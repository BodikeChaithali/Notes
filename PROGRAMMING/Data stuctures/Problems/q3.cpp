#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pairSum(vector<int>& nums,int target) {
    vector<int> ans;
    int start=0,end=nums.size()-1,ps;
    while(start<end) {
        ps=nums[start]+nums[end];
        if(ps>target) end--;
        else if(ps<target) start++;
        else {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
    return {-1,-1};
}
int main() {
    vector<int> vec;
    int n;
    cout << "Enter the value: ";
    cin >> n;
    cout << "Enter the elements in sorted order: ";
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
    int target;
    cin >> target;
    vector<int> ans=pairSum(vec,target);
    cout << "Indeies of the target sum: " << ans[0] << "," << ans[1] << endl;
    return 0;
}