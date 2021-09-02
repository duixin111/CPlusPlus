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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* a = pHead1, *b = pHead2;
        while(a != b)
        {
            a = a ? a->next : pHead2;
            b = b ? b->next : pHead1;
        }
        
        return a;
    }
};
