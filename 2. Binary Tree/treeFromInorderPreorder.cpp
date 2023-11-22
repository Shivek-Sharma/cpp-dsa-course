// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

/*
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution
{
public:
    int findPosition(int in[], int inOrderStart, int inOrderEnd, int element)
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

    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int size)
    {
        // base case
        if (index >= size || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        // create root node from preorder
        int element = pre[index++]; // at every iteration index is increasing
        Node *root = new Node(element);

        // find element's index in inorder
        int position = findPosition(in, inOrderStart, inOrderEnd, element);

        // recursive calls
        root->left = solve(in, pre, index, inOrderStart, position - 1, size);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, size);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // preorder is NLR, so first element is root
        int preOrderIndex = 0;

        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);

        return ans;
    }
};