const {
  getCurrentUser,
  getRecentSubmissions,
  getSubmission,
  getProblem
} = require("./leetcode");

const { submissionLimit, leetcodeUsername } = require("./config");
const { loadState, saveState } = require("./state");
const { writeSolution } = require("./formatter");

async function main() {
  console.log("=== LeetCode → GitHub Actions Sync ===");

  const username = leetcodeUsername || await getCurrentUser();
  console.log(`LeetCode user: ${username}`);

  const state = loadState();

  const submissions = await getRecentSubmissions(
    username,
    submissionLimit
  );

  const accepted = submissions
    .filter(s => s.statusDisplay === "Accepted")
    .reverse();

  console.log(`Accepted submissions found: ${accepted.length}`);

  let imported = 0;

  for (const submission of accepted) {
    const id = String(submission.id);

    if (state.processedSubmissions[id]) {
      continue;
    }

    try {
      console.log(`Processing ${submission.title} (${id})`);

      const details = await getSubmission(id);

      if (!details?.code) {
        console.log("  No source code returned; skipping.");
        continue;
      }

      const problem = await getProblem(submission.titleSlug);
      const difficulty = problem?.difficulty || "Unknown";

      const relativePath = writeSolution({
        title: submission.title,
        titleSlug: submission.titleSlug,
        code: details.code,
        language: submission.lang,
        difficulty,
        runtime: details.runtime,
        memory: details.memory
      });

      state.processedSubmissions[id] = {
        title: submission.title,
        titleSlug: submission.titleSlug,
        language: submission.lang,
        difficulty,
        path: relativePath,
        timestamp: submission.timestamp,
        syncedAt: new Date().toISOString()
      };

      imported++;
      console.log(`  ✓ ${relativePath}`);
    } catch (error) {
      console.error(
        `  ✗ Failed ${submission.title}: ${error.message}`
      );
    }
  }

  saveState(state);

  console.log(`Imported ${imported} new accepted submission(s).`);
}

main().catch(error => {
  console.error("Sync failed:", error.message);
  process.exit(1);
});
