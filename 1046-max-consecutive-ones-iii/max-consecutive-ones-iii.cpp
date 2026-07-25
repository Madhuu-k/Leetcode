class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxSeries = INT_MIN;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeros++;
            if(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            maxSeries = max(maxSeries, right - left + 1);
        }
        return maxSeries;
    }
};