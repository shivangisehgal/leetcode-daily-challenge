//Pretty straightforward

//Better approach: use a string to store the node values, separated by '#', ',' or etc.

class Solution {
public:
    
    void storeLeaf(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            v.push_back(root->val);
            return;
        }
        
        storeLeaf(root->left, v);
        storeLeaf(root->right, v);
    }
    
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        
        storeLeaf(root1, v1);
        storeLeaf(root2, v2);
        
        return v1 == v2;
    }
};
