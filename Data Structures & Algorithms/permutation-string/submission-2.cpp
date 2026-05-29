class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)
        return false;
        int j=0;
        sort(s1.begin(), s1.end());
        for(int j=0;j<m-n+1;j++){
            string t = s2.substr(j,n);
            sort(t.begin(), t.end());
            if(t==s1)
            return true;
        }
        return false;
    }
};
