class Solution 
{
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int, int>> points;
        auto current = make_pair(0, 0);
        points.insert(current);
        
        for (char c : path)
        {
            if (c == 'N')
            {
                current.second += 1;
            }
            else if (c == 'E')
            {
                current.first += 1;
            }
            else if (c == 'S')
            {
                current.second -= 1;
            }
            else if (c == 'W')
            {
                current.first -= 1;
            }
            
            if (points.find(current) != points.end())
            {
                return true;
            }
            
            points.insert(current);
        }
        
        return false;
    }
};