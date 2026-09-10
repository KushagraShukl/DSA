class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, k, count);
    }

private:
    int inorder(TreeNode* root, int k, int& count) {
        if (root == nullptr)
            return -1;

        int left = inorder(root->left, k, count);

        if (left != -1)
            return left;

        count++;

        if (count == k)
            return root->val;

        return inorder(root->right, k, count);
    }
};