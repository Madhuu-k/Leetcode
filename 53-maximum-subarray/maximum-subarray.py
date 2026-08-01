class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = nums[0]
        currSum = nums[0]

        for x in nums[1:]:
            currSum = max(x, x + currSum)
            maxSum = max(maxSum, currSum)

        return maxSum        