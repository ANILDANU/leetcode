// Nearest Exit from Entrance in Maze
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Difficulty: Medium
// Language: cpp
// Runtime: 4
// Memory: 35016000

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r,c] = q.front();
                q.pop();

                if((r != entrance[0] || c!= entrance[1]) && (r == 0 || c == 0 || r == n-1 || c == m-1))
                return step;

                for(auto d: dir){
                    int x = r + d.first, y = c + d.second;
                    if(x < 0 || y < 0 || x>=n || y>=m || maze[x][y] == '+')
                    continue;   

                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            step++;
        }
        return -1;
    }
};
