class Solution {
public:
    int numJewelsInStones(const string& J,const string& S) {
        // create jewels map
        bool map[256] = {0};
        for (const auto ch : J) {
            map[ch] = true;
        }
        int counter = 0;
        for (const auto ch : S) {
            if (map[ch]) {
                ++counter;
            }
        }
        return counter;
    }
};