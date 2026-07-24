class Solution {
public:
    bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    int maxVowels(string s, int k) {
        int left = 0;
        int count = 0;
        int maxVowels = INT_MIN;
        for(int right = 0; right < s.length(); right++){
            if(isVowel(s[right])) count++;

            if(right - left + 1 == k){
                maxVowels = max(maxVowels, count);

                if(isVowel(s[left])) count--;

                left++;
            }
        }   
        return maxVowels;
    }
};