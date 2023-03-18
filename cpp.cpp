/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

// string solution(int N)
// {
//     // Implement your solution here
//     for (int i = 26;; i--)
//         if (N >= i && !(N % i))
//         {
//             string y;
//             for (char c = 'a'; c < 'a' + i; c++)
//                 y.append(N / i, c);
//             return y;
//         }
// }

void bubble_sort(int *begin, int *end)
{
    int cmp = 0, swaps = 0;
    for (; begin < end; end--)
    {
        bool swapped = false;
        for (int *ptr = begin + 1; ptr < end; ptr++)
        {
            ++cmp;
            if (*(ptr - 1) > *ptr)
            {
                ++swaps;
                iter_swap(ptr - 1, ptr);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    printf("%d %d\n", cmp, swaps);
}

int solution(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for (int k = 0; k < n; k++)
    {
        while (i < m - 1 && B[i] < A[k])
            i++;
        if (A[k] == B[i])
            return A[k];
    }
    return -1;
}

int main()
{
    nevikw39;
    // vector<int> a{6, 7, 8, 9}, b{1, 2, 6};
    // cout << solution(a, b) << '\n';
    int arr[] = {1, 3, 8, 3, 7};
    bubble_sort(arr, arr + sizeof(arr) / sizeof(int));
    // copy(ALL(arr), ostream_iterator<int>(cout, " "));
    return 0;
}
