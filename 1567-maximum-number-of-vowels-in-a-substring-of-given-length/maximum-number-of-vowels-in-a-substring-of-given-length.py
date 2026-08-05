class Solution(object):
    def isVowel(self, ch):
        tmp = ch.lower()
        vowels = {'a', 'e', 'i', 'o', 'u'}
        if tmp in vowels:
            return True
        return False

    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        left = 0
        maxLen = float('-inf')
        count = 0

        for right in range(len(s)):
            if self.isVowel(s[right]):
                count += 1
            
            if right - left + 1 == k:
                maxLen = max(maxLen, count)
                if self.isVowel(s[left]): count -= 1
                left += 1
        
        return maxLen
        