// https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333

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

int solve(BinaryTreeNode<int>* root, int &i, int k) {
    //base case
    if(root == NULL)
        return -1;

    //L
    int left = solve(root->left, i, k);
    if(left != -1)
        return left;

    //N
    i++;
    if(i == k)
        return root->data;

    //R
    int right = solve(root->right, i, k);
    return right;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;

    int ans = solve(root, i, k);

    return ans;
}