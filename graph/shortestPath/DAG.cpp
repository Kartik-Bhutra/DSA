#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
  vector<pair<int, int>> adj[N];
  for (int i = 0; i < M; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v, wt});
  }
  vector<bool> vis(N, false);
  stack<int> st;
  function<void(int)> topoSort = [&](int node) {
    vis[node] = true;
    for (auto &x : adj[node]) {
      if (!vis[x.first]) {
        topoSort(x.first);
      }
    }
    st.push(node);
  };
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      topoSort(i);
    }
  }
  vector<int> dist(N, 1e9);
  dist[0] = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (dist[node] != 1e9) {
      for (auto &it : adj[node]) {
        int v = it.first;
        int wt = it.second;
        if (dist[node] + wt < dist[v]) {
          dist[v] = dist[node] + wt;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (dist[i] == 1e9) dist[i] = -1;
  }
  return dist;
}
int main() {
  int N = 6, M = 7;
  vector<vector<int>> edges = {
      {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2},
      {4, 5, 4}, {2, 3, 6}, {5, 3, 1}};
  vector<int> result = shortestPath(N, M, edges);
  cout << "Shortest distances from node 0:" << endl;
  for (int x : result) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}