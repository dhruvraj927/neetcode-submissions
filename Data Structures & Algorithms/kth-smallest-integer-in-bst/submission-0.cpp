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
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int size = q.size();

           for(int i=0;i<size;i++){

            TreeNode* t=q.front();
            q.pop();
            pq.push(t->val);
            if(pq.size()>k) pq.pop();
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
           }
        }
        return pq.top();

        
    }
};
