/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr && pHead2 == nullptr)
            return pHead2;
        ListNode* newHead = new ListNode(-1);
        ListNode* cur = newHead;
        while(pHead1 && pHead2)
        {
            if(pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if(pHead1)
            cur->next = pHead1;
        else if(pHead2)
            cur->next = pHead2;
        ListNode* ret = newHead->next;
        delete newHead;
        return ret;
    }
};
