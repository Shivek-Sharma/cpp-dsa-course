// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Approach 1 (Brute force)
class Solution
{
    int height(Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0;
        }

        // height of left subtree
        int left = height(node->left);

        // height of right subtree
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && diff)
            return true;
        else
            return false;
    }
};

// Approach 2 (Optimized)
class Solution
{
public:
    pair<bool, int> isBalancedFast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p(true, 0);
            return p;
        }

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;

        if (leftAns && rightAns && diff)
            ans.first = true;
        else
            ans.first = false;

        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        int ans = isBalancedFast(root).first;
        return ans;
    }
};