#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    // 双指针技巧：k 是慢指针（下一个不重复元素的写入位置），i 是快指针（扫描数组）
    // 数组已有序，只与前一元素比较，遇到新数字就写入 k 处
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;   // 空数组：没有可去的重复项
        int k = 1;  // 慢指针：下一个不重复元素的写入位置
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {  // 与前一个元素不同 → 遇到新数字
                nums[k] = nums[i];   // 把新数字写到位置 k
                ++k;                 // 写入位置后移一位
            }
        }
        return k;   // k 就是去重后数组的长度
    }
};

int main() {
    // 测试用例：去重后应为 {1, 2, 3}
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
