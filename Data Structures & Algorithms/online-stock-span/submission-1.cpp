class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx=1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price)
        st.pop();
        int ans = 1;
        if(st.empty())
        ans = idx;
        else if(!st.empty() && st.top().first>price)
        ans = idx - st.top().second+1;

        idx++;
        st.push({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */