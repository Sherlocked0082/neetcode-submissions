class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)return false;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;//{node,parent}
        unordered_set<int> visited;
        q.push({0,-1});

        while(!q.empty())
        {
            auto node=q.front().first;
            auto parent=q.front().second;
            q.pop();
            visited.insert(node);
            for(auto it : adj[node])
            {
                if(visited.find(it)==visited.end())
                {
                    q.push({it,node});
                }
                else if (visited.count(it) && it!=parent)return false;
            }
        }
        return visited.size()==n;
    }
};
