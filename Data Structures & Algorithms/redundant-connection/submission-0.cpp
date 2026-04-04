class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py)
            return false;
        if(size[px] < size[py])
            swap(px,py);
        parent[py] = px;
        size[px] += size[py];
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=1;i<=n;i++)
            parent[i] = i;

        for(auto &e : edges){
            if(!unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};