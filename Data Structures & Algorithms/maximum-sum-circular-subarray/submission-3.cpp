class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totSum =0 , mx=0, mxSum=INT_MIN, mnSum = INT_MAX, mn=0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
            mx = max(nums[i], mx+nums[i]);
            mn = min(nums[i], mn+nums[i]);
            mxSum = max(mxSum, mx);
            mnSum = min(mn, mnSum);
        }

        return totSum==mnSum ? mxSum : max(totSum-mnSum,mxSum);
    }
};