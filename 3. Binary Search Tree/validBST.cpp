// https://www.codingninjas.com/studio/problems/validate-bst_799483

/*
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

// Approach 2
bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    //base case
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        if(left && right)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    bool ans = isBST(root, INT_MIN, INT_MAX);

    return ans;
}