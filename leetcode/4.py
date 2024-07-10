class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        l1, l2 = len(nums1), len(nums2)
        l, r = 0, l1 - 1
        med = (l1 + l2) // 2

        while True:
            m = (l + r) // 2
            rem_idx = med - m - 2

            l1l = nums1[m] if m >= 0 else -inf
            l1r = nums1[m + 1] if (m + 1) < l1 else inf
            l2l = nums2[rem_idx] if rem_idx >= 0 else -inf
            l2r = nums2[rem_idx + 1] if (rem_idx + 1) < l2 else inf

            if l1l <= l2r and l2l <= l1r:
                if (l1 + l2) % 2:
                    return min(l2r, l1r)
                else:
                    return (max(l1l, l2l) + min(l2r, l1r)) / 2  
            elif l1l > l2r:
                r = m - 1
            else:
                l = m + 1
