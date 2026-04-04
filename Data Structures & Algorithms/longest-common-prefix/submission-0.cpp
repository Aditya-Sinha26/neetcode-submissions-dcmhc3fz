class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int sz = INT_MAX;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            int n = temp.size();
            sz = min(sz, n);
        }
        for(int i=0;i<sz;i++){
            bool s = true;
            char ch = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(ch != strs[j][i])
                {
                    s=false;
                    break;
                }
            }
            if(s)
            ans+=ch;
            else
            break;
        }
        return ans;
    }
};