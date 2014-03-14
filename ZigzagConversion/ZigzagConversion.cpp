// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
//
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if (nRows == 1)
            {
                return s;
            }

            int l = s.length();
            string zigzag(l, ' ');

            int j = 0;
            int T = nRows + (nRows - 2);        // period
            for (int r = 0; r < nRows; r++)     // row by row
            {
                for (int i = 0; i < l; i += T)  // start base
                {
                    if (i + r < l)
                    {
                        zigzag[j++] = s[i+r];
                    }
                    if (r > 0 && r < nRows-1)
                    {
                        if (i + (T-r) < l)
                        {
                            zigzag[j++] = s[i+(T-r)];
                        }
                    }
                }
            }
            return zigzag;
        }
};

int main()
{
    string s = "PAYPALISHIRING";

    Solution solu;
    cout << s << endl;
    cout << solu.convert(s, 3) << endl;

    return 0;
}
