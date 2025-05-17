#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> streakSet;
        int beginWindow = 0;
        int maxStreak = 0;

        for (int endWindow = 0; endWindow < s.length(); endWindow++) {
            while (streakSet.find(s[endWindow]) != streakSet.end()) {
                streakSet.erase(s[beginWindow]);
                beginWindow++;
            }

            streakSet.insert(s[endWindow]);
            maxStreak = max(maxStreak, endWindow - beginWindow + 1);
        }
        return maxStreak;
    }
};
