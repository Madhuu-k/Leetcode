class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        map1 = {}
        map2 = {}

        for i in range(len(s)):
            c1, c2 = s[i], t[i]

            if c1 in map1 and map1[c1] != c2:
                return False
            
            if c2 in map2 and map2[c2] != c1:
                return False

            map1[c1] = c2
            map2[c2] = c1
        
        return True