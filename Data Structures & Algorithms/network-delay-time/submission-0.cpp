class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        int ans=INT_MIN;
        for(auto it : times)
        {
            g[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});//{dist,from}

        while(!pq.empty())
        {
            int d = pq.top().first; 
            int prev = pq.top().second; 
            pq.pop();

            for(auto it : g[prev])
            {
                int next=it.first;
                int nextdist=it.second;
                if(dist[next]>d+nextdist)
                {
                    dist[next]=d+nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        return ans == INT_MAX ? -1 : ans;
        
    }
};
