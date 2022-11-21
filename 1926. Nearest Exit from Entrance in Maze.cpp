class Solution
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        while (not q.empty())
        {
            auto c = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int x = c[0] + dx[i];
                int y = c[1] + dy[i];
                
                if (x >= 0
                    and x < maze.size()
                    and y >= 0
                    and y < maze[0].size()
                    and maze[x][y] == '.')
                {
                    if (x == 0
                        or x == maze.size() - 1
                        or y == 0
                        or y == maze[0].size() - 1)
                    {
                        return c[2] + 1;
                    }
                    else
                    {
                        maze[x][y] = '+';
                        q.push({x, y, c[2] + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};