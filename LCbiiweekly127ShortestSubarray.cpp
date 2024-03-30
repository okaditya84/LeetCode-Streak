void fun(vector<int>& boop, int num) { 
    int counter = 0; 
    while (num > 0) { 
        int remainder = num % 2; 
        if (remainder == 1) { 
            boop[counter] += 1; 
        } 
        num = num / 2; 
        counter++; 
    } 
} 

void fun1(vector<int>& boop, int num) { 
    int counter = 0; 
    while (num > 0) { 
        int remainder = num % 2; 
        if (remainder == 1) { 
            boop[counter] -= 1; 
        } 
        num = num / 2; 
        counter++; 
    } 
} 

int formnumber(vector<int>& boop) { 
    int val = 0; 
    int answer = 1; 
    for (int i = 0; i < 30; i++) { 
        if (boop[i] >= 1) { 
            val += answer; 
        } 
        answer = answer * 2; 
    } 
    return val; 
} 

int minimumSubarrayLength(vector<int>& nums, int k) { 
    vector<int> boop(32, 0); 
    int i, j = 0; 
    int val = 0; 
    int ans = INT_MAX; 
    for (i = 0; i < nums.size(); i++) { 
        val = val | nums[i]; 
        fun(boop, nums[i]); 
        while (i >= j && val >= k) { 
            ans = min(ans, (i - j + 1)); 
            fun1(boop, nums[j]); 
            val = formnumber(boop); 
            j++; 
        } 
    } 
    return ans == INT_MAX ? -1 : ans; 
}
