#include <bits/stdc++.h>
using namespace std;
int totalSubarraySumEqualK(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            ans++;
        // find the prefix sum as that + k = sum
        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];
        // all the subarray with sum : sum increase
        mp[sum]++;
    }
    return ans;
}
int longestSubarraySumEqualK(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            ans = max(ans, i + 1);
        if (mp.find(sum - k) != mp.end())
            ans = max(ans, i - mp[sum - k]);
        // to find the maximum neglect zero so if it is assigned then don't change
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 4, -7, 5, -8, 2, -3, 5, 9, -6};
    // time complexity is O(N) or O(Nlog(N)) and space complexity is O(N)
    cout << "totalSubarrays count : " << totalSubarraySumEqualK(arr, 3) << "\n";
    // time complexity is O(N) or O(Nlog(N)) and space complexity is O(N)
    cout << "maximumSubarray length : " << longestSubarraySumEqualK(arr, 3) << "\n";
    return 0;
}