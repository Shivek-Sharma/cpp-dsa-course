// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();

            Node *firstNode = temp.first;
            int horizontalDist = temp.second.first;
            int level = temp.second.second;

            nodes[horizontalDist][level].push_back(firstNode->data);

            if (firstNode->left)
                q.push(make_pair(firstNode->left, make_pair(horizontalDist - 1, level + 1)));

            if (firstNode->right)
                q.push(make_pair(firstNode->right, make_pair(horizontalDist + 1, level + 1)));
        }

        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }

        return ans;
    }
};

// less complex solution (no need to track level)
class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, vector<int>> nodes;
        queue<pair<Node *, int>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *firstNode = temp.first;
            int horizontalDist = temp.second;

            nodes[horizontalDist].push_back(firstNode->data);

            if (firstNode->left)
                q.push(make_pair(firstNode->left, horizontalDist - 1));

            if (firstNode->right)
                q.push(make_pair(firstNode->right, horizontalDist + 1));
        }

        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }

        return ans;
    }
};