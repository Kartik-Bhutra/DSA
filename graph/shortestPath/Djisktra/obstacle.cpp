// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
#include <bits/stdc++.h>
using namespace std;
using state = tuple<int, int, int, int>;

class Compare {
public:
    bool operator()(const state &a, const state &b) {
        return get<0>(a) > get<0>(b); 
    }
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 1e9)));
        priority_queue<state, vector<state>, Compare> pq;

        pq.push({0, k, 0, 0});
        vis[0][0][k] = 0;

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()) {
            auto [d, rem, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return d;

            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int new_rem = rem - grid[nx][ny];
                    if (new_rem >= 0 && d + 1 < vis[nx][ny][new_rem]) {
                        vis[nx][ny][new_rem] = d + 1;
                        pq.push({d + 1, new_rem, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
int main()
{

  return 0;
}