// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int target)
{
  if (target == 0)
    return 0;
  int n = coins.size();
  if (n == 1)
    return target % coins.front() ? -1 : target / coins[0];
  sort(coins.begin(), coins.end());
  int minCoin = coins.front();
  if (target == minCoin)
    return 1;
  int idx = 1, gcdVal = minCoin;
  for (; idx < n && target >= coins[idx]; idx++)
  {
    if (target == coins[idx])
      return 1;
    gcdVal = gcd(coins[idx], gcdVal);
    coins[idx] -= minCoin;
  }
  if (target % gcdVal != 0)
    return -1;
  int minVal = (target - 1) / (coins[idx - 1] + minCoin) + 1,
      maxVal = target / minCoin;
  for (int i = minVal; i <= maxVal; i++)
  {
    if (findCombination(coins, 1, idx - 1, target - i * minCoin, i))
      return i;
  }
  return -1;
}

bool findCombination(const vector<int> &coins, int left, int right, int target, int maxCoins)
{
  if (target == 0)
    return true;
  if (target < coins[left] || target / coins[right] > maxCoins)
    return false;
  if (target % coins[right] == 0)
    return true;
  if (left == right)
    return false;
  for (int k = target / coins[right] + 1; k--;)
  {
    if (findCombination(coins, left, right - 1, target - k * coins[right], maxCoins - k))
      return true;
  }
  return false;
}
int main()
{
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << "Fewest number of coins: " << coinChange(coins, amount) << endl;
  return 0;
}