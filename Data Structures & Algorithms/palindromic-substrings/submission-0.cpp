class Solution {
public:
    int cnt=0;
    void solve(string s,int l,int r){
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r])
        {
            cnt++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            solve(s,i,i);
            solve(s,i,i+1);
        }
        return cnt;
    }
};
