# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        seen = {}
        curr = head
        while curr:
            if curr == None:
                return False
            if seen.get(curr, False):
                return True
            seen[curr] = True
            curr = curr.next
