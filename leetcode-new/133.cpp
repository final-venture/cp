/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> o2n;
        deque<Node *> dq;

        o2n[node] = new Node(node->val);
        dq.push_back(node);
        while (!dq.empty())
        {
            Node *x = dq.front();
            dq.pop_front();
            for (auto nei : x->neighbors)
            {

                if (o2n.find(nei) == o2n.end())
                {
                    o2n[nei] = new Node(nei->val);
                    dq.push_back(nei);
                }
                o2n[x]->neighbors.push_back(o2n[nei]);
            }
        }
        return o2n[node];
    }
};
