# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        numSet = set(nums)
        curr = head
        while curr.val in numSet:
            curr = curr.next
        prev = res = curr

        if curr.next:
            curr = curr.next
            while curr:
                if curr.val not in numSet:
                    prev.next = curr
                    prev = curr
                else:
                    prev.next = None
                curr = curr.next
        
        return res
