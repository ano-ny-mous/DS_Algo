// Approach - 1
// Time Complexity: O(n) + O(n/2)
// Space Complexity: O(n)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> checkpal;
        while (head)
        {
            checkpal.push_back(head->val);
            head = head->next;
        }
        int n = checkpal.size();
        for (int i = 0, j = n - 1; i < n / 2; i++, j--)
        {
            if (checkpal[i] != checkpal[j])
            {
                return false;
            }
        }
        return true;
    }
};

// Approach - 2
// Time Complexity: O(n/2) + O(n/2) + O(n/2)
// Space Complexity: O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nxt;
        while (cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = middleNode(head);
        ListNode *rev = reverseList(mid);
        while (head && rev)
        {
            if (head->val != rev->val)
            {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};