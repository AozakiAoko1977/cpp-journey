#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[k]);
                ++k;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    cout << "[";
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
    return 0;
}