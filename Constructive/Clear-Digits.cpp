// Leetcode 3174

// Approach: constructive
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        return processInput(s);
    }

private:
    string processInput(const string& input) {
        stack<char> charStack;
        filterCharacters(input, charStack);
        return constructResult(charStack);
    }

    void filterCharacters(const string& input, stack<char>& charStack) {
        for (const auto& character : input) {
            if (isLowercase(character)) {
                charStack.push(character);
            } else {
                if (!charStack.empty()) {
                    charStack.pop();
                }
            }
        }
    }

    bool isLowercase(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    string constructResult(stack<char>& charStack) {
        string result;
        while (!charStack.empty()) {
            result.push_back(charStack.top());
            charStack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
