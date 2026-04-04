class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> indeg(numCourses, 0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        map<int, set<int>> mp;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it: adj[x]){
                mp[it].insert(x);
                for(auto k : mp[x]){
                    mp[it].insert(k);
                }
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        } 
        vector<bool> ans;
        for(auto it: queries){
            ans.push_back(mp[it[0]].count(it[1]));
        }
        return ans;
    }
};