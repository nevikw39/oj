#include "1233.hpp"

int main()
{
    vector<string> a{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}, b{"/a", "/a/b/c", "/a/b/d"}, c{"/a/b/c", "/a/b/ca", "/a/b/d"};
    Solution sln;
    assert(sln.removeSubfolders(a) == vector<string>({"/a", "/c/d", "/c/f"}));
    assert(sln.removeSubfolders(b) == vector<string>({"/a"}));
    assert(sln.removeSubfolders(c) == vector<string>({"/a/b/c", "/a/b/ca", "/a/b/d"}));
    return 0;
}
