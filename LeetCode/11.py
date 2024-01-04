class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0

        while right > left:
            max_area = max(max_area, min(height[left], height[right]) * (right-left))

            if height[left] < height[right]:
                    left += 1
            elif height[right] < height[left]:
                    right -= 1
            else:
                while height[right] == height[left] and right > left:
                    left += 1

        return max_area
