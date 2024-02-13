class Solution
{
public:
    string firstPalindrome(vector<string>& words)
    {
        for (string word : words)
        {
            if (isPalindromic(word))
            {
                return word;
            }
        }

        return "";
    }

    bool isPalindromic(string word)
    {
        for (int i = 0; i < word.size() / 2; ++i)
        {
            if (word[i] != word[word.size() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};