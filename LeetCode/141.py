# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Own
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

# OPTIMAL - Floyd's Tortoise and Hare Algorithm
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True

        return False
