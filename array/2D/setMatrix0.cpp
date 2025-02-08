// https://leetcode.com/problems/set-matrix-zeroes/
#include <bits/stdc++.h>
using namespace std;
void setMatrix0(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    // is first row has a zero
    bool row1 = 0;
    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 0)
        {
            row1 = 1;
            break;
        }
    }
    // if first colomn has zero then only 0,0 will have zero
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][0] == 0 || mat[0][j] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }
    if (mat[0][0] == 0)
    {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
    if (row1)
    {
        for (int i = 0; i < m; i++)
            mat[0][i] = 0;
    }
}
int main()
{
    vector<vector<int>> mat;
    setMatrix0(mat);
    // time complexity is O(N*M) and space complexity is O(1)
    [&]()
    {
        for (vector<int> vec : mat)
        {
            for (int x : vec)
                cout << x << " ";
            cout << "\n";
        }
    }();
    return 0;
}