// https://www.codingninjas.com/studio/problems/_893049

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

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    int successor = -1;

    TreeNode *temp = root;

    while (temp != NULL)
    {
        if (key > temp->data)
        {
            // updating predecessor with each iteration
            predecessor = temp->data;
            temp = temp->right; //to get max value
        }
        else 
        {   // left subtree
            temp = temp->left;
        }
    }

    temp = root;

    while (temp != NULL)
    {
        if (key >= temp->data)
        {   
            // right subtree
            temp = temp->right;
        }
        else
        {   
            // updating successor with each iteration
            successor = temp->data;
            temp = temp->left; //to get min value
        }
    }

    return make_pair(predecessor, successor);
}