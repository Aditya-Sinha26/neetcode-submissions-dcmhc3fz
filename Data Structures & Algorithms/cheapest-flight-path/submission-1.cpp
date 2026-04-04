class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<int> stops(n, INT_MAX);
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int cost = it[0];
            int u = it[1];
            int step = it[2];
            if(u == dst) return cost;
            if(step > k || step > stops[u]) continue;
            stops[u] = step;
            for(auto &v : adj[u]){
                int next = v.first;
                int price = v.second;
                pq.push({cost + price, next, step + 1});
            }
        }
        return -1;
    }
};