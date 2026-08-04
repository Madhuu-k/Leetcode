class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen = set(nums)
        maxLen = 0

        for num in seen:
            if num - 1 not in seen:
                curr = num
                currLen = 1

                while curr + 1 in seen:
                    curr += 1
                    currLen += 1

                maxLen = max(maxLen, currLen)

        return maxLen
        