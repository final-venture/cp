/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string encoded = "";
        encode(root, encoded);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int idx = 0;
        return decode(data, idx);
    }

    TreeNode *decode(string &encoded, int &idx)
    {
        if (idx >= encoded.length())
            return nullptr;
        if (encoded[idx] == 'n')
        {
            idx += 2;
            return nullptr;
        }
        string numstr = "";
        while (idx < encoded.length() && encoded[idx] != ',')
        {
            numstr += encoded[idx++];
        }
        ++idx;

        TreeNode *node = new TreeNode(stoi(numstr));
        node->left = decode(encoded, idx);
        node->right = decode(encoded, idx);
        return node;
    }

    void encode(TreeNode *node, string &encoded)
    {
        if (!node)
        {
            encoded += "n,";
            return;
        }
        encoded += (to_string(node->val) + ',');
        encode(node->left, encoded);
        encode(node->right, encoded);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));