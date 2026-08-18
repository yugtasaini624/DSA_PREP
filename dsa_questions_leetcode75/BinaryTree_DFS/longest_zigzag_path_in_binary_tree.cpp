/*
You are given the root of a binary tree.
A ZigZag path for a binary tree is defined as follow:

    Choose any node in the binary tree and a direction (right or left).
    If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
    Change the direction from right to left or from left to right.
    Repeat the second and third steps until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0

Constraints:
    The number of nodes in the tree is in the range [1, 5 * 104].
    1 <= Node.val <= 100
*/

#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *root, bool leftTrue, int len, int &ans){
        if(!root) return;

        ans = max(ans, len);

        if(leftTrue){
            dfs(root->left, false, len + 1, ans);
            dfs(root->right, true, 1, ans);
        } else{
            dfs(root->right, true, len + 1, ans);
            dfs(root->left, false, 1, ans);
        }   
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;

        dfs(root, true, 0, ans);
        dfs(root, false, 0, ans);

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    root->left->left->right = new TreeNode(6);

    Solution obj;

    cout<<"Longest ZigZag Path: "<<obj.longestZigZag(root)<<endl;

    return 0;
}