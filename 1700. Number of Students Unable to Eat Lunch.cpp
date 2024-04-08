class Solution
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        auto students_queue = deque<int>(students.begin(), students.end());
        auto sandwiches_stack = deque<int>(sandwiches.begin(), sandwiches.end());
        int iterations = 0;

        while (not students_queue.empty() and iterations < students_queue.size())
        {
            if (students_queue.front() == sandwiches_stack.front())
            {
                sandwiches_stack.pop_front();
                students_queue.pop_front();
                iterations = 0;
            }
            else
            {
                students_queue.push_back(students_queue.front());
                students_queue.pop_front();
                ++iterations;
            }
        }

        return students_queue.size();
    }
};