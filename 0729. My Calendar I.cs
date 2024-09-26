public class MyCalendar
{
    private readonly List<(int Start, int End)> _events = new ();
    
    public bool Book(int start, int end)
    {
        if (_events.Any(x => x.Start < end && x.End > start))
        {
            return false;
        }

        _events.Add((start, end));

        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.Book(start,end);
 */