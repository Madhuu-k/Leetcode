class Solution {
public:
    bool isPresent(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) return true;
            if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it : matrix){
            if(isPresent(it, target)) return true;
        }
        return false;
    }
};