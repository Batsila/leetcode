class Solution
{
    string ring;
    string key;
    unordered_map<int, unordered_map<int, int>> cache;
public:
    int findRotateSteps(string ring, string key)
    {
        this->ring = ring;
        this->key = key;

        return countSteps(0, 0);
    }

    int countSteps(int ringInd, int keyInd)
    {
        if (cache[ringInd][keyInd])
        {
            return cache[ringInd][keyInd];
        }
        else
        {
            if (keyInd < key.size())
            {
                int minSteps = INT_MAX;

                for (int i = 0; i < ring.size(); ++i)
                {
                    if (ring[i] == key[keyInd])
                    {
                        int stepsBetween = abs(ringInd - i);
                        int stepsAround = ring.size() - stepsBetween;
                        int totalSteps = countSteps(i, keyInd + 1) + min(stepsBetween, stepsAround) + 1;
                        minSteps = min(minSteps, totalSteps);
                        cache[ringInd][keyInd] = minSteps;
                    }
                }
        
                return minSteps;
            }

            return 0;
        }
    }
};