// Reference:
//  https://youtu.be/DpkTu2tU87o?t=580
#include "tree_node.h"

using namespace std;

class InsertTreeNodeIntoBST
{
public:
    TreeNode *Insert(TreeNode *root, int target)
    {
        if (!root)
        {
            root = new TreeNode(target);
            return root;
        }

        const int kVal = root->val;
        if (target < kVal)
            root->left = Insert(root->left, target);
        else if (target > kVal)
            root->right = Insert(root->right, target);
        else
            root;
    }
};