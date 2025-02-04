#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMissingAndRepeating(vector<int> &nums)
{
  int n = nums.size();
  long long power1Sum = 0, power2Sum = 0;
  for (int i = 0; i < n; i++)
  {
    power1Sum += nums[i];
    power2Sum += (long long)nums[i] * nums[i];
  }
  long long power1 = (n * (n + 1LL)) / 2;
  long long power2 = (n * (n + 1LL) * (2 * n + 1LL)) / 6;
  // equation1 repeated - missing = power1Sum - power1
  long long minus = power1Sum - power1;
  // equation2 repeated**2 - missing**2 = power2Sum - power2
  long long plus = (power2Sum - power2) / minus;
  return {(plus + minus) / 2, (plus - minus) / 2};
}

int main()
{
  vector<int> nums = {1, 2, 2, 4};
  pair<int, int> result = findMissingAndRepeating(nums);
  cout << result.first << " " << result.second << endl;
  return 0;
}