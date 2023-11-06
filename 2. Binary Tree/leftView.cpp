// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

void solve(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // jumped to next level for the first time
    if (level == ans.size())
        ans.push_back(root->data);

    // left to right traversal on each level
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;

    solve(root, ans, 0);

    return ans;
}