class Solution {
public:
    bool solve(string s)
    {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
                
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int t=0,j=n-1;
        for(int i=0;i<n/2;)
        {
            if(s[i]==s[j])
            {
                i++;j--;
                continue;
            }
            else
            {
                if(t==0)
                {
                    t=1;
                    bool ans=solve(s.substr(i,j-i))||solve(s.substr(i+1,j-i));
                    return ans;
                }
                else
                    return false;
            }
        }
        return true;
    }
};