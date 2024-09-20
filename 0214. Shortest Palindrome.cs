public class Solution
{
    public string ShortestPalindrome(string str)
    {
        var reverseStr = new string(str.Reverse().ToArray());

        for (int i = 0; i < str.Length; ++i)
        {
            if (str[..^i] == reverseStr[i..])
            {
                return reverseStr[..i] + str;
            }
        }

        return reverseStr + str;
    }
}