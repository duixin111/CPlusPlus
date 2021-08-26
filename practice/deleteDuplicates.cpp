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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* tmp = new ListNode(-1);
        tmp->next = head;
        ListNode* cur = tmp;
        while(cur->next && cur->next->next)
        {
            if(cur->next->val == cur->next->next->val)
            {
                int f = cur->next->val;
                while(cur->next && cur->next->val == f)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        
        return tmp->next;
    }
};
