// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
//    Only one letter can be changed at a time
//    Each intermediate word must exist in the dictionary
// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Note:
//     Return 0 if there is no such transformation sequence.
//     All words have the same length.
//     All words contain only lowercase alphabetic characters.

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            int l = start.length();
            queue<pair<int,string> > Q;
            Q.push(pair<int,string>(1,start));
            unordered_set<string> visited;
            while (!Q.empty())
            {
                int d = Q.front().first;
                string word = Q.front().second;
                Q.pop();

                for (int i = 0; i < l; i++)
                {
                    char c = word[i];
                    for (int j = 0; j < 26; j++)
                    {
                        word[i] = 'a'+j;
                        if (word.compare(end) == 0)
                        {
                            return (word[i] == c ? d : d+1);
                        }
                        if (word[i] != c && visited.find(word) == visited.end() && dict.find(word) != dict.end())
                        {
                            Q.push(pair<int,string>(d+1,word));
                            visited.insert(word);
                        }
                        word[i] = c;
                    }
                }
            }
            return 0;
        }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    string start = "hit";
    string end = "cog";

    Solution solu;
    cout << solu.ladderLength(start, end, dict) << endl;

    return 0;
}
