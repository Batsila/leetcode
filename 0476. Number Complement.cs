public class Solution
{
    public int FindComplement(int num)
    {
        if (num != 0)
        {
            var ind = 31;

            while ((num >> ind & 1) != 1)
            {
                --ind;
            }

            while (ind >= 0)
            {
                num ^= 1 << ind;
                --ind;
            }
    
            return num;
        }
        else
        {
            return 1;
        }
    }
}