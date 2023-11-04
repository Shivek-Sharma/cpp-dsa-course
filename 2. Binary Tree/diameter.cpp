// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

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
}; */

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
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);

        int op3 = height(root->left) + height(root->right) + 1;

        int ans = max(max(op1, op2), op3);
        return ans;
    }
};

// Approach 2 (Optimized)
class Solution
{
public:
    pair<int, int> diameterFast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p(0, 0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;

        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(max(op1, op2), op3);
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        int ans = diameterFast(root).first;
        return ans;
    }
};