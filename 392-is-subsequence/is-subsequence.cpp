class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        for(int right = 0; right < t.length(); right++){
            if(s[left] == t[right]) left++;
        }
        return left == s.length();
    }
};