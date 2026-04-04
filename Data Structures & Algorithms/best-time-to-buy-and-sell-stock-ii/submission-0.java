class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int mn=10000;
        int pr=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mn){
                mn=prices[i];
            }
            else{
                pr=pr+prices[i]-mn;
                mn=prices[i];
            }
        }
        return pr;
    }
}