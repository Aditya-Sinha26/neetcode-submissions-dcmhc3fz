class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int i =q.front();
            cnt++;
            q.pop();
            for(auto it: adj[i]){
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }
        return cnt == numCourses;
    }
};
