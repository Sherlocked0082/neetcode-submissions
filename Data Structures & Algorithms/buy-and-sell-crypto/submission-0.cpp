class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0;
        vector<int> mx(n,0);
        mx[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx[i]=max(mx[i+1],prices[i]);
        }
        for(int i=0;i<n;i++)ans=max(ans,mx[i]-prices[i]);
        return ans;
    }
};
