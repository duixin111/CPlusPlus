/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool dfs(TreeNode* root, int sum, int cur)
    {
        if(!root)
            return false;
        cur += root->val;
        if(!root->left && !root->right && sum == cur)
            return true;
        return dfs(root->left, sum, cur) || dfs(root->right, sum, cur);
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(!root)
            return false;
        return dfs(root, sum, 0);
    }
};
