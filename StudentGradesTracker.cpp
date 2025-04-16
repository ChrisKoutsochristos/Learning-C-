#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

float AvgCalc(const vector<float>& grades){
    float sum = 0.00f;
    for (float grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

int main (){
    system("cls");
    vector<string> studentNames;
    vector<vector<float>> studentGrades;
    int studentsNumber;
    
    cout << "How many students are there? : ";
    cin >> studentsNumber;
    for (int i = 1; i <= studentsNumber; i++) {
        cin.ignore();
        string name;
        float grades;
        cout << endl << "Student [" << i <<"] name : ";
        getline(cin, name);
        studentNames.push_back(name);
        cout << "How many grades? : ";
        cin >> grades;
        vector<float> StGrades;
        for (float j = 1; j <= grades; j++) {
            float grade;
            cout << "Grade [" << j << "] : ";
            cin >> grade;
            StGrades.push_back(grade);
        }
        studentGrades.push_back(StGrades);
    }
    for (int k = 0; k < studentNames.size(); ++k) {
        float avg = AvgCalc(studentGrades[k]);
        cout << studentNames[k] << " - Average: " << avg << endl;
    }

}