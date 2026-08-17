/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:
    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.

Example 3:
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

Constraints:
    1 <= words.length <= 300
    1 <= words[i].length <= 20
    words[i] consists of only English letters and symbols.
    1 <= maxWidth <= 100
    words[i].length <= maxWidth
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth){
    vector<string> res;
    vector<string> curr;

    int no_of_letters = 0;

    for(string word: words){
        if(word.size() + curr.size() + no_of_letters > maxWidth){
            for(int i = 0;i < maxWidth - no_of_letters;i++){
                curr[i % (curr.size() - 1 ? curr.size() - 1 : 1)] += ' ';
            }

            string line = "";
            for(string s: curr){
                line += s;
            }

            res.push_back(line);

            curr.clear();
            no_of_letters = 0;
        }

        curr.push_back(word);
        no_of_letters += word.size();
    }

    string last_line = "";

    for(int i = 0; i < curr.size(); i++){
        if(i > 0)
            last_line += ' ';

        last_line += curr[i];
    }

    while(last_line.size() < maxWidth){
        last_line += ' ';
    }

    res.push_back(last_line);

    return res;
}

int main(){
    int maxWidth;
    cout<<"Enter the max width: ";
    cin>>maxWidth;

    int n;
    cin>>n;
    vector<string> words(n);

    cout<<"Enter the words: ";
    for(int i = 0;i < n;i++){
        cin>>words[i];
    }

    vector<string> res = fullJustify(words, maxWidth);

    cout<<"New strings = "<<endl;
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<endl;
    }

}