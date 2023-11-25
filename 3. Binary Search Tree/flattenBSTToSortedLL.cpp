// https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459

/*
template <typename T>
class TreeNode {
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
            if(left)
                delete left;
            if(right)
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

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorder;
    inorderTraverse(root, inorder);
    int size = inorder.size();

    TreeNode<int> *newRoot = new TreeNode<int>(inorder[0]);

    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < size; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorder[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // last node
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}