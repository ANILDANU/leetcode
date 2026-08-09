// My Calendar I
// https://leetcode.com/problems/my-calendar-i/
// Difficulty: Medium
// Language: cpp
// Runtime: 33
// Memory: 42948000

class MyCalendar {
public:
  vector<pair<int,int>> global;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
   
      for(auto &i:global)
      {

        if(start >= i.first && start < i.second || end > i.first && end <= i.second || start <= i.first && end >= i.second)
        return false;
        
      }
      global.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
