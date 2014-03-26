// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
// Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words.
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."], L: 16.
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
// Corner Cases:
//    A line other than the last line might contain only one word. What should you do in this case?
//    In this case, that line should be left-justified.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> text;
        int i = 0;
        int n = words.size();
        while (i < n)
        {
            int l = 0;
            int j = i;
            while (j < n)
            {
                l += (words[j].length()+1);
                if (l > L+1)
                {
                    break;
                }
                j++;
            }
            
            int cnt = j - i;
            if (j < n)
            {
                l -= (words[j].length()+cnt+1);
            }
            
            string line;
            if (j == n || i+1 == j)
            {
                // left justified
                l = 0;
                for (; i < j; i++)
                {
                    line += words[i];
                    l += words[i].length();
                    if (i < j-1)
                    {
                        line += ' ';
                        l++;
                    }
                }
                if (L-l > 0)
                {
                    line.append(L-l, ' ');
                }
            }
            else
            {
                int sep = (L-l) / (cnt-1);
                int c = (L-l) % (cnt-1);
                for (; i < j; i++)
                {
                    line += words[i];
                    if (c > 0)
                    {
                        c--;
                        line.append(sep+1, ' ');
                    }
                    else if (i < j-1)
                    {
                        line.append(sep, ' ');
                    }
                }
            }

            text.push_back(line);
            i = j;
        }
        return text;
    }
};

int main()
{
    string A[] = {"Listen","to","many,","speak","to","a","few."};
    vector<string> words(A, A+7);

    Solution solu;
    vector<string> text = solu.fullJustify(words, 8);

    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i] << "|" << endl;
    }

    return 0;
}
