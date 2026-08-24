#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 三次反转法：把数组向右轮转 k 位
    // 1. 整体反转  2. 反转前 k 个  3. 反转后 n-k 个，三步后即完成右移 k 位
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();       // 数组长度
        k %= n;                    // k 可能大于 n，取模得到实际轮转次数
        reverse(nums, 0, n - 1);   // 整个反转
        reverse(nums, 0, k - 1);   // 前 k 个反转
        reverse(nums, k, n - 1);   // 后面反转
    }

private:
    // 辅助函数：反转数组 [left, right] 区间内的元素
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {                    // 左右指针向中间靠拢，相遇即停
            swap(nums[left], nums[right]);        // 交换左右两个元素
            ++left;                               // 左指针右移
            --right;                              // 右指针左移
        }
    }
};

int main() {
    // 测试用例：向右轮转 3 位，预期 [5, 6, 7, 1, 2, 3, 4]
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 3);
    cout << "[";
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
    return 0;
}