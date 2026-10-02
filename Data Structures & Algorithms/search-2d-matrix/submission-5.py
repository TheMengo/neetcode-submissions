class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False 
        leftIndexU = 0
        rightIndexD = len(matrix) - 1
        leftIndexL = 0
        rightIndexR = len(matrix[0]) - 1
        while leftIndexU <= rightIndexD:
            midpoint = int((leftIndexU + rightIndexD) / 2)
            if matrix[midpoint][0] <= target:
                leftIndexU = midpoint + 1
            else:
                rightIndexD = midpoint - 1

        while leftIndexL <= rightIndexR:
            midpointsecond = int((leftIndexL + rightIndexR) / 2)
            if matrix[rightIndexD][midpointsecond] < target:
                leftIndexL = midpointsecond + 1
            elif matrix[rightIndexD][midpointsecond] > target:
                rightIndexR = midpointsecond - 1
            else:
                return True
        return False
