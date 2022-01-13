#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <memory>
#include "student.h"

using namespace std;

unique_ptr<StudentInfo>make_student(){
    unique_ptr<StudentInfo> pStudent(new StudentInfo);
    cin>>pStudent->name>>pStudent->scores[0]>>pStudent->scores[1]>>pStudent->scores[2];
    pStudent->sum = pStudent->scores[0]+pStudent->scores[1]+pStudent->scores[2];
    pStudent->average = pStudent->sum/3.0;
    return move(pStudent);
}

void print(const StudentInfo& si){
    cout<<si.name<<"\t"<<si.scores[0]<<"\t"<<si.scores[1]<<"\t"<<si.scores[2]<<"\t"<<si.sum<<"\t"<<si.average;

}

void print_all(const vector<unique_ptr<StudentInfo>>& vec){
    for (auto& it: vec) {
        print(*it);
        cout << endl;
    }
}