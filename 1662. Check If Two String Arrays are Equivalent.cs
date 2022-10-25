public class Solution 
{
    public bool ArrayStringsAreEqual(string[] word1, string[] word2) 
    {
        return word1.Aggregate((x, y) => x + y) == word2.Aggregate((x, y) => x + y);
    }
}