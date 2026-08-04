class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        majority = len(nums) / 2
        freq = {}

        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        
        for key, value in freq.items():
            if(value > majority):
                return key

        return 0