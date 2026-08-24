#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 双指针技巧：k 指向下一个非零元素应放的位置
    // 遇到非零元素就与 k 处交换，把非零元素全部挤到前面，零自然落到后面
    void moveZeroes(vector<int>& nums) {
        int k = 0;   // 下一个非零元素的写入位置
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {          // 遇到非零元素
                swap(nums[i], nums[k]);  // 与 k 处交换，非零元素换到前面
                ++k;                     // 写入位置后移一位
            }
        }
    }
};

int main() {
    // 测试用例：移动后应为 {1, 3, 12, 0, 0}
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