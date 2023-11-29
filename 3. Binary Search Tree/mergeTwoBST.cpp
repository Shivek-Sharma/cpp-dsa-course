// https://www.codingninjas.com/studio/problems/h_920474

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

// Problem 1
void inorderTraverse(TreeNode *root, vector<int> &inorder)
{
    // base case
    if (root == NULL)
        return;

    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> inorder1, inorder2, inorder3;

    inorderTraverse(root1, inorder1);
    inorderTraverse(root2, inorder2);

    int i = 0, j = 0;

    while (i < inorder1.size() && j < inorder2.size())
    {
        if (inorder1[i] > inorder2[j])
            inorder3.push_back(inorder2[j++]);
        else
            inorder3.push_back(inorder1[i++]);
    }

    while (i < inorder1.size())
        inorder3.push_back(inorder1[i++]);

    while (j < inorder2.size())
        inorder3.push_back(inorder2[j++]);

    return inorder3;
}

// Problem 2
void convertIntoSortedDLL(TreeNode *root, TreeNode *&head)
{
    // base case
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode *mergeSortedDLL(TreeNode *head1, TreeNode *head2)
{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            { // first insertion
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            { // insertion at tail
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            { // first insertion
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            { // insertion at tail
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode *head)
{
    int cnt = 0;
    TreeNode *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode *mergedDLLToBST(TreeNode *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    TreeNode *left = mergedDLLToBST(head, n / 2);

    TreeNode *root = head;
    root->left = left;

    head = head->right;

    TreeNode *right = mergedDLLToBST(head, n - n / 2 - 1);
    root->right = right;

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    // step 1: convert both BST to sorted doubly linked list in-place
    TreeNode *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // step 2: merge 2 sorted doubly linked lists in sorted order
    TreeNode *head3 = mergeSortedDLL(head1, head2);

    // step 3: convert merged sorted doubly linked list to BST
    int nodeCount = countNodes(head3);
    return mergedDLLToBST(head3, nodeCount);
}