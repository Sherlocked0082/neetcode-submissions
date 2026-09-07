class Solution {
public:
    int distance(int x,int y)
    {
        return (pow(x,2)+pow(y,2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto it : points)
        {
            pq.push({distance(it[0],it[1]),{it[0],it[1]}});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});            
            pq.pop();
        }
        return ans;
    }
};
