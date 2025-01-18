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
    for (int x : arr)
        cout << x << " ";
    return 0;
}
