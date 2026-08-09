// Maximum Number of Robots Within Budget
// https://leetcode.com/problems/maximum-number-of-robots-within-budget/
// Difficulty: Hard
// Language: cpp
// Runtime: 10
// Memory: 112856000

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {

        deque<int> dq;      // stores indices, decreasing chargeTimes

        long long runSum = 0;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < chargeTimes.size(); right++) {

            runSum += runningCosts[right];

            while (!dq.empty() &&
                   chargeTimes[dq.back()] <= chargeTimes[right])
                dq.pop_back();

            dq.push_back(right);

            while (!dq.empty() &&
                   (long long)chargeTimes[dq.front()] +
                   (right - left + 1LL) * runSum > budget) {

                if (dq.front() == left)
                    dq.pop_front();

                runSum -= runningCosts[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
