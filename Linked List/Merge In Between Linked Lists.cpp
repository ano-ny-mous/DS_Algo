// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head = list1;
        for (int i = 1; i < a && list1 != NULL; i++)
        {
            list1 = list1->next;
        }
        ListNode *skipHead = list1;
        for (int i = a; i <= b + 1 && list1 != NULL; i++)
        {
            list1 = list1->next;
        }
        skipHead->next = list2;
        while (list2->next != NULL)
        {
            list2 = list2->next;
        }
        list2->next = list1;
        return head;
    }
};