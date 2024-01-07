class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # # Brute Force
        # res = 0

        # for j in range(len(heights)):
        #     min_h = inf
        #     start_i = j - 1
        #     for i in range(j, len(heights)):
        #         if heights[i] == 0:
        #             start_i = i
        #         min_h = min(min_h, heights[i])
        #         res = max(res, (i - start_i) * min_h)

        # return res

        # # Brute Force 2
        # count = 0
        # res = 0

        # for height in set(heights):
        #     stack_thresh = height
        #     for i in range(len(heights)):
        #         if heights[i] < stack_thresh or i == len(heights) - 1:
        #             if heights[i] >= stack_thresh:
        #                 count += 1
        #             res = max(res, stack_thresh * count)
        #             count = 0
        #         else:
        #             count += 1
        
        # return res

        res = 0
        stack = []

        for i, h in enumerate(heights):
            start = i
            while stack and h < stack[-1][-1]:
                index, height = stack.pop()
                res = max(res, (i-index) * height)
                start = index
            stack.append([start, h])

        for i, h in stack:
            res = max(res, (len(heights) - i) * h)

        return res
