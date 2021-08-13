/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode* left = pHead, *right = pHead;
        while(k--)
        {
            if(right == nullptr)
            {
                return nullptr;
            }
            right = right->next;
        }
        while(right)
        {
            left = left->next;
            right = right->next;
        }
        return left;
        
    }
};
