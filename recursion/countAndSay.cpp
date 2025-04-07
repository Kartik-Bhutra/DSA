// https://leetcode.com/problems/count-and-say/description/
#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
  if(n==1)
      return "1";
  if(n==2)
      return "11";
  string str = "11";
  for(int i=3; i<=n ; i++)
  {
      string temp = "";
      str = str+"&"; 
      int cnt = 1; 
      for(int j = 1; j<str.length(); j++)
      {
          if(str[j]!=str[j-1])
          {
              temp = temp + to_string(cnt); 
              temp = temp + str[j-1]; 
              cnt = 1; 
          }
          else
              cnt++; 
      }
      str = temp;
  }
return str;
}
int main(){
  return 0;
}