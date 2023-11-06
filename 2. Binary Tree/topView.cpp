// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> topNode;
        queue<pair<Node *, int>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *frontNode = temp.first;
            int horizontalDist = temp.second;

            // if one value is present for a horizontalDist, then do nothing (1:1 mapping)
            if (topNode.find(horizontalDist) == topNode.end())
                topNode[horizontalDist] = frontNode->data;

            if (frontNode->left)
                q.push(make_pair(frontNode->left, horizontalDist - 1));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, horizontalDist + 1));
        }

        for (auto i : topNode)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};