class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            int curr = asteroids[i];
            bool dest = false;
            while(!st.empty() && st.top()>0 && curr<0){
                if(abs(st.top()) < abs(curr)) {
                    st.pop();
                }
                else if(abs(st.top()) == abs(curr)) {
                    st.pop();
                    dest = true;
                    break;
                }
                else {
                    dest = true;
                    break;
                }
            }
            if(!dest)
            st.push(curr);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};