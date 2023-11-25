// https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472

/*
template <typename T>
class TreeNode
{
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
};
*/

void inorderTraverse(TreeNode<int> *root, vector<int> &inorder)
{
    // base case
    if (root == NULL)
        return;

    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> inorder)
{
    // base case
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    TreeNode<int> *newRoot = new TreeNode<int>(inorder[mid]);

    newRoot->left = inorderToBST(s, mid - 1, inorder);
    newRoot->right = inorderToBST(mid + 1, e, inorder);

    return newRoot;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorder;
    inorderTraverse(root, inorder);
    int size = inorder.size();

    return inorderToBST(0, size - 1, inorder);
}