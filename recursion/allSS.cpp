// https://leetcode.com/problems/subsets/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), m = 1<<n;
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            vector<int> ss;
            int k = i, j = 0;
            while(k){
                if(k&1){
                    ss.push_back(nums[j]);
                }
                k/=2;
                j++;
            }
            ans.push_back(ss);
        }
        return ans;
    }
};
int main(){
  
  return 0;
}