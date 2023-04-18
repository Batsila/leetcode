class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int ind1 = 0;
        int ind2 = 0;

        while (ind1 < word1.size() or ind2 < word2.size())
        {
            if (ind1 < word1.size())
            {
                ans.push_back(word1[ind1]);
                ++ind1;
            }

            if (ind2 < word2.size())
            {
                ans.push_back(word2[ind2]);
                ++ind2;
            }
        }

        return ans;
    }
};