/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> o2n;
        Node *curr = head;
        Node *prev = nullptr;
        while (curr)
        {
            o2n[curr] = new Node(curr->val);
            if (prev != nullptr)
                o2n[prev]->next = o2n[curr];
            prev = curr;
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            o2n[curr]->random = o2n[curr->random];
            curr = curr->next;
        }
        return o2n[head];
    }
};
