class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;

        for (int num: nums2) {
            while (!s.empty() && s.top() < num) { // pop elements from the stack and update the map
                map[s.top()] = num;
                s.pop();
            }
            s.push(num); // push current element into the stack
        }

        for (int i=0; i < nums1.size(); i++) { // Check if each element in nums1 has a next greater element in map
            nums1[i] = map.count(nums1[i]) ? map[nums1[i]] : -1; // update element in nums1 with next greater element or -1
        }
    
        return nums1;
    }
};
