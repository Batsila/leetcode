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
    public bool IsSymmetric(TreeNode root) 
    {
        return IsSymmetric(root?.left, root?.right);
    }
    
    bool IsSymmetric(TreeNode l, TreeNode r)
    {
        if (l == null && r == null)
        {
            return true;
        }
        
        if (l?.val != r?.val)
        {
            return false;
        }
        
        return IsSymmetric(l.right, r.left) && IsSymmetric(l.left, r.right);
    }
}