class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp ;
        //line sweep
        for(auto it :trips)
        {
            mp[it[1]]+=it[0];
            mp[it[2]]-=it[0];
        }
        int sum=0;
        for(auto x :mp)
        {
            sum+=x.second;
            if(sum>capacity)return false;
            // cout<<x.first<<" "<<x.second<<" = "<<sum<<endl;
        }
        return true;
    }
};