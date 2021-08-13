#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double student_scores[5] = {0};
double test_scores[3] = {0};
int main(){
    int scoreMax = 0, scoreA = 0;
    int x[15];
    ifstream data;
    data.open("p6.dat");
    for (int i = 0; i <= 14; i++) {             //input data from file to array
        data >> x[i];
    }
    
    for (int i = 0; i <= 4; i++) {              //for loop to average student's scores and put into student_scores array
        int sum = 0;
        for (int j = 1; j <= 3; j++) {
            sum += x[(j+3*(i))-1];
            student_scores[i] = sum;
        }
        student_scores[i] = student_scores[i]/3;
    }

    for (int i = 0; i <= 2; i++) {               //for loop to average test scores and put into test_scores array
        int sum = 0;
        for (int j = 0; j <= 14; j+=3) {
            sum += x[j+i*1];
            test_scores[i] = sum;
        }
        test_scores[i] = test_scores[i]/5;
    }
    
    for (int i = 0; i<=14; i++){
        if (x[i]>scoreMax) {
            scoreMax = x[i];
        }
        if (x[i]>=90){
            scoreA++;
        }
    }
    
        cout << "Average Score per Student:  ";
    for (int i = 0; i<=4; i++){
        cout << fixed << setprecision(2) << student_scores[i] << " ";
    }
    cout << endl;
        cout << "\nAverage Score per Test:  ";
    for (int i = 0; i<=2; i++){
        cout << test_scores[i] << " ";
    }
    
    cout << "\n\nThe best score was:  " << scoreMax << endl;
    cout << "\nThe number of tests that scored an 'A' was:  ";
    cout << scoreA << endl;
    return 0;
}
