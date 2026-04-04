class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs.size();i++){
            ans+=strs[i];
            ans = ans+"-";
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n=s.size();
        vector<string> ans;
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='-')
            {
                ans.push_back(temp);
                temp="";
            }
            else
            temp+=s[i];
        }
        return ans;
    }
};
