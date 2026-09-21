class Solution(object):
    def maxArea(self, height):
        ans = 0
        left, right = 0, len(height) - 1

        while left < right:
            area = min(height[left], height[right]) * (right - left)
            ans = max(area, ans)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return ans

            

        