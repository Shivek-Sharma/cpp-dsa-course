// https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103

/*
class TreeNode
{
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
*/

class Info {
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

Info solve(TreeNode *root, int &maxSize) {
    //base case
    if(root == NULL) {
        return {INT_MAX, INT_MIN, true, 0};
    }

    Info left = solve(root->left, maxSize);
    Info right = solve(root->right, maxSize);

    Info currNode;

    //updating info of current node
    currNode.size = left.size + right.size + 1;
    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);

    //check if current node is BST or not
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    //update maxSize
    if(currNode.isBST) {
        maxSize = max(maxSize, currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode * root){
    int maxSize = 0;

    Info temp = solve(root, maxSize);

    return maxSize;
}