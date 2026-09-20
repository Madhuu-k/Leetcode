class Solution(object):
    def maxSubArray(self, nums):
        maxSum = nums[0]
        currSum = nums[0]

        for num in nums[1:]:
            currSum = max(num, num + currSum)
            maxSum = max(maxSum, currSum)

        return maxSum        