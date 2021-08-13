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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        ListNode* newHead = nullptr;
        while(cur)
        {
            newHead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = newHead;
        }
        
        return prev;
    }
};
