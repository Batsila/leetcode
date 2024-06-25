/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    private int sum = 0;

    public TreeNode BstToGst(TreeNode root)
    {
        UpdateTree(root);

        return root;
    }

    private void UpdateTree(TreeNode node)
    {
        if (node != null)
        {
            UpdateTree(node.right);
            sum += node.val;
            node.val = sum;
            UpdateTree(node.left);
        }
    }
}