// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

queue<int> modifyQueue(queue<int> q, int k)
{
    // step1: pop first k elements from queue and push to stack
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step2: pop from stack and push to queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step3: pop first (n-k) elements from queue and push to queue
    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}