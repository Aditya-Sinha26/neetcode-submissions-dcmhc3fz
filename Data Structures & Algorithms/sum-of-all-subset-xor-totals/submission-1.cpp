class Solution {
public:
    int ans = 0;
    void solve(int idx, vector<int>& nums, int xr){
        if(idx == nums.size()){
            ans += xr;
            return;
        }
        solve(idx + 1, nums, xr ^ nums[idx]);
        solve(idx + 1, nums, xr);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return ans;
    }
};