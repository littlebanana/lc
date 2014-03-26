// Given an absolute path for a file (Unix-style), simplify it.
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
//    1. Did you consider the case where path = "/../"?
//    2. In this case, you should return "/".
//    3. Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//    4. In this case, you should ignore redundant slashes and return "/home/foo".

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            int l = path.length();
            deque<string> deQ;
            int i = 0;
            while (i < l)
            {
                // skip multiple spaces and '/'
                for (; i < l && (path[i] == ' ' || path[i] == '/'); i++);

                // parse directory name
                int j = i;
                for (; j < l && path[j] != ' ' && path[j] != '/'; j++);

                string dir = path.substr(i,j-i);
                if (dir.compare("..") == 0)
                {
                    if (!deQ.empty())
                    {
                        deQ.pop_back();
                    }
                }
                else if (dir.compare(".") != 0)
                {
                    if (!dir.empty())
                    {
                        deQ.push_back(dir);
                    }
                }

                i = j;
            }

            if (deQ.empty())
            {
                return "/";
            }
            string simplified;
            while (!deQ.empty())
            {
                simplified += "/";
                simplified += deQ.front();
                deQ.pop_front();
            }
            return simplified;
        }
};

int main()
{
    string s = "/a/./b/../../c/";

    Solution solu;
    cout << s << endl;
    cout << solu.simplifyPath(s) << endl;

    return 0;
}
