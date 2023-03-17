#include "0208.hpp"

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << '\n';   // return True
    cout << trie.search("app") << '\n'      // return False
         << trie.startsWith("app") << '\n'; // return True
    trie.insert("app");
    cout << trie.search("app") << '\n'; // return True
    return 0;
}
