// https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631

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
};
*/

void inorderTraverse(BinaryTreeNode<int>* root, vector<int> &inorder) {
    //base case
    if(root == NULL)
        return;

    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorder;

    inorderTraverse(root, inorder);

    int i = 0, j = inorder.size()-1;

    while(i < j) {
        if(inorder[i] + inorder[j] == target)
            return true;

        else if(inorder[i] + inorder[j] > target)
            j--;

        else i++;
    }

    return false;
}