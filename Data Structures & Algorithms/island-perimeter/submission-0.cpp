class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter=0;
        int r[] = {-1,1,0,0};
        int c[] = {0,0,-1,1}; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++){
                        int newr = i + r[k];
                        int newc = j + c[k];
                        if(newr>=0 && newr<n && newc<m && newc>=0 && grid[newr][newc]==1)
                        perimeter+=0;
                        else{
                            perimeter+=1;
                        }   
                    }
                }
            }
        }
        return perimeter;
    }
};