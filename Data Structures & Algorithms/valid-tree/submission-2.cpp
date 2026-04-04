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

    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);
        if(edges.size() != n-1)
        return false;

        for(int i=0;i<n;i++)
            parent[i] = i;

        bool ans=true;
        for(auto &e : edges){
            ans = unite(e[0], e[1]);
            if(!ans)
                return ans;
        }
        return ans;
    }
};
