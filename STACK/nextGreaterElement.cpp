#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nGE(vector<int>& req) {
    vector<int> ans;
    stack<int> st;
    
    // Traverse the array from right to left
    for(int i = req.size() - 1; i >= 0; --i) {
        
        if(st.empty()) {
            ans.push_back(-1);
        }
        else if(!st.empty() && st.top() > req[i]) {
            ans.push_back(st.top());
        }
        else if(!st.empty() && st.top() <= req[i]) {
            while(!st.empty() && st.top() <= req[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
        }
        st.push(req[i]);
    }

    // Reverse the result to match the original order of input
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    int n;
    cin >> n; // Input for the number of elements
    vector<int> input(n);
    for(int i = 0; i < n; ++i) {
        cin >> input[i]; // Input the array elements
    }
    
    vector<int> output = nGE(input);

    cout << "Next Greater Elements: ";
    for(auto &ele : output) {
        cout << ele << " "; // Print the output
    }
    cout << endl;
    
    return 0;
}
