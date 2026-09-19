class Solution(object):
    def missingNumber(self, nums):
        maxNum = max(nums)
        for x in range(maxNum):
            if x not in nums:
                return x
        
        return len(nums)
        