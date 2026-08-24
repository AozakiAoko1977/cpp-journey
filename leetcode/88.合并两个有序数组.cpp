#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 逆向双指针：nums1 尾部预留了 n 个空位，从大到小从后往前填充，避免覆盖未处理的元素
    // 每次比较两个数组末尾元素，把较大的放到 nums1 尾部
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;        // nums1 有效部分的末尾
        int p2 = n - 1;        // nums2 的末尾
        int p = m + n - 1;     // 合并后的写入位置（nums1 末尾）
        while (p1 >= 0 && p2 >= 0) {     // 两边都还有元素时
            if (nums1[p1] > nums2[p2]) { // nums1 的元素更大 → 放它
                nums1[p] = nums1[p1];
                --p1;
            } else {                     // 否则放 nums2 的元素（相等也放 nums2）
                nums1[p] = nums2[p2];
                --p2;
            }
            --p;                         // 写入位置前移一位
        }
        while (p2 >= 0) {                // nums2 还有剩余 → 依次搬到前面
            nums1[p] = nums2[p2];
            --p2;
            --p;
        }
        // 若 p1 >= 0，nums1 剩余元素本来就在正确位置，无需处理
    }
};

int main() {
    // 测试用例：nums1 后 3 个 0 是预留空位，合并后应为 {1, 2, 2, 3, 5, 6}
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    cout << "[";
    for (int i = 0; i < nums1.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums1[i];
    }
    cout << "]" << endl;
    return 0;
}
