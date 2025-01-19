#include <bits/stdc++.h>
using namespace std;
void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    // -> int returns a integer value
    int pivotIdx = [&]() -> int
    {
        int low = start + 1, high = end;
        // Pivot element is the first element
        int pivotEle = arr[start];
        // all the smaller on the left side of pivotIdx and larger on the right side of pivotIdx
        while (low <= high)
        {
            while (low <= high && arr[low] <= pivotEle)
                low++;
            while (low <= high && arr[high] > pivotEle)
                high--;
            if (low < high)
                swap(arr[low], arr[high]);
        }
        return high;
    }();
    swap(arr[start], arr[pivotIdx]);
    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}
int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    quickSort(arr, 0, arr.size() - 1);
    // time complexity O(NLog(N)) and space complexity O(1)
    // if array is in decreasing order them time complexity is O(N*N)
    [&]()
    {
        for (int i : arr)
            cout << i << " ";
        cout << "\n";
    }();
    return 0;
}
