class Solution {
public:
    vector<string> temp;

    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& res, string s, int start){
        if(start == s.length()){
            res.push_back(temp);
            return;
        }

        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                temp.push_back(s.substr(start, end - start + 1));
                backtrack(res, s, end + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtrack(res, s, 0);
        return res;
    }
};