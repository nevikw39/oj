#include "1472.hpp"

int main()
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");        // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");      // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");       // You are in "facebook.com". Visit "youtube.com"
    cout << browserHistory.back(1) << '\n'     // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
         << browserHistory.back(1) << '\n'     // You are in "facebook.com", move back to "google.com" return "google.com"
         << browserHistory.forward(1) << '\n'; // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    browserHistory.visit("linkedin.com");      // You are in "facebook.com". Visit "linkedin.com"
    cout << browserHistory.forward(2) << '\n'  // You are in "linkedin.com", you cannot move forward any steps.
         << browserHistory.back(2) << '\n'     // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
         << browserHistory.back(7) << '\n';    // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    return 0;
}
