class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, minSum = INT_MAX, sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                minSum = min(minSum, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minSum == INT_MAX) ? 0 : minSum;
    }
};