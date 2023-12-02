class Solution
{
public:
    int check(string word, vector<int> available_chars)
    {
        for (char c : word)
        {
            if (available_chars[c - 'a'] <= 0)
            {
                return 0;
            }

            --available_chars[c - 'a'];
        }

        return word.size();
    }

    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> available_chars(26, 0);

        for (char c : chars)
        {
            ++available_chars[c - 'a'];
        }

        int ans = 0;

        for (auto word : words)
        {
            ans += check(word, available_chars);
        }

        return ans;
    }
};