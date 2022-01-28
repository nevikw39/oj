#include "0211.hpp"

int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << '\n'
         << wordDictionary.search("bad") << '\n'
         << wordDictionary.search(".ad") << '\n'
         << wordDictionary.search("b..") << '\n';
    return 0;
}
