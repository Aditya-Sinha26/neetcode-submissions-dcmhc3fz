class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][1]]++;
        }
        for(int i=0;i<trust.size();i++){
            if(mp[trust[i][0]]==n-1)
            return -1;
        }
        for(auto it: mp){
            if(it.second == n-1)
            return it.first;
        }
        return -1;
    }
};