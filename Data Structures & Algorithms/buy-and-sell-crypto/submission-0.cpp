class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pr=0,n=prices.size(),mx=0;
        for(int i=n-1;i>=0;i--){
            if(mx<prices[i]){
                mx=prices[i];
            }
            else{
                pr=max(pr,mx-prices[i]);
            }
        }
        return pr;
    }
};
