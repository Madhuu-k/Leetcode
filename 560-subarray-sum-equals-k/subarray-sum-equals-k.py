class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        prefix_count = {0: 1}
        curr_sum = 0

        for num in nums:
            curr_sum += num
            count += prefix_count.get(curr_sum - k, 0)
            prefix_count[curr_sum] = prefix_count.get(curr_sum, 0) + 1

        return count