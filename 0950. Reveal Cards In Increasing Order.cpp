class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        sort(deck.begin(), deck.end());
        reverse(deck.begin(), deck.end());
        deque<int> new_deck;

        for (int card : deck)
        {
            if (not new_deck.empty())
            {
                new_deck.push_front(new_deck.back());
                new_deck.pop_back();
            }

            new_deck.push_front(card);
        }

        return vector<int>(new_deck.begin(), new_deck.end());
    }
};