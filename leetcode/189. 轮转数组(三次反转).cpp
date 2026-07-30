#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);   // 整个反转
        reverse(nums, 0, k - 1);   // 前 k 个反转
        reverse(nums, k, n - 1);   // 后面反转
    }

private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }
};

int main() {
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