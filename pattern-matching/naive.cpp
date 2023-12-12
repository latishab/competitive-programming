// Time taken O(mn)
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Write C++ code here
    string line, pattern;
    
    cout << "Enter your sentence: " << endl;
    getline(cin, line);
    
    cout << "Enter your pattern: " << endl;
    getline(cin, pattern);
    
    int i=0, j=0, count=0, count_patterns=0;
    while (i < line.size()) {
        while (j < pattern.size()) {
            int k = i;
            cout << "Comparing " << line[k] << " with " << pattern[j] << endl;
            if (line[k] == pattern[j]) {
                count++;
                i++;
                j++;
            } else {
                j = 0; // reset j
                break;
            }
        }
        
        if (count == pattern.size()) {
            count_patterns++;
        }
        count = 0; // reset the counter
        i++;
    }
    
    cout << "The number of patterns are: " << count_patterns << endl;

    return 0;
}
