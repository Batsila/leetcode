public class Solution
{
    public int CountTriplets(int[] arr)
    {
        var prefixXor = new List<int>() { 0 };
        prefixXor.AddRange(arr);

        for (int i = 1; i < prefixXor.Count; ++i)
        {
            prefixXor[i] ^= prefixXor[i - 1];
        }

        var result = 0;

        for (int i = 0; i < prefixXor.Count; ++i)
        {
            for (int j = i + 1; j < prefixXor.Count; ++j)
            {
                if (prefixXor[i] == prefixXor[j])
                {
                    result += j - i - 1;
                }
            }
        }

        return result; 
    }
}