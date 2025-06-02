// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fx(vector<pair<pair<int,int>,int>>& setime, int i, vector<int>& dp) {
        if (i == setime.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int lo = i + 1, hi = setime.size(), nextIndex = setime.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (setime[mid].first.first >= setime[i].first.second) {
                nextIndex = mid;
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }    
        int include = setime[i].second + fx(setime, nextIndex, dp);
        int exclude = fx(setime, i + 1, dp);  
        return dp[i] = max(include, exclude);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int,int>,int>> setime; 
        for (int i = 0; i < n; ++i) {
            setime.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(setime.begin(), setime.end());
        vector<int> dp(n, -1);
        return fx(setime, 0, dp);
    }
};

int main(){
  
  return 0;
}