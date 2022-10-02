class Solution
{
public:
    string customSortString(string order, string str)
    {
        map<char, int> pos;
        
        for (int i = 0; i < order.size(); ++i)
        {
            pos[order[i]] = i;
        }
        
        sort(str.begin(), str.end(), [pos](char a, char b)
             {
                 auto a_pos = pos.find(a);
                 auto b_pos = pos.find(b);
                 
                 return a_pos->second < b_pos->second;
             });
        
        return str;
    }
};