# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        curr = head
        headr = ListNode()
        currr = headr
        l = []
        lr = []
        while curr:
            l.append(curr.val)
            curr = curr.next

        left = 0
        right = len(l) - 1

        while left <= right:
            if right == left:
                lr.append(l[left])
            else:
                lr.append(l[left])
                lr.append(l[right])
            left += 1
            right -= 1
        
        for char in lr:
            currr.next = ListNode(char)
            currr = currr.next
        
        head.next = headr.next.next

        """
        Do not return anything, modify head in-place instead.
        """
        