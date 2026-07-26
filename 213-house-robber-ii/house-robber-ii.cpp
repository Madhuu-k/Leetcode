class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i){
        if(i < 0) return 0;
        if(i == 0) return nums[0];

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums, dp, i - 2);
        int skip = solve(nums, dp, i - 1);

        dp[i] = max(take, skip);

        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> skipFirst(nums.begin() + 1, nums.end());
        vector<int> skipLast(nums.begin(), nums.end() - 1);

        vector<int> dp1(skipFirst.size(), -1);
        vector<int> dp2(skipLast.size(), -1);

        return max(
            solve(skipFirst, dp1, skipFirst.size() - 1),
            solve(skipLast, dp2, skipLast.size() - 1)
        );
    }
};
