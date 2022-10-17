class Solution
{
    int m[26];
public:
    bool checkIfPangram(string sentence)
    {
        for (char c : sentence)
        {
            ++m[c - 'a'];
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (not m[i])
            {
                return false;
            }
        }
        
        return true;
    }
};