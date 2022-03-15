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
        int maxLevel = 0 ; 
        int maxSum = INT_MIN;
        int level = 0 ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curr_sum = 0;
            ++level;
            int n = q.size();
            for(int i = n ; i>0 ; i--){
                TreeNode* temp = q.front();
                q.pop();
                curr_sum+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(curr_sum>maxSum){
                maxSum = curr_sum;
                maxLevel = level;
            }
            
            
            
        }
        return maxLevel;
        
    }
};