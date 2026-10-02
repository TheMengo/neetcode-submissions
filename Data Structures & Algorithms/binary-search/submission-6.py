class Solution:
    def search(self, nums: List[int], target: int) -> int:
        leftIndex = 0
        rightIndex = len(nums) - 1
        while leftIndex <= rightIndex:
            midPoint = int((leftIndex + rightIndex) / 2)
            if nums[midPoint] > target:
                rightIndex = midPoint - 1
            elif nums[midPoint] < target:
                leftIndex = midPoint + 1
            if nums[midPoint] == target:
                return midPoint
            
        return -1
            