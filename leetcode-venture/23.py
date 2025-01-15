# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        
        while len(lists) > 1:
            merge_result = []

            for i in range(0, len(lists), 2):
                l1 = lists[i]
                if i + 1 < len(lists):
                    l2 = lists[i+1]
                else:
                    l2 = None
                merge_result.append(self.mergeLists(l1, l2))

            lists = merge_result
        
        return lists[0]

    def mergeLists(self, l1, l2):
        dummy = ListNode()
        curr = dummy

        while l1 or l2:
            if l1 and l2:
                if l2.val < l1.val:
                    curr.next = ListNode(l2.val)
                    l2 = l2.next
                else:
                    curr.next = ListNode(l1.val)
                    l1 = l1.next

            elif l1 and not l2:
                curr.next = ListNode(l1.val)
                l1 = l1.next
                
            else:
                curr.next = ListNode(l2.val)
                l2 = l2.next
                
            curr = curr.next

        return dummy.next
                