class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqs1(26);
        vector<int> freqs2(26);
        for(char c : s1) freqs1[c - 'a']++;
        int left = 0;
        for(int right = 0; right < s2.length(); right++){
            freqs2[s2[right] - 'a']++;
            if(right - left + 1 == s1.length()){
                if(freqs1 == freqs2) return true;
                freqs2[s2[left] - 'a']--;
                left++;
            }
        }
        return false;
    }
};