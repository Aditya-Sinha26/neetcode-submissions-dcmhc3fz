class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n=board.size();
        int m = board[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j] == 'O')
                    {
                        q.push({i,j});
                        board[i][j] = '1';
                    }
                }
            }
        }
        while(!q.empty()){
            auto [nr,nc] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newr = nr + dr[i];
                int newc = nc + dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O'){
                    q.push({newr,newc});
                    board[newr][newc] = '1';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1')
                board[i][j]='O';
            }
        }
    }
};
