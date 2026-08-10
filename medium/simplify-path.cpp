// Simplify Path
// https://leetcode.com/problems/simplify-path/
// Difficulty: Medium
// Language: cpp
// Runtime: 11
// Memory: 23636000

class Solution {
public:
    string simplifyPath(string &path) {
        
        stringstream ss(path);
        string s;

        vector<string> v;
        while(getline(ss,s,'/')){
        if(s.empty() || s == ".")
        continue;

        if(s == ".."){
            if(!v.empty())
            v.pop_back();
            continue;
        }

        v.push_back(s);
        }

        string p = "";
        for(auto &s:v){
            p = p + "/" +s;     
        }

        if(p.empty())
        return "/";

        return p;

    }
};
