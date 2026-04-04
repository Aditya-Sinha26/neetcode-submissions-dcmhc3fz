class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
        for(int i=0;i<n;i++){
            if(operations[i] == "+"){
                if(st.size()<2)
                return -1;
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x+y;
                st.push(y);
                st.push(x);
                st.push(z);
            }
            else if(operations[i] == "D"){
                if(st.size()<1)
                return -1;
                int x = st.top();
                st.push(2*x);
            }
            else if(operations[i] == "C")
            st.pop();
            else{
                st.push(stoi(operations[i]));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};