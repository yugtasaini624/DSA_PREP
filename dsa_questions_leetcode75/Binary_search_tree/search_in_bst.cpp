/*
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []

Constraints:
    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 107
    root is a binary search tree.
    1 <= val <= 107
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
    TreeNode* search(TreeNode *root, int val){
        if(root == nullptr) return root;

        if(root->val == val) return root;
        else if(root->val > val) return search(root->left, val);
        else return search(root->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;

        return search(root, val);
    }
};

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);

    Solution s;
    int val=2;

    TreeNode* result=s.searchBST(root,val);

    if(result!=nullptr){
        cout<<result->val<<endl;
    }
    else{
        cout<<"Value not found"<<endl;
    }

    return 0;
}
