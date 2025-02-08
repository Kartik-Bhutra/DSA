// https://leetcode.com/problems/majority-element-ii/
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    // at max it can be 2 elements
    int ele1 = 0, ele2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        // if second one is not equal to that before
        if (count1 == 0 && ele2 != arr[i])
        {
            ele1 = arr[i];
            count1++;
        }
        else if (count2 == 0 && ele1 != arr[i])
        {
            ele2 = arr[i];
            count2++;
        }
        else if (ele1 == arr[i])
            count1++;
        else if (ele2 == arr[i])
            count2++;
        // if both are not same as that
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
    }
    // rechecking as they may not be majority
    if (count1 > n / 3)
    {
        ans.push_back(ele1);
    }
    if (count2 > n / 3)
    {
        ans.push_back(ele2);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    vector<int> majority = majorityElement(arr);
    // time complexity is O(N) and space complexity is O(1)
    [&majority]()
    {
        for (int x : majority)
            cout << x << " ";
        cout << "\n";
    }();
    return 0;
}