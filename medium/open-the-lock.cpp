// Open the Lock
// https://leetcode.com/problems/open-the-lock/
// Difficulty: Medium
// Language: cpp
// Runtime: 147
// Memory: 39168000

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //cout<<'0'+5<<endl;
        string start = "0000";

        unordered_set<string> dead,seen;
        dead.insert(deadends.begin(),deadends.end());

        if(dead.count(start) || dead.count(target))
        return -1;

        queue<string> q;
        q.push(start);
        seen.insert("0000");
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            //cout<<step<<endl;
            while(sz--){

            auto s = q.front();
            q.pop();

            // if(seen.count(s))
            // continue;

            if(s == target)
            return step;

            //seen.insert(s);
            //cout<<s<<endl;
            for(int i = 0;i<4;i++){
                string str  = s;
                char c = str[i],b = str[i];
                if(c == '0')
                    c = '9';
                else
                    c--;
                if(b == '9')
                    b = '0';
                else
                    b++;
                
                str[i] = c;
                if(!dead.count(str) && !seen.count(str)){
                    q.push(str);
                    seen.insert(str);
                }
                str[i] = b;

                if(!dead.count(str) && !seen.count(str)){
                    seen.insert(str);
                    q.push(str);
                }
            }
            }
            step++;
        }
        return -1;
    }
};
