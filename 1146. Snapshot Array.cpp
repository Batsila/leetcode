class SnapshotArray
{
    int s = 0;
    vector<vector<pair<int, int>>> v;
public:
    SnapshotArray(int length)
    {
        v = vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, make_pair(s, 0)));
    }
    
    void set(int index, int val)
    {
        v[index].push_back(make_pair(s, val));
    }
    
    int snap()
    {
        return s++;
    }
    
    int get(int index, int snap_id)
    {
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));

        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */