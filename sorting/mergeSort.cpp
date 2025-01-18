#include <bits/stdc++.h>
using namespace std;
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    // lamda function & for taking all the argument as it is with reference
    [&]()
    {
        vector<int> vec;
        int low = start, high = mid + 1;
        while (low <= mid && high <= end)
        {
            if (arr[low] < arr[high])
                vec.push_back(arr[low++]);
            else
                vec.push_back(arr[high++]);
        }
        while (low <= mid)
            vec.push_back(arr[low++]);
        while (high <= end)
            vec.push_back(arr[high++]);
        for (int i = start; i <= end; i++)
            arr[i] = vec[i - start];
    }();
    // calling it directly without naming it
}
int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
