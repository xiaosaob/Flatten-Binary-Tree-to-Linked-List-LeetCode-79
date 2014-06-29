// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// click to show hints.

// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        TreeNode *cur = root;
        while(cur) {
            TreeNode *right = cur->right;
            if(cur->left) {
                TreeNode *tmp = cur->left;
                while(tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
