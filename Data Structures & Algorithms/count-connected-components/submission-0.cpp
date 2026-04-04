class Solution {
public:
    void dfs(vector<vector<int>> adj, vector<int> &vis, int i){
        vis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};
