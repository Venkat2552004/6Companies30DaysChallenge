// Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Goldman Sachs | Day - 4 | Problem - 3

int ans;
class Sol{
public:
    int sum;
    int minn;
    int maxx;
    bool isBST;
    
    Sol (){
        sum = 0;
        minn = INT_MAX;
        maxx = INT_MIN;
        isBST = true;
    }
};

class Solution {
public:
    Sol solve(TreeNode* root){
        if(root == NULL)
            return Sol();
        
        Sol curr;
        Sol lt = solve(root->left);
        Sol rt = solve(root->right);

        if(lt.isBST and rt.isBST and root->val > lt.maxx and root->val < rt.minn){
            curr.sum = lt.sum + root->val + rt.sum;
            curr.minn = min(lt.minn, root->val);
            curr.maxx = max( root->val, rt.maxx);
        }
        else
            curr.isBST = false;

        if(curr.isBST)
            ans = max(ans, curr.sum);
        return curr;
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
