class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        for(int num : seen){
            if(!seen.count(num - 1)){
                int len = 1;
                int curr = num;

                while(seen.count(curr + 1)){
                    curr = curr + 1;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};