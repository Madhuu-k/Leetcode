class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        left = 0
        freq = {}
        maxFreq = 0
        ans = 0

        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            maxFreq = max(maxFreq, freq[s[right]])
            while (right - left + 1) - maxFreq > k:
                freq[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)

        return ans