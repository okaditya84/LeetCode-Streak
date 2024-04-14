
    for(int i = 1; i < n; i++) {
        cost += abs(arr[i] - arr[i - 1]);
    }
    return cost;
}