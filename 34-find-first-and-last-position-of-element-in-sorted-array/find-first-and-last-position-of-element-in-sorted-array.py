class Solution(object):
    def search_left(self, nums, target):
        l, r = 0, len(nums) - 1
        pos = -1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                pos = mid
                r = mid - 1   
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return pos

    def search_right(self, nums, target):
        l, r = 0, len(nums) - 1
        pos = -1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                pos = mid
                l = mid + 1   # keep searching right
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return pos

    def searchRange(self, nums, target):
        return [self.search_left(nums, target), self.search_right(nums, target)]
