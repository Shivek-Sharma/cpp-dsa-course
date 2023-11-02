// https://practice.geeksforgeeks.org/problems/queue-reversal/1

// Approach 1 (using stack)
queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

// Approach 2 (using recursion)
void reverse(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    int value = q.front();
    q.pop();

    // recursive call
    reverse(q);

    q.push(value);
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}