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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<int> pre;
    vector<int> mid;
    vector<int> post;
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        if(root != nullptr)
        {
            preorder(root);
            midorder(root);
            postorder(root);
        }
        vector<vector<int>> res = {pre, mid, post};
        return res;
    }
    vector<int> preorder(TreeNode* root)
    {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            pre.push_back(tmp->val);
            s.pop();
            if(tmp->right)
                s.push(tmp->right);
            if(tmp->left)
                s.push(tmp->left);
        }
        return pre;
    }
    vector<int> midorder(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp)
        {
            while(tmp)
            {
                s.push(tmp);
                tmp = tmp->left;
            }
            if(!s.empty())
            {
                tmp = s.top();
                mid.push_back(tmp->val);
                s.pop();
                tmp = tmp->right;
            }
            
        }
        return mid;
    }
    vector<int> postorder(TreeNode* root)
    {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            post.push_back(tmp->val);
            s.pop();
            if(tmp->left)
                s.push(tmp->left);
            if(tmp->right)
                s.push(tmp->right);
        }
        reverse(post.begin(), post.end());
        return post;
    }
};
