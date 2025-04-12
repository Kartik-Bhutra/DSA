#ifndef DSU_HPP
#define DSU_HPP
#include <vector>
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
#endif
