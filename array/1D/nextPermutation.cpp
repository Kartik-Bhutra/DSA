#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    // index where decreasing sequence break
    int pivotIdx = [&]() -> int
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
                return i - 1;
        }
        return -1;
    }();
    if (pivotIdx >= 0)
    {
        // find just greater than the pivot and as the sequence is decreasing so stop at once
        for (int i = n - 1; i > pivotIdx; i--)
        {
            if (arr[pivotIdx] < arr[i])
            {
                swap(arr[pivotIdx], arr[i]);
                break;
            }
        }
        reverse(arr.begin() + pivotIdx + 1, arr.end());
    }
    else
    {
        // if this permutation is largest then starting point is next
        reverse(arr.begin(), arr.end());
    }
}
int main()
{
    vector<int> arr = {3, 2, 1};
    nextPermutation(arr);
    // time complexity is O(N) and space complexity is O(1)
    [&]()
    {
        for (int i : arr)
            cout << i << " ";
        cout << "\n";
    }();
    return 0;
}