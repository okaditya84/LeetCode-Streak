#include <string>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string giggleComp;
        int n = word.size();
        int foo = 0;
        
        while (foo < n) {
            char bar = word[foo];
            int count = 0;
            while (foo < n && word[foo] == bar && count < 9) {
                ++foo;
                ++count;
            }
            giggleComp += std::to_string(count) + bar;
        }
        
        return giggleComp;
    }
};
