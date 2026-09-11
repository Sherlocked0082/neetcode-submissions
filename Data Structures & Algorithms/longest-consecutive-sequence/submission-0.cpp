class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(auto it: nums){
            if(st.find(it-1)==st.end())
            {
                int x=1;
                while(st.find(it+x)!=st.end())x++;
                ans=max(ans,x);
            }
        }
        return ans;
    }
};
