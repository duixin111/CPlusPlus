/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        ListNode* fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == nullptr)
            slow = slow->next;
        slow = reverse(slow);
        fast = head;
        while(slow != nullptr)
        {
            if(slow->val == fast->val)
            {
                slow = slow->next;
                fast = fast->next;
            }
            else
                return false;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        while(head != nullptr)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};
