// Grid Teleportation Traversal
// https://leetcode.com/problems/grid-teleportation-traversal/
// Difficulty: Medium
// Language: cpp
// Runtime: 292
// Memory: 143464000

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        
        vector<pair<int,int>> mat[26];
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> visited(n,vector<int> (m,INT_MAX));

        vector<int> fre(26,0);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == '.' || matrix[i][j] == '#')
                continue;

                mat[matrix[i][j] - 'A'].push_back({i,j});
            }
        }

        deque<pair<int,int>> q;
        q.push_back({0,0});
        visited[0][0] = 0;

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop_front();
                //cout<<i<<" "<<j<<" "<<step<<endl;

                if(i == n-1 && j == m-1)
                return step;
                if(matrix[i][j] >= 'A' && matrix[i][j] <='Z' && fre[matrix[i][j]-'A'] == 0){
                    fre[matrix[i][j]-'A'] = 1;

                    for(auto d : mat[matrix[i][j]-'A']){
                        if(d.first == i && d.second == j)
                        continue;

                        if(visited[d.first][d.second] <= step)
                        continue;

                        visited[d.first][d.second] = step;
                        q.push_front({d.first,d.second});
                        sz++;
                    }
                }

                for(auto d : dir){
                    int x = i + d.first, y = j + d.second;
                    if(x< 0 || y< 0 || x>=n || y>=m || matrix[x][y] == '#' || visited[x][y] <= step +1)
                    continue;

                    visited[x][y] = step + 1;

                    q.push_back({x,y});
                }
                
            }
            step++;
        }
        return -1;
    }
};
