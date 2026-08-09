// Minimum Moves to Reach Target with Rotations
// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
// Difficulty: Hard
// Language: cpp
// Runtime: 54
// Memory: 25508000

class Solution {
public:
struct PairHash {
    size_t operator()(
        const pair<pair<int,int>, pair<int,int>>& p
    ) const {
        size_t h1 = hash<int>{}(p.first.first);
        size_t h2 = hash<int>{}(p.first.second);
        size_t h3 = hash<int>{}(p.second.first);
        size_t h4 = hash<int>{}(p.second.second);

        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};
    bool isempty(pair<int,int> p, pair<int,int> q, vector<vector<int>>& grid){
        int i = p.first,j = p.second, x = q.first,y = q.second;
        int n = grid.size();

        if(i< 0 || j< 0 || i>=n || j>=n || x<0 || y<0 || x>=n ||y>=n || grid[i][j] != 0 || grid[x][y]!=0)
        return false;

        return true;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{0,0},{0,1}});
        int n  = grid.size();
        // q.push({0,1});

        unordered_set< pair <pair<int,int>,pair<int,int>>,PairHash > seen;
        seen.insert({{0,0},{0,1}});
        int step = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [tail,head] = q.front();
                q.pop();
                // auto tail = q.front();
                //cout<<tail.first<<" "<<tail.second<<" "<<head.first<<" "<<head.second<<endl;
                // q.pop();
                if(head.first == n-1 && head.second == n-1 && tail.first == n-1 && tail.second == n-2)
                return step;

                pair<int,int> rtail = {tail.first,tail.second+1}, rhead = {head.first,head.second+1};

                if (!seen.count(make_pair(rtail, rhead)) && isempty(rtail, rhead, grid)) {
                    q.push({rtail,rhead});
                    seen.insert({rtail,rhead});
                }

                pair<int,int> dtail = {tail.first+1,tail.second}, dhead = {head.first+1,head.second};

                if(!seen.count({dtail,dhead}) && isempty(dtail,dhead,grid)){
                    q.push({dtail,dhead});
                    seen.insert({dtail,dhead});
                }

                pair<int,int> ctail = {tail.first,tail.second}, chead = {head.first+1,head.second-1};
                pair<int,int> utail = {tail.first+1,tail.second}, uhead = {head.first+1,head.second};

                if(!seen.count({ctail,chead}) && isempty(ctail,chead,grid) &&(tail.first == head.first && tail.second + 1 == head.second) && isempty(utail,uhead,grid)){
                    q.push({ctail,chead});
                    seen.insert({ctail,chead});
                }

                pair<int,int> cctail = {tail.first,tail.second}, cchead = {head.first-1,head.second+1};
                pair<int,int> cutail = {tail.first,tail.second+1}, cuhead = {head.first,head.second+1};

                if(!seen.count({cctail,cchead}) && isempty(cctail,cchead,grid) &&(tail.second == head.second && tail.first +1 == head.first) && isempty(cutail,cuhead,grid)){
                    q.push({cctail,cchead});
                    seen.insert({cctail,cchead});
                }

            }
            step++;
        }
        return -1;
    }
};
