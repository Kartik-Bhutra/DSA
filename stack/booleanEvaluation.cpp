// https://leetcode.com/problems/parsing-a-boolean-expression/description/
#include <bits/stdc++.h>
using namespace std;
bool parseBoolExpr(string s)
{
  stack<char> opt;
  stack<char> tf;
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == '!' || s[i] == '&' || s[i] == '|')
    {
      opt.push(s[i]);
    }
    else if (s[i] == '(' || s[i] == 't' || s[i] == 'f')
    {
      tf.push(s[i]);
    }
    else if (s[i] == ')')
    {
      if (opt.top() == '!')
      {
        char temp = tf.top();
        tf.pop();
        tf.pop();
        opt.pop();
        if (temp == 't')
          tf.push('f');
        else
          tf.push('t');
      }
      else if (opt.top() == '&')
      {
        bool temp = true;
        while (tf.top() != '(')
        {
          if (tf.top() == 'f')
            temp = false;
          tf.pop();
        }
        tf.pop();
        opt.pop();
        if (temp)
          tf.push('t');
        else
          tf.push('f');
      }
      else
      {
        bool temp = false;
        while (tf.top() != '(')
        {
          if (tf.top() == 't')
            temp = true;
          tf.pop();
        }
        tf.pop();
        opt.pop();
        if (temp)
          tf.push('t');
        else
          tf.push('f');
      }
    }
  }
  return tf.top() == 't';
}
int main()
{

  return 0;
}