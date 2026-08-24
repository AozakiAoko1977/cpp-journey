#include  <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 双指针技巧：k 是慢指针（下一个保留元素的写入位置），i 是快指针（扫描数组）
    // 遍历时把不等于 val 的元素依次搬到数组前面
    int removeElement(vector<int>& nums, int val) {
        int k = 0;   // 慢指针：下一个保留元素的写入位置
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {   // 不是要删除的值 → 保留
                nums[k] = nums[i];  // 搬到前面 k 的位置
                ++k;                // 写入位置后移一位
            }
        }
        return k;   // k 就是移除后数组的长度
    }
};

int main() {
    // 测试用例：删除 3 后应为 {2, 2}
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution s;
    int k = s.removeElement(nums, val);
    cout << "k = " << k << endl;
    cout << "[";
    for (int i = 0; i < k; ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
    return 0;
}