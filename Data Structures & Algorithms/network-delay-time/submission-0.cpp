class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<times.size();j++){
                int u = times[j][0];
                int v = times[j][1];
                int t = times[j][2];
                if(dist[u]!= INT_MAX && dist[u]+t < dist[v]){
                    dist[v] = t + dist[u];
                }
            }
        }
        int mx = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)
            return -1;
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
