// Task 1 CGPA Calculator

#include<iostream>
using namespace std;

int main() {
    int n;
    float grade, credit, totalCredits = 0, totalPoints = 0;
    
    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Course " << i << " grade : ";
        cin >> grade;
        cout << "Course " << i << " credit hours: ";
        cin >> credit;
        totalPoints += grade * credit;
        totalCredits += credit;
    }

    float cgpa = totalPoints / totalCredits;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
