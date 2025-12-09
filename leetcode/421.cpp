// No trie
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        int maxBit = log2(max(*max_element(nums.begin(), nums.end()), 1));
        int maxx = 0, curr_mask = 0;
        for (int i = maxBit; i >= 0; --i)
        {
            int target = maxx | (1 << i);
            curr_mask |= (1 << i);
            unordered_set<int> numSet;
            for (int num : nums)
            {
                numSet.insert(num & curr_mask);
            }
            for (int cand : numSet)
            {
                if (numSet.contains(target ^ cand))
                {
                    maxx = target;
                    break;
                }
            }
        }
        return maxx;
    }
};

// Trie
class TrieNode
{
public:
    TrieNode *children[2];
    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *head = new TrieNode();
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            TrieNode *curr = head;
            for (int bit = 31; bit >= 0; --bit)
            {
                if ((num >> bit) & 1)
                {
                    if (!curr->children[1])
                    {
                        curr->children[1] = new TrieNode();
                    }
                    curr = curr->children[1];
                }
                else
                {
                    if (!curr->children[0])
                    {
                        curr->children[0] = new TrieNode();
                    }
                    curr = curr->children[0];
                }
            }
        }

        int maxx = 0;
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            TrieNode *curr = head;
            int toXor = 0;
            for (int bit = 31; bit >= 0; --bit)
            {
                if ((num >> bit) & 1)
                {
                    if (!curr->children[0])
                    {
                        curr = curr->children[1];
                        toXor |= (1 << bit);
                    }
                    else
                    {
                        curr = curr->children[0];
                    }
                }
                else
                {
                    if (!curr->children[1])
                    {
                        curr = curr->children[0];
                    }
                    else
                    {
                        curr = curr->children[1];
                        toXor |= (1 << bit);
                    }
                }
            }
            maxx = max(toXor ^ num, maxx);
        }
        return maxx;
    }
};
