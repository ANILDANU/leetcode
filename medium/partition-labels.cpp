// Partition Labels
// https://leetcode.com/problems/partition-labels/
// Difficulty: Medium
// Language: cpp
// Runtime: 1
// Memory: 9276000

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> start(26,INT_MAX),end(26,0);
        int n = s.size();

        for(int i = 0;i<n;i++){
            int index = s[i] - 'a';
            if(start[index] == INT_MAX)
            start[index] = i;

            end[index] = max(end[index],i);
        }

        map<int,int> mp;

        for(int i = 0;i<26;i++){
            //cout<<start[i]<<" "<<end[i]<<endl;
            if(start[i] != INT_MAX){
                mp[start[i]] = end[i];
                // mp[end[i]] = -1;
            }
        }

        int e = -1,count = 0;
        vector<int> v,ans;
        for(auto [i,j] : mp){
            //cout<<i<<" "<<j<<endl;
            if( e < i){
                count++;
                v.push_back(i);
                e = max(e,j);
            }
            else
            {
                e = max(e,j);
            }
        }
        for(int i =1;i<v.size();i++){
            ans.push_back(v[i] - v[i-1]);
        }
        ans.push_back(e - v[v.size()-1] + 1);
        return ans;

    }
};
