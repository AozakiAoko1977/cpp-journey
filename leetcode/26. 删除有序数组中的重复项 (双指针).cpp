#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;  // 慢指针：下一个不重复元素的写入位置
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {  // 与前一个元素不同 → 遇到新数字
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};
    Solution s;
    int k = s.removeDuplicates(nums);
    cout << "k = " << k << endl;
    cout << "[";
    for (int i = 0; i < k; ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
    return 0;
}
