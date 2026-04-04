class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)
        return false;
        int j=0;
        sort(s1.begin(), s1.end());
        for(int i=n-1;i<m;i++,j++){
            string t = s2.substr(j,i-j+1);
            sort(t.begin(), t.end());
            if(t==s1)
            return true;
        }
        return false;
    }
};
