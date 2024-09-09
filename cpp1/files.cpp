/* This program uses ifstream to load in a text file, 
 * prints it out, sorts it, then prints it out again */

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream word_file("word.txt");
    istream_iterator<string> start(word_file), end;
    vector<string> words(start, end);
    cout << "\n\nWords as read:\n";
    for (auto str : words) cout << str << '\n';
    sort(words.begin(), words.end());
    cout << "\n\nWords as sorted:\n";
    for (auto str : words) cout << str << '\n';
    cout << endl;

}
