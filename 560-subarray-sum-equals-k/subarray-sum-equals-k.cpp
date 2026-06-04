class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int currSum = 0;
        int count = 0;

        for(int num : nums){
            currSum += num;
            int req = currSum - k;
            if(mp.find(req) != mp.end()) count += mp[req];
            mp[currSum]++;
        }

        return count;
    }
};