// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* current = root;
        
	    while (current != NULL) {
	        
    		if (current->left != NULL) {
    			//find the inorder predecessor of current 
    			Node* pre = current->left;
    			while (pre->right != NULL)
    				pre = pre->right;
    
    			//when pre->right == NULL i.e. inorder predecessor found
    			pre->right = current->right;
    			current->right = current->left;
    			current->left = NULL;
    		} 
    		
    		current = current->right;
	    }
    }
};