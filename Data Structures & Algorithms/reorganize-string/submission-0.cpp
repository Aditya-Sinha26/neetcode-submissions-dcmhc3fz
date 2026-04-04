class Solution {
public:
    string reorganizeString(string s) {
      vector<int> fre(26,0);
      for(auto i:s)
        fre[i-'a']++;
      priority_queue<pair<int,int>> pq;
      for(int i=0;i<26;i++)
      {
        if(fre[i]>0)
          pq.push({fre[i],i});
      }
      string ans;
      while(!pq.empty())
      {
        pair<int,int> p=pq.top();
        int k=pq.top().first;
        int key=pq.top().second;
        char c=pq.top().second+'a';
        pq.pop();
        if(ans.size()>0&&ans[ans.size()-1]==c)
        {
          if(pq.empty())
            return "";
          else
          {
            k=pq.top().first;
            key=pq.top().second;
            c=key+'a';
            pq.pop();
            pq.push(p);
          }
        }
        ans=ans+c;
        k--;
        if(k>0)
        pq.push({k,key});
      }
      
      return ans;
    }
};