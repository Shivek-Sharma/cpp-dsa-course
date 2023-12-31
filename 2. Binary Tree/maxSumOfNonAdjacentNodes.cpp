// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    pair<int, int> solve(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;

        // max sum including nodes in current level
        res.first = root->data + left.second + right.second;

        // max sum excluding nodes in current level
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }

    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};