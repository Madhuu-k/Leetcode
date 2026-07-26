class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for(int i = 2* n - 1; i >= 0; i--){  // 2*n-2 because we're having circular loop
            while(!st.empty() && st.top() <= nums[i % n]) st.pop();
            if(i < n){  // to make sure we dont run on infinity
                if(!st.empty()) res[i] = st.top();
            }
            st.push(nums[i % n]);
        }

        return res;
    }
};