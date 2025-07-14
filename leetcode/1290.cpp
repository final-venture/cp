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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr)
        {
            curr = curr -> next;
            ++len;
        }       
        int ret = 0;
        curr = head;
        for (int bit = len - 1; bit >= 0; --bit)
        {
            ret += (pow(2, bit) * (curr -> val)); 
            curr = curr -> next;
        }
        return ret;
    }
};
