// https://leetcode.com/problems/4sum/description/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sum4(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // to use 2 pointers
    for (int i = 0; i < n; i++)
    {
        // if same then their is not point in using that
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                long long sum = static_cast<long long>(arr[i]) + arr[j] + arr[low] + arr[high];
                if (sum > target)
                {
                    high--;
                    while (low < high && arr[high] == arr[high + 1])
                        high--;
                }
                else if (sum < target)
                {
                    low++;
                    while (low < high && arr[low] == arr[low - 1])
                        low++;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                    low++;
                    high--;
                    while (low < high && arr[low] == arr[low - 1])
                        low++;
                    while (low < high && arr[high] == arr[high + 1])
                        high--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr;
    vector<vector<int>> fourSum = sum4(arr, 10);
    // time complexity is O(N*N*N) && space complexity is O(1)
    [&fourSum]()
    {
        for (vector<int> vec : fourSum)
        {
            for (int x : vec)
                cout << x << " ";
            cout << "\n";
        }
    }();
    return 0;
}