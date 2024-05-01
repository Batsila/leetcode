class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int ind = word.find(ch);

        if (ind != -1)
        {
            reverse(word.begin(), word.begin() + ind + 1);
        }

        return word;
    }
};