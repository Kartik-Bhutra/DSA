#include <bits/stdc++.h>
using namespace std;
class ds
{
  vector<int> parent, rank, size;

public:
  ds(int n)
  {
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);
    parent.resize(n + 1, -1);
  }
  int findParent(int node)
  {
    if (parent[node] == -1)
      return node;
    return parent[node] = findParent(parent[node]);
  }
  void unionByRank(int u, int v)
  {
    int up = findParent(u), vp = findParent(v);
    if (up == vp)
      return;
    if (rank[up] > rank[vp])
    {
      parent[vp] = up;
      size[up] += size[vp];
    }
    else if (rank[up] < rank[vp])
    {
      parent[up] = vp;
      size[vp] += size[up];
    }
    else
    {
      rank[up]++;
      parent[vp] = up;
      size[up] += size[vp];
    }
  }
  int getSize(int node)
  {
    return size[findParent(node)];
  }
};
int main()
{
  ds d(10);
  d.unionByRank(1, 2);
  d.unionByRank(2, 3);
  d.unionByRank(4, 5);
  d.unionByRank(6, 7);
  d.unionByRank(5, 6);
  d.unionByRank(3, 7);
  d.unionByRank(8, 9);
  d.unionByRank(9, 10);
  d.unionByRank(7, 10);
  for (int i = 1; i <= 10; i++)
  {
    cout << "Node: " << i
         << ", Root: " << d.findParent(i)
         << ", Size of component: " << d.getSize(i) << '\n';
  }
  return 0;
}
