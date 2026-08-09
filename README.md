# LeetCode → GitHub Sync with GitHub Actions

Automatically sync newly accepted LeetCode submissions to this GitHub repository.

You configure it once. After that, **you do not need to run Node.js locally**.

## Flow

```text
Solve problem on LeetCode
        ↓
Submit
        ↓
Accepted
        ↓
GitHub Actions runs on schedule
        ↓
Fetch recent submissions
        ↓
Fetch accepted source code
        ↓
Create solution file
        ↓
Commit + push to this repository
```

## One-time setup

### 1. Create the repository

This project can be used directly as your LeetCode solutions repository.

### 2. Add repository secret

Go to:

`Repository → Settings → Secrets and variables → Actions → New repository secret`

Create:

```text
Name: LEETCODE_SESSION
Value: <your LeetCode LEETCODE_SESSION cookie>
```

Do not commit the cookie to the repository.

### 3. Enable Actions write permission

Go to:

`Repository → Settings → Actions → General`

Under **Workflow permissions**, select:

**Read and write permissions**

You can also explicitly enable this through the workflow's:

```yaml
permissions:
  contents: write
```

### 4. Enable the workflow

The workflow is:

`.github/workflows/leetcode-sync.yml`

It runs every 5 minutes and can also be started manually from the Actions tab.

## Usage

After setup:

```text
LeetCode → Accepted → wait for scheduled run → GitHub
```

You don't need to run:

```bash
npm start
```

or

```bash
npm run sync
```

locally.

## Repository layout

Solutions are created like:

```text
easy/
  two-sum.cpp

medium/
  product-of-array-except-self.cpp
  word-search.cpp

hard/
  merge-k-sorted-lists.cpp
```

The persistent state is:

```text
data/state.json
```

It records processed LeetCode submission IDs so the same submission is not imported repeatedly.

## Manual sync

Open:

`GitHub → Actions → LeetCode → GitHub Sync → Run workflow`

This starts the workflow immediately.

## Important security note

Your `LEETCODE_SESSION` cookie is an authentication credential. Treat it like a password:

- Never put it in source code.
- Never commit `.env`.
- Never print it in logs.
- Use a GitHub Actions repository secret.
- Rotate it if you accidentally expose it.

## LeetCode API note

This project uses LeetCode's GraphQL endpoints. These are not a stable public API and can change without notice. If LeetCode changes the endpoint/schema, the workflow may need an update.
