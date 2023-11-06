// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{   
    vector<int> ans;
    queue<Node*> q;
    
    q.push(root);
    
    while (!q.empty())
    {
        Node* frontNode = q.front();
        q.pop();
        
        while (frontNode)
        {
            if(frontNode->left) 
                q.push(frontNode->left);
            
            ans.push_back(frontNode->data); 
            
            // Move to the right child of the current node
            frontNode = frontNode->right; 
        }
    }
    return ans; 
}