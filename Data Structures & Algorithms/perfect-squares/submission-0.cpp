class Solution {
public:
    int numSquares(int n) {
        int x=100;
        int dp[101][n+1];
        for(int i=0;i<=x;i++){
            for(int j=0;j<=n;j++){
                if(j==0)
                dp[i][j]=0;
                else
                dp[i][j]=INT_MAX;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=n;j++){
                int temp = i*i;
                if(temp<=j){
                    dp[i][j]=min(1+dp[i][j-temp], dp[i-1][j]);
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[x][n];
    }
};