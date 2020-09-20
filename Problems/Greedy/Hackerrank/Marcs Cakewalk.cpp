long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end());
    reverse(calorie.begin(), calorie.end());
    long ans = 0, n = calorie.size();
    for(int i = 0; i<n; i++)
        ans += (calorie[i]*pow(2, i));
    return ans;
}