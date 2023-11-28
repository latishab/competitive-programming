#include <stack>
#include <vector>
#include <string>

class Solution {
public:
int calPoints(vector<string>& operations) {
    stack<int> s;

    for(const string& op: operations) {
        if (op != "D" && op != "C" && op != "+") {
            int num = stoi(op);
            cout << "The num is " << num << endl;
            s.push(num); // push to stack s
        } else if (op == "C") {
            s.pop(); // remove the previous record
        } else if (op == "D") {
            s.push(s.top() * 2); // double the previous record
        } else if (op == "+") {
            int top1 = s.top();
            s.pop();

            int top2 = s.top();
            s.push(top1);
            s.push(top1 + top2);
        }
    }   

    int sum = 0;
    while (!s.empty()) { // count the sum of values in the stack
        sum += s.top();
        s.pop();
    }
    return sum;
}
};
