class Solution(object):
    def maxProduct(self, nums):
        maxSoFar = minSoFar = ans = nums[0]

        for i in range(1, len(nums)):
            x = nums[i]
            newMax = max({x, x * maxSoFar, x * minSoFar})
            newMin = min({x, x * maxSoFar, x * minSoFar})

            maxSoFar = newMax
            minSoFar = newMin

            ans = max(ans, maxSoFar)

        return ans
        