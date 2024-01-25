class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        inc = True

        if len(arr) < 3:
            return False

        curr = 1

        if inc:
            while curr < len(arr):
                if curr >= len(arr):
                    return False
                if arr[curr-1] >= arr[curr]:
                    if curr == 1:
                        return False
                    else:
                        inc = False
                        break
                curr += 1

        if not inc:
            while curr < len(arr):
                if curr >= len(arr):
                    break
                if arr[curr-1] <= arr[curr]:
                    return False
                curr += 1

            return True
