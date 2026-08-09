// Dota2 Senate
// https://leetcode.com/problems/dota2-senate/
// Difficulty: Medium
// Language: cpp
// Runtime: N/A
// Memory: 8940000

class Solution {
public:
    string predictPartyVictory(string senate) {
      int band=0,banr=0;
      while(1)
      {
        for(int i=0;i<senate.size();i++)
        {
          if(senate[i]!='X'){
          if(senate[i]=='R')
          {
            if(banr>0)
            {
              banr--;
              senate[i]='X';
            }
            else
            {
              band++;
            }
          }
          else
          {
            if(band>0)
            {
              band--;
              senate[i]='X';
            }
            else
              banr++;
          }
        }
        }
        int countr=0,countd=0;
        for(auto i:senate)
        {
          if(i=='R')
            countr++;
          if(i=='D')
            countd++;
        }
        if(countd==0)
          return "Radiant";
        if(countr==0)
          return "Dire";
      }
      return " ";
      /*stack<char> r;
      stack<char>d;
      char last;
      for(auto i:senate)
      {
        if(i=='R')
        {
          r.push('R');
          last='R';
        }  
        else
        {
          d.push(i);
          last=i;
        }
          
      }
      if(r.empty())
          return "Dire";
        if(d.empty())
          return "Radiant";
      int visitr=0,visitd=0,popd=0,popr=0;
      for(auto i:senate)
      {
        if(i=='R')
        {
          visitr++;
          if(visitr>popr)
          {
            d.pop();
            popd++;
          }
        }
        else
        {
          visitd++;
          if(visitd>popd)
          {
            r.pop();
            popr++;
          }
        }
        if(r.empty())
          return "Dire";
        if(d.empty())
          return "Radiant";
      }
      if(last=='R')
        return "Dire";
      return "Radiant";*/
    }
};
