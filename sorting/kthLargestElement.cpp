#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int kthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int pivot = left + rand() % (right - left + 1);
            pivot = partition(nums, left, right, pivot);
            
            if (pivot == k - 1) {
                return nums[pivot];
            }
            if (pivot < k - 1) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return nums[k - 1];
    }
    
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);
        
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] >= pivotValue) {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return kthLargest(nums, k);
    }
};