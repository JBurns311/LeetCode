#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        map<int,vector<int>> sumMap;

        for (int i = 0; i < nums.size(); i++) {
            auto complement = sumMap.find(target - nums[i]);
            if (complement != sumMap.end()) {
                vector<int> sumVec = {complement->second[0], i};
                return sumVec;
            } else {
                sumMap[nums[i]].push_back(i);
            }
        }
        return vector<int>();
    }
};

int main () {
    vector<int> v = {2, 7, 11, 15};
    Solution s;
    vector<int> answer = s.twoSum(v, 9);
    cout << "answer is :" << answer[0] << ", " << answer[1] << endl;

    return 0;
}
