#include <bits/stdc++.h>
using namespace std;
int longestConsecutiveSequence(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> st(arr.begin(), arr.end());
    int ans = 1;
    for (int x : st)
    {
        // if it is not the last then don't do anything
        if (st.find(x + 1) == st.end())
        {
            int temp = x - 1, count = 1;
            while (st.find(temp) != st.end())
            {
                count++;
                temp--;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 4, 3, 100, 2, 101, 9, 10, 11, 201, 102, 5};
    cout << longestConsecutiveSequence(arr) << "\n";
    // time complexity is O(N) as at max it can traverse the array twice 
    // space complexity is O(N) 
    return 0;
}