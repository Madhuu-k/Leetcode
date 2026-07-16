class Solution {
public:
    vector<int> temp;

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<bool>& visited){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;

            temp.push_back(nums[i]);
            backtrack(res, nums, visited);
            temp.pop_back();

            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(res, nums, visited);
        return res;
    }
};