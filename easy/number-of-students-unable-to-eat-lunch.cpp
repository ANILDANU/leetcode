// Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// Difficulty: Easy
// Language: cpp
// Runtime: N/A
// Memory: 11756000

class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sand) {
        int n = s.size();

        int one = 0, zero = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i])
            one++;
            else
            zero++;
        }

        int i = 0,j = 0;

        while(j<n){
            if(sand[j] == 1){
                if(one == 0)
                break;
            }
            else
            {
                if(zero == 0)
                break;
            }
            if(s[i] == sand[j])
            {
                if(s[i] == 0)
                {
                    zero--;
                }
                else
                one--;
                j++;
                i++;
            }
            else
            {
                i++;
            }

            i=i%n;
        }
        return n - j;
    }
};
