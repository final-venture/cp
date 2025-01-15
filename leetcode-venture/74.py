class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        left = 0
        right = rows * cols - 1

        while left <= right:
            middle = (left + right) // 2
            if matrix[middle // cols][middle % cols] < target:
                left = middle + 1
            elif matrix[middle // cols][middle % cols] > target:
                right = middle - 1
            else:
                return True

        return False
