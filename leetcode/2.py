# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        cur1 = l1
        cur2 = l2
        dummy = ListNode()
        cur_res = dummy

        while cur1 or cur2:
            if not cur_res.next:
                cur_res.next = ListNode(0)

            if cur2 and not cur1:
                cur_res.next.val += cur2.val
                cur2 = cur2.next
            elif cur1 and not cur2:
                cur_res.next.val += cur1.val
                cur1 = cur1.next
            else:
                cur_res.next.val += cur1.val + cur2.val
                cur1, cur2 = cur1.next, cur2.next

            if cur_res.next.val >= 10:
                cur_res.next.val = cur_res.next.val % 10
                cur_res.next.next = ListNode(1)

            cur_res = cur_res.next
            
        return dummy.next
