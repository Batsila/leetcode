public class Solution
{
    private int[] dx = { 0, 1, 0, -1 };
    private int[] dy = { 1, 0, -1, 0 }; 

    public int RobotSim(int[] commands, int[][] obstacles)
    {
        var obstaclesSet = obstacles.Select(x => (long)x[0] * 100000 + x[1]).ToHashSet();
        var result = 0;

        var location = (x: 0, y: 0);
        var direction = 0;

        foreach (var command in commands)
        {
            if (command == -1)
            {
                direction += 1;
            }
            else if (command == -2)
            {
                direction += 3;
            }
            else
            {
                for (var i = 0; i < command; ++i)
                {
                    var x = location.x + dx[direction % 4];
                    var y = location.y + dy[direction % 4];

                    if (!obstaclesSet.Contains((long)x * 100000 + y))
                    {
                        location = (x, y);
                    }
                    else
                    {
                        break;
                    }
                }

                result = Math.Max(result, location.x * location.x + location.y * location.y);
            }
        }

        return result;
    }

}