class Solution {
public:
    string ans="";
    int mx=0;
    void solve1(string s){
        int n=s.size();
        for(int k=0;k<n;k++){
            int j=k, i=k;
            while(i>=0 && j<n && s[i]==s[j]){
                int t=j-i+1;
                if(t>mx){
                    mx=t;
                    ans=s.substr(i,j-i+1);
                }
                i--;
                j++;
            }
        }
    }
    void solve2(string s){
        int n=s.size();
        for(int k=0;k<n;k++){
            int i=k,j=k+1;
            while(i>=0 && j<n && s[i]==s[j]){
                int t=j-i+1;
                if(t>mx){
                    mx=t;
                    ans=s.substr(i,j-i+1);
                }
                i--;
                j++;
            }
        }
    }
    string longestPalindrome(string s) {
        solve1(s);
        solve2(s);
        return ans;
    }
};
