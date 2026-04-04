class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%2!=0)
        return false;
        int amount = s/2;
        bool dp[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0 && j==0)
                dp[i][j]=true;
                else
                dp[i][j]=false;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(nums[i-1]<=amount){
                    dp[i][j] = dp[i-1][j-nums[i-1]] | dp[i-1][j];
                }
                else
                dp[i][j]=dp[i][j-1];
            }
        }
        return dp[n][amount];
    }
};
