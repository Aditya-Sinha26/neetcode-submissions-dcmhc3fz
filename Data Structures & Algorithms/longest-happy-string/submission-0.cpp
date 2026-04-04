class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string s="";
        while(pq.size()>1){
            int k =pq.top().first;
            char x = pq.top().second;
            pq.pop();
            int k1 =pq.top().first;
            char x1 = pq.top().second;
            pq.pop();
            if(k>=2)
            {
                s=s+x+x;
                k=k-2;
            }
            else{
                s+=x;
                k=k-1;
            }
            if(k1>=2 && k1>=k)
            {
                s=s+x1+x1;
                k1=k1-2;
            }
            else{
                s+=x1;
                k1=k1-1;
            }
            if(k>0)
            pq.push({k,x});
            if(k1>0)
            pq.push({k1,x1});
        }
        if(pq.empty())
        return s;
        if(pq.top().first>=2){
            s+=pq.top().second;
            s+=pq.top().second;
        }
        else{
            s+=pq.top().second;
        }
        return s;

    }
};