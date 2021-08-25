class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* Head =new ListNode(0);
        Head->next =head;
        ListNode* p=Head;//开始的双指针都指向头节点
        ListNode* q=Head;
        for( int i=0;i<n+1;i ++ ){
            q=q->next;//q指针指向第n-1个节点
        }
        while(q){
            p=p->next;
            q=q->next;
        }
        ListNode* delNode=p->next;
        p->next=delNode->next;
        delete delNode;//删除多于结点

        ListNode* retNode=Head->next;
        delete Head;//删除多余节点
        return retNode;

    }
};
