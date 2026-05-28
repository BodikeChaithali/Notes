#include <bits/stdc++.h>
using namespace std;

// ---- WRITE YOUR LOGIC HERE ----
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

vector<double> solveTestcase(int n, vector<int> &a) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]<a[j]) swap(&a[i],&a[j]);
        }
    }
    if(n%2!=0) return {(double)a[n/2]};
    else return {((double)(a[n/2]+a[n/2-1]))/2};
}
// --------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<double> medians = solveTestcase(n, a);

        // Print each testcase output in one line
        for (double x : medians) cout << fixed << setprecision(1) << x << " ";
        cout << "\n";
    }
}