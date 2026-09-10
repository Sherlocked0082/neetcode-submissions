class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int l = 0;
        int cnt = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            // Acquire
            mp[s[r]]++;
            cnt = max(cnt, mp[s[r]]);

            // Release until valid
            while ((r - l + 1) - cnt > k) {
                mp[s[l]]--;
                l++;
            }

            // Current window is valid
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};