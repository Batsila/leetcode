public class Solution
{
    public int MinOperations(string[] logs)
    {
        var result = 0;

        foreach (var log in logs)
        {
            if (log == "../")
            {
                if (result > 0)
                {
                    --result;
                }
            }
            else if (log != "./")
            {
                ++result;
            }
        }
        
        return result;
    }
}