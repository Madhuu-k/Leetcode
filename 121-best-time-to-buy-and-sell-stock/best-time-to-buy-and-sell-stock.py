class Solution(object):
    def maxProfit(self, prices):
        maxPrice = 0
        minPrice = 1e9

        for x in prices:
            minPrice = min(minPrice, x)
            price = x - minPrice
            maxPrice = max(maxPrice, price)

        return maxPrice
        