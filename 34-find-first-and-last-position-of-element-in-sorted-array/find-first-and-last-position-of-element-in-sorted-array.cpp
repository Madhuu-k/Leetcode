class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }

    int findRight(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findLeft(nums, target), findRight(nums, target)};
    }
};