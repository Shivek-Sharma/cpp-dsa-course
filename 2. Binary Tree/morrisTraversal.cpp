// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode
{
    int data;
    struct tNode* left;
    struct tNode* right;

    tNode(int x){
        data = x;
        left = right = NULL;
    }
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
	struct tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Temporary link creation by making current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}

			/* Temporary link removal by fixing the right
			child of predecessor */
			else { // pre->right == current
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			} 
		} 
	} 
}

/* Driver program to test above functions*/
int main()
{
	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
  */
	struct tNode* root = new tNode(1);
	
	root->left = new tNode(2);
	root->right = new tNode(3);
	root->left->left = new tNode(4);
	root->left->right = new tNode(5);

	MorrisTraversal(root);

	return 0;
}