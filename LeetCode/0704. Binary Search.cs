public class Solution 
{
    public int Search(int[] nums, int target) 
    {
        var l = 0;
        var r = nums.Count() - 1;
        
        while (l <= r)
        {
            var c = l + (r - l) / 2;
            
            if (target == nums[c])
            {
                return c;
            }
            
            if (target < nums[c])
            {
                r = c - 1;
            }
            else
            {
                l = c + 1;
            }
        }
        
        return -1;
    }
}