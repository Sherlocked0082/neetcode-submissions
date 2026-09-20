class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi)
        {
            int m=lo+(hi-lo)/2;
            if(nums[m]==target)return m;
            else if(nums[m]>target)hi--;
            else lo++;
        }   
        return -1;     
    }
};
