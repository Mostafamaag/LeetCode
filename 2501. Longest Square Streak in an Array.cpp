class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> dp;
        for(auto n : nums) dp[n] = -1;
        
        int res = 0;
        for(auto n : nums){
            res = max(res, dfs(n, dp));
        }

        return res > 1? res : -1;
    }
    int dfs(long long n, unordered_map<int, int> &dp){
        if(n > 1e5 || !dp.contains(n)) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = 1 + dfs(n*n, dp);
    }
};
