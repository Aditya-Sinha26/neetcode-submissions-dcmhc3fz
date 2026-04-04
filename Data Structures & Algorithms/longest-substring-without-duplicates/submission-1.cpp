class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int n = s.size(),cnt=0;
        while(j<n){
            if(mp.count(s[j])){
                i = max(i, mp[s[j]] + 1); 
            }
            cnt = max(cnt, j-i+1);
            mp[s[j]]=j;
            j++;
        }
        return cnt;
    }
};
