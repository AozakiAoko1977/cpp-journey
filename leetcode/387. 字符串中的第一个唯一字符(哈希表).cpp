#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(char ch : s){
            count[ch-'a']++;
        }
        for(int i = 0 ; i < s.size(); i++ ){
            if(count[s[i] - 'a' ] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << "leetcode     → " << sol.firstUniqChar("leetcode") << endl;     // 预期 0
    cout << "loveleetcode → " << sol.firstUniqChar("loveleetcode") << endl; // 预期 2
    cout << "aabb         → " << sol.firstUniqChar("aabb") << endl;         // 预期 -1
    return 0;
}
