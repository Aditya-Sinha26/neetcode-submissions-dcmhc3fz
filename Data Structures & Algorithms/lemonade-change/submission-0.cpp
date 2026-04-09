class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        mp[5]=0;
        mp[10]=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                mp[5]++;
            }
            else if(bills[i]==10){
                if(mp[5]!=0){
                    mp[5]--;
                    mp[10]++;
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp[10]!=0){
                    mp[10]--;
                    if(mp[5]!=0)
                    {
                        mp[5]--;
                        continue;
                    }
                    else
                    return false;
                }
                else{
                    if(mp[5]>=3){
                        mp[5] = mp[5]-3;
                        continue;
                    }
                    else
                    return false;
                }
            }
        }
        return true;
    }
};