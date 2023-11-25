// https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111

/*
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
};
*/

// Approach 2
BinaryTreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    // base cases
    if (i >= preorder.size())
        return NULL;

    // out of range
    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    // in range
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i]);
    i++;

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;

    return solve(preorder, mini, maxi, index);
}

// without using mini
BinaryTreeNode<int> *solve(vector<int> &preorder, int maxi, int &i)
{
    // base cases
    if (i >= preorder.size())
        return NULL;

    // out of range
    if (preorder[i] > maxi)
        return NULL;

    // in range
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i]);
    i++;

    root->left = solve(preorder, root->data, i);
    root->right = solve(preorder, maxi, i);

    return root;
}