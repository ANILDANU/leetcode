require("dotenv").config();

function required(name) {
  const value = process.env[name];
  if (!value) throw new Error(`Missing environment variable: ${name}`);
  return value;
}

module.exports = {
  leetcodeSession: required("LEETCODE_SESSION"),
  leetcodeUsername: process.env.LEETCODE_USERNAME || null,
  submissionLimit: Number(process.env.LEETCODE_SUBMISSION_LIMIT || 20)
};
