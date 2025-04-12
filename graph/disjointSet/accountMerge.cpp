// https://leetcode.com/problems/accounts-merge/description/
#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;
vector<vector<string>> accountsMerge(vector<vector<string>> &details)
{
  int n = details.size();
  ds d(n);
  sort(details.begin(), details.end());
  unordered_map<string, int> mapMailNode;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < details[i].size(); j++)
    {
      string mail = details[i][j];
      if (mapMailNode.find(mail) == mapMailNode.end())
      {
        mapMailNode[mail] = i;
      }
      else
      {
        d.unionByRank(i, mapMailNode[mail]);
      }
    }
  }
  vector<string> mergedMail[n];
  for (auto it : mapMailNode)
  {
    string mail = it.first;
    int node = d.findParent(it.second);
    mergedMail[node].push_back(mail);
  }
  vector<vector<string>> ans;
  for (int i = 0; i < n; i++)
  {
    if (mergedMail[i].size() == 0)
      continue;
    sort(mergedMail[i].begin(), mergedMail[i].end());
    vector<string> temp;
    temp.push_back(details[i][0]);
    for (auto it : mergedMail[i])
    {
      temp.push_back(it);
    }
    ans.push_back(temp);
  }
  sort(ans.begin(), ans.end());
  return ans;
}
class Solution
{
public:
  unordered_set<string> visited;
  unordered_map<string, vector<string>> adjacent;
  void DFS(vector<string> &mergedAccount, string &email)
  {
    visited.insert(email);
    mergedAccount.push_back(email);
    for (string &neighbor : adjacent[email])
    {
      if (visited.find(neighbor) == visited.end())
      {
        DFS(mergedAccount, neighbor);
      }
    }
  }
  vector<vector<string>> accountsMerge(vector<vector<string>> &accountList)
  {
    int accountListSize = accountList.size();
    for (vector<string> &account : accountList)
    {
      int accountSize = account.size();
      string accountFirstEmail = account[1];
      for (int j = 2; j < accountSize; j++)
      {
        string email = account[j];
        adjacent[accountFirstEmail].push_back(email);
        adjacent[email].push_back(accountFirstEmail);
      }
    }
    vector<vector<string>> mergedAccounts;
    for (vector<string> &account : accountList)
    {
      string accountName = account[0];
      string accountFirstEmail = account[1];
      if (visited.find(accountFirstEmail) == visited.end())
      {
        vector<string> mergedAccount;
        mergedAccount.push_back(accountName);
        DFS(mergedAccount, accountFirstEmail);
        sort(mergedAccount.begin() + 1, mergedAccount.end());
        mergedAccounts.push_back(mergedAccount);
      }
    }
    return mergedAccounts;
  }
};
int main()
{
  return 0;
}