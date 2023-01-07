/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        // sorted array from tree 1
        vector<int> arr1;
        f(arr1, root1);
        // sorted array from tree2
        vector<int> arr2;
        f(arr2, root2);
        // merge two sorted array and return ;
        return f(arr1, arr2);
    }
    void f(vector<int> &v, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        f(v, root->left);
        v.push_back(root->val);
        f(v, root->right);
    }
    vector<int> f(vector<int> &v1, vector<int> &v2)
    {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] <= v2[j])
            {
                ans.push_back(v1[i++]);
            }
            else
            {
                ans.push_back(v2[j++]);
            }
        }
        while (i < v1.size())
        {
            ans.push_back(v1[i++]);
        }
        while (j < v2.size())
        {
            ans.push_back(v2[j++]);
        }
        return ans;
    }
};