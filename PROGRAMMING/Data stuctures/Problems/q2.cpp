#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int MaxSubArraySum(vector<int>& nums) {
    int curr_sum=0;
    int max_sum=INT_MIN;
    for(int val:nums) {
        curr_sum+=val;
        max_sum=max(curr_sum,max_sum);
        if(curr_sum<0) curr_sum=0;
    }
    return max_sum;
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
    cout << "Maximum sub array sum :" << MaxSubArraySum(vec) << endl;
    return 0;
}