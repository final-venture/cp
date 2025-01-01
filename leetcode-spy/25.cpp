/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *gp = dummy;
        while (1)
        {
            ListNode *kth = getkth(gp, k);
            if (!kth)
                break;
            ListNode *gn = kth->next;

            // reverse
            ListNode *curr = gp->next;
            ListNode *prev = kth->next;
            ListNode *tmp = nullptr;
            while (curr != gn)
            {
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            tmp = gp->next;
            gp->next = kth;
            gp = tmp;
        }
        return dummy->next;
    }

    ListNode *getkth(ListNode *curr, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (!curr)
                return nullptr;
            curr = curr->next;
        }
        return curr;
    }
};
