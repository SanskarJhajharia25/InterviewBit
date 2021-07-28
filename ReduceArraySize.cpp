/*
https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        priority_queue<int> pq;
        for(int &element : arr) map[element]++;
        for(const pair<int, int> &p : map) pq.push(p.second);
        int elementToDelete = arr.size() / 2, elementDeleted = 0, count = 0;
        while(elementDeleted < elementToDelete) {
            elementDeleted += pq.top(); pq.pop();
            count++;
        }
        
        return count;
    }
};
