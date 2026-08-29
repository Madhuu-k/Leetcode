class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        seen = {}
        for x in nums:
            seen[x] = seen.get(x, 0) + 1

        return max(seen, key=seen.get)
                