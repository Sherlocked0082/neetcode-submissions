class Solution {
public:
    void DFS(vector<vector<int>> adj,int s,vector<int> & visited)
    {
        visited[s]=1;
        for(auto next : adj[s])
        {
            if(!visited[next])DFS(adj,next,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                cnt++;
                DFS(adj,i,visited);
            }
        }
        return cnt;

    }
};
