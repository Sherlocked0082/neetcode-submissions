class Solution {
public:
    bool caneat(vector<int> & piles,int v,int h)
    {
        long long time=0;
        for(auto x : piles){
            time+=ceil((double)x/v);
        }
        // cout<<time<<" "<<v<<endl;
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,hi=1e9,ans=1;
        // N N N N N Y Y Y Y Y Y Y 
        while(lo<=hi)
        {
            int m=lo+(hi-lo)/2;
            if(caneat(piles,m,h))
            {
                ans=m;
                hi=m-1;
            }else
            {
                lo=m+1;
            }
        }
        return ans;
    }
};
