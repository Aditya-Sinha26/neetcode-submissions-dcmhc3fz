class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0, totC=0, totG=0, curr=0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            totC+=cost[i];
            totG+=gas[i];
            tot+=gas[i]-cost[i];
            if(tot<0){
                curr=i+1;
                tot=0;
            }
        }
        return totG<totC ? -1: curr;
    }
};
