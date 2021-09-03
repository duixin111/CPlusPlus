class Solution {
public:
    ListNode *partition(ListNode *head, int x)
    {
        if(head == NULL) return head;
        ListNode* less = new ListNode(-1);
        ListNode* more = new ListNode(-1);
        ListNode* head1 = less;
        ListNode* head2 = more;
        ListNode* pNode = head;
        while(pNode != NULL)
        {
            if(pNode->val < x)
            {
                head1->next = pNode;
                head1 = head1->next;
            }
            else
            {
                head2->next = pNode;
                head2 = head2->next;
            }
            pNode = pNode->next;
        }
        head2->next = NULL;
        head1->next = more->next;
        return less->next;
    }
};
