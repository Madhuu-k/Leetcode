class Solution {
public:
    int solve(vector<int>& coins, vector<int>& dp, int amount){
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;

        for(int coin : coins){
            int res = solve(coins, dp, amount - coin);
            if(res != INT_MAX) ans = min(ans, res + 1);
        }

        dp[amount] = ans;
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = solve(coins, dp, amount);
        return (res == INT_MAX) ? -1 : res;
    }
};