//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') stk.push(i); 
            else if (stk.top()==-1 or s[stk.top()]!='(') stk.push(i);
            else stk.pop();
        }
        int last = s.size();
        while (stk.size()) {
            res = max(res, last-stk.top()-1);
            last = stk.top(); stk.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends