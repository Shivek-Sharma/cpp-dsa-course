// https://practice.geeksforgeeks.org/problems/sum-tree/1

/*
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *root)
    {
        // base cases
        if (root == NULL)
        {
            pair<bool, int> p(true, 0);
            return p;
        }

        if (root->left == NULL && root->right == NULL)
        {
            // leaf node
            pair<bool, int> p(true, root->data);
            return p;
        }

        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool isSum = left.second + right.second == root->data;

        pair<bool, int> ans;

        if (leftAns && rightAns && isSum)
            ans.first = true;
        else
            ans.first = false;

        ans.second = root->data + left.second + right.second;

        return ans;
    }

    bool isSumTree(Node *root)
    {
        bool ans = isSumTreeFast(root).first;
        return ans;
    }
};