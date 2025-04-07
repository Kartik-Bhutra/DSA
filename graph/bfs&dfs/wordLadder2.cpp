// https://leetcode.com/problems/word-ladder-ii/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_map<string, int> depthMap;
    vector<vector<string>> ans;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    depthMap[beginWord] = 1;
    wordSet.erase(beginWord);
    while (!q.empty())
    {
      string word = q.front();
      q.pop();
      int steps = depthMap[word];
      if (word == endWord)
        break;
      for (int i = 0; i < word.size(); ++i)
      {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
          word[i] = ch;
          if (wordSet.count(word))
          {
            q.push(word);
            wordSet.erase(word);
            depthMap[word] = steps + 1;
          }
        }
        word[i] = original;
      }
    }
    if (depthMap.count(endWord))
    {
      vector<string> seq = {endWord};
      dfs(endWord, beginWord, seq, depthMap, ans);
    }
    return ans;
  }

private:
  void dfs(string word, string beginWord, vector<string> &seq, unordered_map<string, int> &depthMap, vector<vector<string>> &ans)
  {
    if (word == beginWord)
    {
      reverse(seq.begin(), seq.end());
      ans.push_back(seq);
      reverse(seq.begin(), seq.end());
      return;
    }
    int steps = depthMap[word];
    for (int i = 0; i < word.size(); ++i)
    {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ++ch)
      {
        word[i] = ch;
        if (depthMap.count(word) && depthMap[word] + 1 == steps)
        {
          seq.push_back(word);
          dfs(word, beginWord, seq, depthMap, ans);
          seq.pop_back();
        }
      }
      word[i] = original;
    }
  }
};
class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord))
      return {};

    unordered_map<string, vector<string>> parentMap;

    unordered_set<string> currentLevel, nextLevel;
    currentLevel.insert(beginWord);
    bool found = false;
    wordSet.erase(beginWord);
    while (!currentLevel.empty() && !found)
    {
      for (const string &word : currentLevel)
      {
        wordSet.erase(word);
      }
      nextLevel.clear();
      for (const string &word : currentLevel)
      {
        string temp = word;
        for (int i = 0; i < temp.size(); ++i)
        {
          char original = temp[i];
          for (char c = 'a'; c <= 'z'; ++c)
          {
            temp[i] = c;
            if (wordSet.count(temp))
            {
              nextLevel.insert(temp);
              parentMap[temp].push_back(word);
              if (temp == endWord)
                found = true;
            }
          }
          temp[i] = original;
        }
      }
      currentLevel = move(nextLevel);
    }
    if (!found)
      return {};

    vector<vector<string>> result;
    vector<string> path = {endWord};
    dfs(endWord, beginWord, parentMap, path, result);
    return result;
  }

private:
  void dfs(const string &word, const string &beginWord,
           unordered_map<string, vector<string>> &parentMap,
           vector<string> &path, vector<vector<string>> &result)
  {
    if (word == beginWord)
    {
      result.push_back(vector<string>(path.rbegin(), path.rend()));
      return;
    }
    for (const string &parent : parentMap[word])
    {
      path.push_back(parent);
      dfs(parent, beginWord, parentMap, path, result);
      path.pop_back();
    }
  }
};
int main()
{
  return 0;
}