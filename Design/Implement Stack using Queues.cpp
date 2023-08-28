// Approach - 1
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        while (q1.size() > 0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (q2.size() > 0)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int element = q1.front();
        q1.pop();
        return element;
    }

    int top()
    {
        int element = q1.front();
        return element;
    }

    bool empty()
    {
        return q1.empty();
    }
};

// Approach - 2
class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        if (q.empty())
        {
            q.push(x);
        }
        else
        {
            int n = q.size();
            q.push(x);
            while (n--)
            {
                q.push(q.front());
                q.pop();
            }
        }
    }

    int pop()
    {
        int element = q.front();
        q.pop();
        return element;
    }

    int top()
    {
        int element = q.front();
        return element;
    }

    bool empty()
    {
        return q.empty();
    }
};