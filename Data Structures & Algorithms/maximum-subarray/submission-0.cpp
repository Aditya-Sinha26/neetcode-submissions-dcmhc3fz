class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx =-1001 , ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx = max(mx+nums[i], nums[i]);
            ans=max(mx, ans);
        }
        return ans;
    }
};
