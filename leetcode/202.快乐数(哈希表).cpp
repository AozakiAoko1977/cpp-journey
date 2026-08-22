#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1){
            set.insert(n);
            int sum = 0;
            while(n > 0){
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            if(set.count(n)){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << "19 → " << (s.isHappy(19) ? "快乐数" : "非快乐数") << endl;    // 预期 快乐数
    cout << "2  → " << (s.isHappy(2) ? "快乐数" : "非快乐数") << endl;     // 预期 非快乐数
    cout << "7  → " << (s.isHappy(7) ? "快乐数" : "非快乐数") << endl;     // 预期 快乐数
    return 0;
}
