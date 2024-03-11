// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> arr;
        while (head)
        {
            arr.push_back(head);
            head = head->next;
        }
        return arr[arr.size() / 2];
    }
};

// Approach - 2
// Time Complexity: O(n) + O(n/2)
// Space Complexity: O(1)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        count = count / 2;
        while (head && count--)
        {
            head = head->next;
        }
        return head;
    }
};

// Approach - 3
// Time Complexity: O(n/2)
// Space Complexity: O(1)
class Solution
{
public:
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
};