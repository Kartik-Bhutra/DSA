// https://leetcode.com/problems/word-ladder/description/
#include <bits/stdc++.h>
using namespace std;
int ladderLength(string b, string e, vector<string> &a)
{
  int n = a.size(), l = b.size();
  int idx = find(a.begin(), a.end(), e) - a.begin();
  if (idx == n)
    return 0;
  if (e == b)
    return 0;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++)
  {
    string s = a[i];
    int ct = 0;
    for (int j = 0; j < l; j++)
    {
      if (s[j] != b[j])
        ct++;
      if (ct > 1)
        break;
    }
    if (ct == 1)
      adj[0].push_back(i + 1);
  }
  for (int i = 0; i < n; i++)
  {
    string s = a[i];
    for (int j = i + 1; j < n; j++)
    {
      string t = a[j];
      int ct = 0;
      for (int k = 0; k < l; k++)
      {
        if (s[k] != t[k])
          ct++;
        if (ct > 1)
          break;
      }
      if (ct == 1)
      {
        adj[i + 1].push_back(j + 1);
        adj[j + 1].push_back(i + 1);
      }
    }
  }
  queue<pair<int, int>> q;
  vector<bool> v(n + 1, 0);
  v[0] = 1;
  q.push({0, 1});
  while (!q.empty())
  {
    auto [i, r] = q.front();
    q.pop();
    if (i == idx + 1)
      return r;
    for (int j : adj[i])
    {
      if (!v[j])
      {
        q.push({j, r + 1});
        v[j] = 1;
      }
    }
  }
  return 0;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
  queue<pair<string, int>> q;
  q.push({beginWord, 1});
  unordered_set<string> st(wordList.begin(), wordList.end());
  st.erase(beginWord);
  while (!q.empty())
  {
    string word = q.front().first;
    int steps = q.front().second;
    q.pop();
    if (word == endWord)
    {
      return steps;
    }
    for (int i = 0; i < word.size(); i++)
    {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch;
        if (st.find(word) != st.end())
        {
          st.erase(word);
          q.push({word, steps + 1});
        }
      }
      word[i] = original;
    }
  }
  return 0;
}
int main()
{
  return 0;
}