class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        for(auto& it : intervals){
            if(result.empty()){
                result.push_back(it);
                continue;
            }

            vector<int> lastIndex = result.back();
            if(lastIndex[1] >= it[0]){
                result.back()[1] = max(lastIndex[1], it[1]);
            }
            else result.push_back(it);
        }
        return result;
    }
};