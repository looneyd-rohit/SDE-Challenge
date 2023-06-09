int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    int cnt = 0, ans = 0;
    int i=0, j=0;
    while(i<n && j<n){
        if(at[i] <= dt[j]){
            cnt++;
            ans = max(ans, cnt);
            i++;
        }else{
            cnt--;
            j++;
        }
    }
    return ans;
}