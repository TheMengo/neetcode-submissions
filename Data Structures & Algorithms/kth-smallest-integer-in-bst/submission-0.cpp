/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> dfs;
        TreeNode* curr = root;

        while(!dfs.empty() || curr != nullptr){
            while(curr != nullptr){
                dfs.push(curr);
                curr = curr->left;
            }
            curr = dfs.top();
            dfs.pop();
            k--;
            if(k == 0){
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
        
    }
};
