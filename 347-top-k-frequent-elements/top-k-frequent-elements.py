class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for x in nums:
            freq[x] = freq.get(x, 0) + 1

        arr = sorted(freq.items(), key=lambda x : x[1], reverse=True)

        res = []

        for i in range(k):
            res.append(arr[i][0])

        return res
        