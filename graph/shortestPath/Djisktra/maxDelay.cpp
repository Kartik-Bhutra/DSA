// https://leetcode.com/problems/network-delay-time/description/
#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  vector<vector<pair<int, int>>> g(n + 1);
 for (auto& e : times) g[e[0]].push_back({e[1], e[2]});
  vector<int> dist(n + 1, 1e9);
  dist[k] = 0;
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
     pq.push({0,k});
 while(!pq.empty()){
     int d = pq.top().first;
     int u = pq.top().second;
     pq.pop();
     if(d>dist[u]) continue;
     for(auto it:g[u]){
         int v = it.first;
         int w = it.second;
         if(d + w < dist[v] ){
             dist[v] = d+w;
             pq.push({dist[v],v});
         }
     }     
}
int ans = *max_element(dist.begin()+1,dist.end());
return ans == 1e9 ? -1 : ans;
}
int main(){
  return 0;
}