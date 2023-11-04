// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

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
class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
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
};