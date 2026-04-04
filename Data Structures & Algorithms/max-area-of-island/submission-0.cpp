class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        int mx =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j] == 1){
                    cnt++;
                    q.push({i,j});
                    grid[i][j]=2;
                    while(!q.empty()){
                        int newi = q.front().first;
                        int newj = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr = newi + dr[k];
                            int nc = newj + dc[k];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                            {
                                cnt++;
                                grid[nr][nc]=2;
                                q.push({nr,nc});
                            }
                        } 
                    }
                }
                mx = max(cnt, mx);
            }
        }
        return mx;
    }
};
