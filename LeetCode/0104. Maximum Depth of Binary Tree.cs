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
    private int maxDepth;
    
    public int MaxDepth(TreeNode root) 
    {
        Dfs(root, 0);
        
        return maxDepth;
    }
    
    public void Dfs(TreeNode node, int depth)
    {
        if (node == null)
        {
            return;
        }
        
        ++depth;
        maxDepth = Math.Max(maxDepth, depth);
        
        Dfs(node.left, depth);
        Dfs(node.right, depth);
    }
}