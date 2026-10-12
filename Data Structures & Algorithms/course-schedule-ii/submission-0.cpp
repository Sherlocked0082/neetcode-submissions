class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        vector<int> ans;
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        int temp=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            temp++;
            for(auto next:adj[curr])
            {
                if(--indeg[next]==0){
                    q.push(next);
                }
            }
        }
        return (temp==numCourses)?ans: vector<int>{};

    }
};
