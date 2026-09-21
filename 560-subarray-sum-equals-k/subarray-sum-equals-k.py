class Solution(object):
    def subarraySum(self, nums, k):
        prefix = {0 : 1}
        
        currSum = 0
        count = 0

        for num in nums:
            currSum += num
            needed = currSum - k

            if needed in prefix:
                count += prefix[needed]
            
            prefix[currSum] = prefix.get(currSum, 0) + 1
        
        return count
        