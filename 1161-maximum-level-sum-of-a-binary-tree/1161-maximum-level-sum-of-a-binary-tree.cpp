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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxLevel = 0 ; 
        int level = 0 ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sum = 0 ; 
            int n = q.size();
            while(n>0){
                TreeNode *node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                n--;
            }
            if(sum>maxSum){
                maxSum = sum;
                maxLevel = level;
            }
                
        }
        return maxLevel;
        
        
    }
};