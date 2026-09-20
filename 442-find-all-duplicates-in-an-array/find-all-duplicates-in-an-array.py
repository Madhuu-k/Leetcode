class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        seen = {}
        for num in nums:
            seen[num] = seen.get(num, 0) + 1
            if seen[num] > 1:
                res.append(num)

        return res
        