public class Solution
{
    public int SmallestChair(int[][] times, int targetFriend)
    {
        var friendChairs = new Dictionary<int, int>();
        var freeChairs = new PriorityQueue<int, int>();

        foreach (var chair in Enumerable.Range(0, times.Length))
        {
            freeChairs.Enqueue(chair, chair);
        }

        var events = new List<(int time, int friend, bool leave)>();

        foreach (var friendEvents in times.Select((time, friend) => new List<(int, int, bool)>{(time[0], friend, false), (time[1], friend, true)}))
        {
            events.AddRange(friendEvents);
        }

        foreach (var (time, friend, leave) in events.OrderBy(x => x.time).ThenBy(x => !x.leave))
        {
            if (leave)
            {
                var friendChair = friendChairs[friend];
                freeChairs.Enqueue(friendChair, friendChair);
            }
            else
            {
                var friendChair = freeChairs.Dequeue();

                if (friend != targetFriend)
                {
                    friendChairs[friend] = friendChair;
                }
                else
                {
                    return friendChair;
                }
            }
        }

        return -1;
    }
}