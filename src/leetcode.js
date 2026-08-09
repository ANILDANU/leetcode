const axios = require("axios");
const { leetcodeSession } = require("./config");

const client = axios.create({
  baseURL: "https://leetcode.com",
  timeout: 20000,
  headers: {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0"
  }
});

client.defaults.headers.Cookie = `LEETCODE_SESSION=${leetcodeSession}`;

async function graphql(query, variables = {}) {
  const response = await client.post("/graphql", { query, variables });

  if (response.data.errors?.length) {
    throw new Error(JSON.stringify(response.data.errors));
  }

  return response.data.data;
}

async function getCurrentUser() {
  const query = `
    query {
      userStatus {
        username
      }
    }
  `;

  const data = await graphql(query);
  return data.userStatus.username;
}

async function getRecentSubmissions(username, limit) {
  const query = `
    query recentSubmissionList($username: String!, $limit: Int) {
      recentSubmissionList(username: $username, limit: $limit) {
        title
        titleSlug
        timestamp
        statusDisplay
        lang
        id
      }
    }
  `;

  const data = await graphql(query, { username, limit });
  return data.recentSubmissionList || [];
}

async function getSubmission(submissionId) {
  const query = `
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        runtime
        memory
        statusCode
        lang {
          name
          verboseName
        }
      }
    }
  `;

  const data = await graphql(query, {
    submissionId: Number(submissionId)
  });

  return data.submissionDetails;
}

async function getProblem(titleSlug) {
  const query = `
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionId
        title
        titleSlug
        difficulty
        topicTags {
          name
        }
      }
    }
  `;

  const data = await graphql(query, { titleSlug });
  return data.question;
}

module.exports = {
  getCurrentUser,
  getRecentSubmissions,
  getSubmission,
  getProblem
};
