class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<position.size();i++){
            pq.push({position[i], speed[i]});
        }
        int ans=0;
        double temp=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double t = (double)(target - it.first)/(double)it.second;
            if(t>temp){
                ans++;
                temp=t;
            }
        }
        return ans;
    }
};
