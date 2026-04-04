class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y= points[i][1];
            int d = x*x + y*y;
            pq.push({d,{x,y}});
            if(pq.size()>k)
            pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> res;
            auto p = pq.top().second;
            pq.pop();
            res.push_back(p.first);
            res.push_back(p.second);
            ans.push_back(res);
        }
        return ans;
    }
};
