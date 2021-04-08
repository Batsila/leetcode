class Solution 
{
private:
    vector<vector<char>> letters_per_digits =
    {
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z' }
    };
    
    vector<string> ans;
    string digits;
    
public:
    vector<string> letterCombinations(string digits) 
    {
        if (!digits.size())
        {
            return vector<string>();
        }
        
        this->digits = digits;
        
        combine_recursive("", 0);
        
        return ans;
    }
    
    void combine_recursive(string current_string, int current_position)
    {
        if (current_position < digits.size())
        {
            for (char c : letters_per_digits[digits[current_position] - '2'])
            {
                combine_recursive(current_string + c, current_position + 1);
            }
        }
        else
        {
            ans.push_back(current_string);
        }
    }
};