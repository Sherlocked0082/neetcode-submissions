class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        if(q.empty())return false;
        int temp=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            temp++;
            for(auto next:adj[curr])
            {
                if(--indeg[next]==0){
                    q.push(next);
                }
            }
        }
        return temp==numCourses;


    }
};
