class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        int left = 0;
        double sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(right - left + 1 == k){
                double avg = sum / k;
                maxAvg = max(maxAvg, avg);
                sum -= nums[left];
                left++;
            }
        }
        return maxAvg;
    }
};