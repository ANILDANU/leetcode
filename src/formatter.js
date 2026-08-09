const fs = require("fs");
const path = require("path");
const slugify = require("slugify");

function getExtension(language) {
  const key = String(language || "").toLowerCase();

  const map = {
    cpp: "cpp",
    "c++": "cpp",
    c: "c",
    java: "java",
    python: "py",
    python3: "py",
    javascript: "js",
    typescript: "ts",
    go: "go",
    rust: "rs",
    kotlin: "kt",
    swift: "swift",
    csharp: "cs",
    "c#": "cs",
    php: "php",
    ruby: "rb",
    scala: "scala"
  };

  return map[key] || "txt";
}

function getCommentSyntax(language) {
  const key = String(language || "").toLowerCase();
  return key.includes("python") ? "#" : "//";
}

function getFilename(title, language) {
  const slug = slugify(title, { lower: true, strict: true });
  return `${slug}.${getExtension(language)}`;
}

function formatSolution({
  title,
  titleSlug,
  code,
  language,
  difficulty,
  runtime,
  memory
}) {
  const comment = getCommentSyntax(language);
  const url = `https://leetcode.com/problems/${titleSlug}/`;

  return `${comment} ${title}
${comment} ${url}
${comment} Difficulty: ${difficulty || "Unknown"}
${comment} Language: ${language}
${comment} Runtime: ${runtime || "N/A"}
${comment} Memory: ${memory || "N/A"}

${code}
`;
}

function ensureDir(dir) {
  fs.mkdirSync(dir, { recursive: true });
}

function writeSolution({
  title,
  titleSlug,
  code,
  language,
  difficulty,
  runtime,
  memory
}) {
  const directory = String(difficulty || "Unknown").toLowerCase();
  const filename = getFilename(title, language);
  const relativePath = path.join(directory, filename);
  const absolutePath = path.join(process.cwd(), relativePath);

  ensureDir(path.dirname(absolutePath));

  const content = formatSolution({
    title,
    titleSlug,
    code,
    language,
    difficulty,
    runtime,
    memory
  });

  fs.writeFileSync(absolutePath, content, "utf8");

  return relativePath;
}

module.exports = {
  writeSolution
};
