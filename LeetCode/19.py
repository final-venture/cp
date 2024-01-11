# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        self.i = 0
        self.curr = head
        
        def getlen():
            if self.curr:
                self.curr = self.curr.next
            else:
                return self.i
            self.i += 1
            return getlen()

        length = getlen()
        
        j = 0
        curr = head
        prev = None

        while j < length-n:
            if curr:
                prev = curr
                curr = curr.next
            j += 1
        if prev:
            prev.next = curr.next 
        else:
            head = head.next
             
        return head
