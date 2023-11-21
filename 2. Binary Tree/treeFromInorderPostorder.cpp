// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

/* Tree node structure
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

int findposition(int in[], int inOrderStart, int inOrderEnd, int element, int n)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // create root node from postorder
    int element = post[index--]; // at every iteration index is decreasing
    Node *root = new Node(element);

    // find element's index in inorder
    int position = findposition(in, inOrderStart, inOrderEnd, element, size);

    // recursive calls (we first build right subtree in postorder)
    root->right = solve(in, post, index, position + 1, inOrderEnd, size);
    root->left = solve(in, post, index, inOrderStart, position - 1, size);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    // postorder is LRN, so last element is root
    int postOrderIndex = n - 1;

    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);

    return ans;
}