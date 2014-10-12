// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int num = 0;
            int l = s.length();
            for (int i = l-1; i >= 0; i--) {
                if (s[i] == 'I') {
                    num += 1;
                } else if (s[i] == 'V') {
                    if (i > 0 && s[i-1] == 'I') {
                        num += 4;
                        i--;
                    } else {
                        num += 5;
                    }
                } else if (s[i] == 'X') {
                    if (i > 0 && s[i-1] == 'I') {
                        num += 9;
                        i--;
                    } else {
                        num += 10;
                    }
                } else if (s[i] == 'L') {
                    if (i > 0 && s[i-1] == 'X') {
                        num += 40;
                        i--;
                    } else {
                        num += 50;
                    }
                } else if (s[i] == 'C') {
                    if (i > 0 && s[i-1] == 'X') {
                        num += 90;
                        i--;
                    } else {
                        num += 100;
                    }
                } else if (s[i] == 'D') {
                    if (i > 0 && s[i-1] == 'C') {
                        num += 400;
                        i--;
                    } else {
                        num += 500;
                    }
                } else {
                    if (i > 0 && s[i-1] == 'C') {
                        num += 900;
                        i--;
                    } else {
                        num += 1000;
                    }
                }
            }
            return num;
        }

        int romanToInt2(string s) {
            // I - 1, V - 5, X - 10, L - 50, C - 100, D - 500, M - 1000
            unordered_map<string, int> map;
            map["M"] = 1000;
            map["CM"] = 900;
            map["D"] = 500;
            map["CD"] = 400;
            map["C"] = 100;
            map["XC"] = 90;
            map["L"] =50;
            map["XL"] = 40;
            map["X"] = 10;
            map["IX"] = 9;
            map["V"] = 5;
            map["IV"] = 4;
            map["I"] = 1;
            int num = 0;
            int l = s.length();
            for (int i = 0; i < l; i++) {
                auto it = map.find(s.substr(i, 2));
                if (i == l - 1 || it == map.end()) {
                    it = map.find(s.substr(i, 1));
                    num += it->second;
                } else {
                    num += it->second;
                    i++;
                }
            }
            return num;
        }
};

int main() {
    Solution solu;

    string s = "XIIV";
    cout << "s = " << s << ", num = " << solu.romanToInt(s) << endl;

    return 0;
}
