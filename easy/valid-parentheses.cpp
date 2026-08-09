// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Language: cpp
// Runtime: 3
// Memory: 8892000

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(auto &i:str){
            if(i == ')' || i == ']' || i =='}'){
                if(s.empty())
                return false;

                if(i == ')' && s.top() == '(' || i == ']' && s.top() == '[' || i == '}' && s.top() == '{')
                s.pop();
                else
                return false;


            }
            else
            s.push(i);
        }

        return s.empty();
    }
};
