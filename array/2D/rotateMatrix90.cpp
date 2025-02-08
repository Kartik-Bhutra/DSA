// https://leetcode.com/problems/rotate-image/description/
#include <bits/stdc++.h>
using namespace std;
void rotateMatrix90(vector<vector<int>> &mat)
{
    int n = mat.size();
    // observation
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}
int main()
{
    vector<vector<int>> mat;
    rotateMatrix90(mat);
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