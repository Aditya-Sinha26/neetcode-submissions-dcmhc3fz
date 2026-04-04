class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,1,-0,0};
        int dc[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int cnt=0;
        if(!q.empty())
        cnt=-1;
        while(!q.empty()){
            int x = q.size();
            cnt++;
            for(int l=0;l<x;l++){
                auto [nr, nc] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newr = nr+dr[k];
                    int newc = nc+dc[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        q.push({newr,newc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return cnt;
    }
};
