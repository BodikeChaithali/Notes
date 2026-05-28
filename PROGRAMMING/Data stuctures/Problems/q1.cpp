#include<iostream>
#include<vector>
using namespace std;
int singlevalue(vector<int>& nums) {
    //n^n=0
    //n^0=n
    int ans=0;
    for(int val:nums) {
        ans=ans^val;
    }
    return ans;
}
int main() {
    vector<int> vec;
    int n;
    cout << "Enter the value: ";
    cin >> n;
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
    cout << "Unique element is :" << singlevalue(vec) << endl;
    return 0;
}