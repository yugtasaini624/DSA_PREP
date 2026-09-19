/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 104].
    0 <= Node.val <= 105

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *prev = nullptr;

    void helper(TreeNode *root, int &minVal) {
        if (root == nullptr) return;

        if (root->left) {
            helper(root->left, minVal);
        }

        if (prev) {
            minVal = min(minVal, abs(root->val - prev->val));
        }

        prev = root;

        if (root->right) {
            helper(root->right, minVal);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        int minVal = INT_MAX;
        helper(root, minVal);
        return minVal;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    cout << "Minimum Difference: "
         << obj.getMinimumDifference(root) << endl;

    return 0;
}