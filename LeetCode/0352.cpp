#include "0352.hpp"

int main()
{
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);                           // arr = [1]
    for (const auto &i : summaryRanges.getIntervals()) // return [[1, 1]]
        cout << i[0] << ' ' << i[1] << '\n';
    cout << '\n';
    summaryRanges.addNum(3);                           // arr = [1, 3]
    for (const auto &i : summaryRanges.getIntervals()) // return [[1, 1], [3, 3]]
        cout << i[0] << ' ' << i[1] << '\n';
    cout << '\n';
    summaryRanges.addNum(7);                           // arr = [1, 3, 7]
    for (const auto &i : summaryRanges.getIntervals()) // return [[1, 1], [3, 3], [7, 7]]
        cout << i[0] << ' ' << i[1] << '\n';
    cout << '\n';
    summaryRanges.addNum(2);                           // arr = [1, 2, 3, 7]
    for (const auto &i : summaryRanges.getIntervals()) // return [[1, 3], [7, 7]]
        cout << i[0] << ' ' << i[1] << '\n';
    cout << '\n';
    summaryRanges.addNum(6);                           // arr = [1, 2, 3, 6, 7]
    for (const auto &i : summaryRanges.getIntervals()) // return [[1, 3], [6, 7]]
        cout << i[0] << ' ' << i[1] << '\n';
    cout << '\n';
    return 0;
}
