//Almost (given just node value, instead of node) same as min time to burn a tree/

//1. Brute 1 - graph
//2. Brute 2 - store parent
//3. Optimal - One pass - modified height function.

//Brute approach 1: make a graph (map of int, set of int) and do bfs
//Brute 2: store parents of nodes and do bfs
//TC: O(N)
//SC: O(N)
class Solution {
public:
    
    TreeNode* storeParentandFindStart(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start)
    {
        TreeNode* startNode = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->val == start)
                startNode = node;
            
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
        return startNode;
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = storeParentandFindStart(root, parent, start);
        
        unordered_map<TreeNode*, bool> visited;
        
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;
        
        int level = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && visited[node->left] == false)
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && visited[node->right] == false)
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent.find(node) != parent.end() && visited[parent[node]] == false)
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            
            level++;
        }
        
        return (level - 1);
    }
};

//Optimal
//one-pass DFS
//TC: O(N)
//SC: O(N)
//We know timne take to burn/infect would be max of (dist of leaf node going from top of start , height of start)
//So we can use height function.
//1. If we encounter start, we can store the height of start in a variable (ans), and should only return 1. However, instead of keep a visited variable for start, we can return -1.
//2. Hence, if both heights are non-negative, that means start hasn't been found and we will simply return the height.
//3. if either height is negative, that means start start has been found, so, distance of leaf node from start will be |lh| + |rh| (hence, update ans = max(ans, dist) as well),
  // and we are interested in returning the distance of the node from start, hence, we will return -(|negative height| + 1) = min(lh,rh) - 1
lass Solution {
public:
    int findDepth(TreeNode* root, int& ans, int start)
    {
        if(root == NULL)
            return 0;
        
        int lh = findDepth(root->left, ans, start);
        int rh = findDepth(root->right, ans, start);
        
        if(root->val == start) //find height of start, return only start
        {
            ans = max(lh, rh);
            return -1; //negative to show that start has been visited, magnitude should be 1
        }
        
        else if(lh >= 0 && rh >= 0) //branch which doesn't contain start
        {
            return 1 + max(lh, rh);
        }
        
        else
        {
            int dist = abs(lh) + abs(rh); //whichever will be negative
            ans = max(ans, dist);
            
            //return height from start => |negative one| + 1
            return min(lh, rh) - 1;
        }
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        findDepth(root, ans, start);
        return ans; 
    }
};


