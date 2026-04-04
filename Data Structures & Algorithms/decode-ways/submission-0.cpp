class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0')
        return 0;
        int dp[n+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i]=1;
        }
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0')
            dp[i]=dp[i-1];
            else
            dp[i]=0;
            if(s[i-2]!='0' && stoi(s.substr(i-2,2))<=26)
            dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
