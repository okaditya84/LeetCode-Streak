class Solution {
public:
    long long countSubarrays(vector<int>& numbers, int target) {
        long long  length = numbers.size(); 
        long long  maxValue = *max_element(numbers.begin(), numbers.end()); 
        long long start = 0, end = 0, count = 0, result = 0; 

        while (end < length) { 
            if (numbers[end] == maxValue) { 
                count++; 
            } 
            if (count >= target) { 
                while (count >= target) { 
                    result += length - end; 
                    if (numbers[start] == maxValue) { 
                        count--; 
                    } 
                    start++; 
                } 
            } 
            end++; 
        } 
        return result; 
    }
};
