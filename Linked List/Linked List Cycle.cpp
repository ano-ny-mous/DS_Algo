// Approach - 1
// Time Complexity: O(n*2)
// Space Complexity: O(n)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> nodes;
        while (head)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] == head)
                {
                    return true;
                }
            }
            nodes.push_back(head);
            head = head->next;
        }
        return false;
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> s;
        while (head)
        {
            if (s.find(head) != s.end())
            {
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Approach - 3
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        if (fast && fast->next)
        {
            fast = fast->next;
        }
        while (slow && fast && fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};