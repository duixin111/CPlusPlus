/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if(pRoot == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        q.push(pRoot);
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* l = q.front()->left;
                TreeNode* r = q.front()->right;
                if(l)
                    q.push(l);
                if(r)
                    q.push(r);
                q.front()->left = r;
                q.front()->right = l;
                q.pop();
            }
        }
        
        return pRoot;
    }
};
