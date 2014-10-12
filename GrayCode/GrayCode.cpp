// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code(1<<n);     // pre-allocate space, make use of shift
        code[0] = 0;
        int addon = 1;
        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i < addon; i++)
            {
                code[addon+i] = code[addon-i-1] + addon;
            }
            addon *= 2;
        }
        return code;
    }

    vector<int> grayCode2(int n) {
        vector<int> code;
        code.push_back(0);
        for (int l = 1; l <= n; l++) {
            int n = code.size();
            for (int j = 0; j < n; j++) {
                code.push_back(code[n-1-j] + n);
            }
        }
        return code;
    }
};

int main()
{
    Solution solu;
    vector<int> result = solu.grayCode(3);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] <<endl;
    }

    return 0;
}
