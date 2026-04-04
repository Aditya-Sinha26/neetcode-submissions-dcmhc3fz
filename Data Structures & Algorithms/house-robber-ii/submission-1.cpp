class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        int dp[n+1]={0};
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        vector<int> first(nums.begin(), nums.end()-1);
        vector<int> last(nums.begin()+1,nums.end());
        int withFirst = solve(first);
        int withLast = solve(last);
        return max(withFirst, withLast);
    }
};
