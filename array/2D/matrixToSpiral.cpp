// https://leetcode.com/problems/spiral-matrix/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> printSpiral(vector<vector<int>> &mat)
{
    vector<int> ans;
    int n = mat.size(), m = mat[0].size();
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;
        // to check if maxBottom * maxRight < total elements
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat;
    vector<int> spiral = printSpiral(mat);
    // time complexity is O(N*M) and space complexity is O(1) exclude ans
    [&spiral]()
    {
        for (int x : spiral)
            cout << x << " ";
        cout << "\n";
    }();
    return 0;
}