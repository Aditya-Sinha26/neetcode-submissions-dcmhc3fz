class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.size();) {
            if (s[i] == ']') {
                string temp = "";

                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int repeat = stoi(numStr);
                string expanded = "";
                for (int k = 0; k < repeat; k++) {
                    expanded += temp;
                }
                st.push(expanded);
                i++;
            }
            else {
                st.push(string(1, s[i]));
                i++;
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};