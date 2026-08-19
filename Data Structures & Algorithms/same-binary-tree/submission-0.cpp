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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        pq.push(p);
        qq.push(q);
        while(!pq.empty() && !qq.empty()){
            TreeNode* curp = pq.front(); pq.pop();
            TreeNode* curq = qq.front(); qq.pop();
            // Val check if it exists;
            if(!curp && !curq){
                continue;
            }
            if(!curp || !curq || curp->val != curq->val){
                return false;
            }
            pq.push(curp->left);
            pq.push(curp->right);
            qq.push(curq->left);
            qq.push(curq->right);
        }
        return true;
    }
};
