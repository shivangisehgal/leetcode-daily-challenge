//Pretty straight-forward

class Solution {
public:
    
    void rec(TreeNode* root, int& sum, int low, int high)
    {
        if(root == NULL)
            return;
        
        if(root->val < low)
            rec(root->right, sum, low, high);
        
        else if(root->val > high)
            rec(root->left, sum, low, high);
        
        else
        {
            sum += root->val;
            rec(root->left, sum, low, high);
            rec(root->right, sum, low, high);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        rec(root, sum, low, high);
        return sum;
    }
};
