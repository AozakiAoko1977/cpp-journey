#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 核心思路：不断求各位数字的平方和，用 set 记录出现过的数，出现循环就说明不是快乐数
    bool isHappy(int n) {
        unordered_set<int> set;              // 记录出现过的数，用于检测循环
        while(n != 1){                       // 算到 1 才是快乐数
            set.insert(n);                   // 记录当前数
            int sum = 0;
            while(n > 0){
                int digit = n % 10;          // 取出个位
                sum += digit * digit;        // 累加个位的平方
                n /= 10;                     // 去掉个位
            }
            n = sum;                         // 得到下一次要处理的数
            if(set.count(n)){                // 这个数之前出现过 → 陷入循环
                return false;                // 不是快乐数
            }
        }
        return true;                         // 到达 1，是快乐数
    }
};

int main() {
    Solution s;
    cout << "19 → " << (s.isHappy(19) ? "快乐数" : "非快乐数") << endl;    // 预期 快乐数
    cout << "2  → " << (s.isHappy(2) ? "快乐数" : "非快乐数") << endl;     // 预期 非快乐数
    cout << "7  → " << (s.isHappy(7) ? "快乐数" : "非快乐数") << endl;     // 预期 快乐数
    return 0;
}
