class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> ord;
        while(!q.empty()){
            int i =q.front();
            ord.push_back(i);
            q.pop();
            for(auto it: adj[i]){
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }
        vector<int> empty;
        return ord.size() == numCourses ? ord : empty;
    }
};
