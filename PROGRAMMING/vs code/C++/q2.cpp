#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main () {
    cout<<"Enter the marks obtained in the exam: ";
    int marks;
    cin >> marks;
    if(marks >= 80 and marks<=100) {
        cout << "A" << endl;
    } else if(marks >= 60 and marks < 80) {
        cout << "B" << endl;
    } else if(marks >= 50 and marks < 60) {
        cout << "C" << endl;
    } else if(marks >= 45 and marks < 50) {
        cout << "D" << endl;
    } else if(marks >= 25 and marks < 45) {
        cout << "E" << endl;
    } else if(marks <25) {
        cout << "F" << endl;
    }
    else cout << "Invalid marks has entered" << endl;
}