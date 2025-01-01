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
    ListNode *&merge(ListNode *&c1, ListNode *&c2)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (c1 && c2)
        {
            if (c1->val <= c2->val)
            {
                curr->next = new ListNode(c1->val);
                c1 = c1->next;
            }
            else
            {
                curr->next = new ListNode(c2->val);
                c2 = c2->next;
            }
            curr = curr->next;
        }
        if (c1)
        {
            curr->next = c1;
        }
        if (c2)
        {
            curr->next = c2;
        }
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1)
        {
            vector<ListNode *> tmp;
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                tmp.push_back(merge(l1, l2));
            }
            lists = move(tmp);
        }
        return lists[0];
    }
};
