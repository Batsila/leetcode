class Solution 
{
public:
    bool isNumber(string s) 
    {
        regex reg(R"_([+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?)_");
        
        return regex_match(s, reg);
    }
};