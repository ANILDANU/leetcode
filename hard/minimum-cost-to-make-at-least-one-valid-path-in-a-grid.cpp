// Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Difficulty: Hard
// Language: cpp
// Runtime: 27
// Memory: 19432000

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

        pq.push({0,0,0});

        vector<pair<int,int>> dr = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()){
            auto [w,i,j] = pq.top();
            pq.pop();

            if(i == n-1 && j == m-1)
            return w;
            if(w > dp[i][j])
            continue;

            dp[i][j] = w;

            for(int k = 0;k<4;k++){
                int x = i + dr[k].first , y = j +dr[k].second;

                if(x<0 || y<0 || x>=n || y>=m)
                continue;

                if(k == grid[i][j] - 1){
                    if(dp[x][y] > w)
                    {
                        dp[x][y] = w;
                        pq.push({w,x,y});
                    }
                }
                else
                {
                    if(dp[x][y] > w+1){
                    dp[x][y] = w+1;
                    pq.push({w+1,x,y});
                    }
                }
            }
        }
        return -1;
    }
};
