class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        data = set()

        def helper(i, cand):
            if i == len(nums):
                res.append(cand)
                return

            if nums[i] in data:
                helper(i+1, cand)
            else:
                helper(i+1, cand+[nums[i]])
                data.add(nums[i])
                helper(i+1, cand)
                data.remove(nums[i])

        helper(0, [])
        return res
