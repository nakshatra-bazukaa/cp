int minimumAbsoluteDifference(vector<int> arr) {
    int n = arr.size();
    int ans = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i = 1; i<n; i++)
        if(ans > abs(arr[i] - arr[i-1]))
            ans = abs(arr[i] - arr[i-1]);

    return ans;
}