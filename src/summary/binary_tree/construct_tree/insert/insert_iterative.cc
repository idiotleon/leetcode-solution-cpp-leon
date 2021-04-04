// Reference:
//  https://youtu.be/DpkTu2tU87o?t=580
#include "tree_node.h"

class InsertTreeNodeIntoBST
{
public:
    TreeNode *Insert(TreeNode *root, int target)
    {
        TreeNode *cur = root;
        TreeNode *newNode = new TreeNode(target);
        if (!cur)
        {
            cur = newNode;
            return cur;
        }

        TreeNode *prev = nullptr;
        while (cur)
        {
            prev = cur;
            if (cur->val < target)
                cur = cur->right;
            else
                cur = cur->left;
        }

        if (prev->val < target)
            prev->right = newNode;
        else
            prev->left = newNode;

        return root;
    }
};