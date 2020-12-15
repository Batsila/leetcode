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
    private List<int> list;
        
    public TreeNode BalanceBST(TreeNode root) 
    {
        list = new List<int>();
        
        Dfs(root);
        
        return CreateBalancedBST(0, list.Count() - 1);
    }
    
    public TreeNode CreateBalancedBST(int l, int r)
    {
        if (r < l)
        {
            return null;
        }
        
        int c = (r + l) / 2;
        
        var ln = CreateBalancedBST(l, c - 1);
        var rn = CreateBalancedBST(c + 1, r);
        
        return new TreeNode(list[c], ln, rn);
    }
    
    public void Dfs(TreeNode node)
    {
        if (node == null)
        {
            return;
        }
        
        Dfs(node.left);
        list.Add(node.val);
        Dfs(node.right);
    }
}