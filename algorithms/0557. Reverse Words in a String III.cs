public class Solution
{
    public string ReverseWords(string s)
    {
        var words = s.Split();
        var reversedWords = new List<string>();
        
        foreach (var word in words)
        {
            var charArray = word.ToCharArray();
            Array.Reverse(charArray);
            reversedWords.Add(new string(charArray));
        }
        
        return string.Join(" ", reversedWords);
    }
}