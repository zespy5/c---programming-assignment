#ifndef ASSIGN_3_STUDENT_H
#define ASSIGN_3_STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <numeric>

#include <memory>



const int SUBJECT_NO = 3;



struct StudentInfo {

    std::string name;

    int scores[SUBJECT_NO];

    int sum;

    double average;

};



std::unique_ptr<StudentInfo> make_student();

void print(std::unique_ptr<StudentInfo> si);

void print_all(const std::vector<std::unique_ptr<StudentInfo>>& vec);



#endif //ASSIGN_3_STUDENT_H