class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int ans=INT_MIN;
        unordered_map<char,int> mp;
        int l=0,r=0;
        while(r<s.size())
        {
            //acquire till valid
            if(mp[s[r]]==0){
                mp[s[r]]++;
                r++;
            }
            //release till invalid
            else
            {
                mp[s[l]]--;
                l++;
            }
            // cout<<r<<" "<<l<<endl;
            ans=max(ans,r-l);
        }
        return ans;
        
    }
};
