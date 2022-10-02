/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution 
{
    private Dictionary<int, int> _inorderDict;
    private int[] _postorder;
    private int _postorderI;
    
    public TreeNode BuildTree(int[] inorder, int[] postorder) 
    {
        _inorderDict = new Dictionary<int, int>();
        for (int i = 0; i < inorder.Count(); ++i)
        {
            _inorderDict.Add(inorder[i], i);
        }
        _postorder = postorder;
        _postorderI = inorder.Count() - 1;
        
        return Help(0, _postorderI);
    }
    
    public TreeNode Help(int start, int end)
    {
        if (start < 0 || start > end || _postorderI < 0)
        {
            return null;
        }
        
        var node = new TreeNode(_postorder[_postorderI]);
        --_postorderI;
        
        var inorderI = _inorderDict[node.val];
        
        node.right = Help(inorderI + 1, end);
        node.left = Help(start, inorderI - 1);
        
        return node;
    }
}