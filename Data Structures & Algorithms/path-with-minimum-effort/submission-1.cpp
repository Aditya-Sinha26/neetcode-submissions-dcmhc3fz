class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        vector<int> dir = {0,1,0,-1,0};

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int effort = curr[0], r = curr[1], c = curr[2];

            if(r == n-1 && c == m-1)
                return effort;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];

                if(nr>=0 && nc>=0 && nr<n && nc<m){

                    int newEffort = max(effort,
                        abs(heights[r][c] - heights[nr][nc]));

                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};