class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        startIndex = 0
        endIndex = len(numbers) - 1
        while startIndex < endIndex:
            if numbers[startIndex] + numbers[endIndex] > target:
                endIndex -= 1
            elif numbers[startIndex] + numbers[endIndex] < target:
                startIndex += 1
            else:
                return [startIndex + 1,endIndex + 1]
        return []