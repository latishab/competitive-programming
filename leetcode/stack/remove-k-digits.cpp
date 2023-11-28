class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        if (k >= num.size()) {return "0";} // handle edge case
        for (char c: num) {
            /*
            1. if k is larger than 0
            2. if the stack is not empty
            3. if the top of the stack is larger than num
            */
            while (k > 0 && !s.empty() && s.top() > c) {
                s.pop();
                k--;
            }
            s.push(c);
        }

        // if k is still greater than 0, pop k times
        while (k>0) {
            s.pop();
            k--;
        }

        // we form the string using the stack
        deque<char> resultDequeue;
        while(!s.empty()) {
            resultDequeue.push_front(s.top());
            s.pop();
        }

        // convert deque to string
        string result(resultDequeue.begin(), resultDequeue.end());

        // To handle leading zeros
        int startPos = 0;
        while (startPos < result.size() && result[startPos] == '0') {
            startPos++;
        }

        // This means that the string is actually a zero
        if (startPos == result.size()) {
            result = "0";
        } else {
            // We get the substr, removing the leading zero
            result = result.substr(startPos);
        }

        return result;
    }
};
