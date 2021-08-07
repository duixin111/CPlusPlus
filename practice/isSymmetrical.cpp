/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return check(pRoot, pRoot);
    }
    bool check(TreeNode* a, TreeNode* b)
    {
        if(a == nullptr && b == nullptr)
            return true;
        if(a == nullptr || b == nullptr)
            return false;
        if(a->val != b->val)
            return false;
        else
            return check(a->left,b->right) && check(a->right, b->left);
            
    }

};
