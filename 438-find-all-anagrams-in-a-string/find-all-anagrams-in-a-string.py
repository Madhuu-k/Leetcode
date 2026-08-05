class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        pos = []
        left = 0
        freqS = {}
        freqP = {}

        for c in p:
            freqP[c] = freqP.get(c, 0) + 1

        for right in range(len(s)):
            freqS[s[right]] = freqS.get(s[right], 0) + 1
            if right - left + 1 == len(p):
                if freqP == freqS: pos.append(left)
                freqS[s[left]] = freqS.get(s[left], 0) - 1
                if freqS[s[left]] == 0: del freqS[s[left]]
                left += 1
            
        return pos
