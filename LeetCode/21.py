# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 and not list2:
            return list1
        elif list2 and not list1:
            return list2
        else:
            head = None
            curr1 = list1
            curr2 = list2

            while curr1 or curr2:
                if not head:
                    if curr1.val > curr2.val:
                        head = ListNode(curr2.val)
                        curr = head
                        curr2 = curr2.next
                    else:
                        head = ListNode(curr1.val)
                        curr = head
                        curr1 = curr1.next
                else:
                    if curr1 and curr2:
                        if curr1.val > curr2.val:
                            curr.next = ListNode(curr2.val)
                            curr = curr.next
                            curr2 = curr2.next
                        else:
                            curr.next = ListNode(curr1.val)
                            curr = curr.next
                            curr1 = curr1.next
                    elif curr1 and not curr2:
                        curr.next = ListNode(curr1.val)
                        curr = curr.next
                        curr1 = curr1.next
                    else:
                        curr.next = ListNode(curr2.val)
                        curr = curr.next
                        curr2 = curr2.next
            return head
