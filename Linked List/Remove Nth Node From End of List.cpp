// Approach - 1
// Time Complexity: O(n+n)
// Space Complexity: O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *temp1 = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        count = count - n + 1;
        ListNode *prev = NULL;
        while (--count)
        {
            prev = temp1;
            temp1 = temp1->next;
        }
        if (prev && prev->next)
        {
            prev->next = prev->next->next;
            return head;
        }
        else
        {
            return head->next;
        }
    }
};

// Approach - 2
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *newhead = new ListNode();
        newhead->next = head;
        ListNode *slow = newhead;
        ListNode *fast = newhead;
        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow && slow->next)
        {
            slow->next = slow->next->next;
        }
        return newhead->next;
    }
};