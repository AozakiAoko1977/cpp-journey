#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;                          // 左边界
        int right = nums.size() - 1;           // 右边界
        while (left <= right) {
            int mid = left + (right - left) / 2;   // 取中间（防溢出写法）
            if (nums[mid] == target) return mid;   // 找到了，返回下标
            else if (nums[mid] < target) left = mid + 1;   // 目标在右边
            else right = mid - 1;                          // 目标在左边
        }
        return left;                           // 没找到：left 正好是插入位置
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3, 5, 6};
    cout << "[1,3,5,6] 找 5 → " << s.searchInsert(a, 5) << endl;   // 预期 2
    cout << "[1,3,5,6] 找 2 → " << s.searchInsert(a, 2) << endl;   // 预期 1（插在3前面）
    cout << "[1,3,5,6] 找 7 → " << s.searchInsert(a, 7) << endl;   // 预期 4（插在末尾）
    cout << "[1,3,5,6] 找 0 → " << s.searchInsert(a, 0) << endl;   // 预期 0（插在最前）
    return 0;
}
