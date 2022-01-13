#include "shape.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {

    vector<unique_ptr<Rectangle>> rvec; vector<unique_ptr<Circle>> cvec;

    while(true) {

        string cmd; cin >> cmd;

        transform(begin(cmd), end(cmd), begin(cmd),  [](char& c){return tolower(c);});

        Command c = getCommand(cmd);


        switch(c){
            case RECT:
                rvec.emplace_back(make_rectangle());
                break;

            case CIRCLE:
                cvec.emplace_back(make_circle());
                break;

            case SORT:
                sort(rvec.begin(),rvec.end(), [](unique_ptr<Rectangle>& a,unique_ptr<Rectangle>& b){return a->area > b->area;});
                sort(cvec.begin(),cvec.end(),[](unique_ptr<Circle>& a,unique_ptr<Circle>& b){return a->area > b->area;});

                break;

            case PRINT:
                static auto printR = [](const unique_ptr<Rectangle>& a) {cout<<"Rectangle:"<<"\t"<<a->width<<"\t"<<a->height<<"\t"<<a->area<<endl;};
                for_each(rvec.cbegin(),rvec.cend(),printR);
                static auto printC = [](const unique_ptr<Circle>& a) {cout<<"Circle:"<<"     \t"<<a->radius<<"\t"<<a->area<<endl;};
                for_each(cvec.cbegin(),cvec.cend(),printC);

                break;

            case SUM:

                static double sumArea = accumulate(rvec.begin(),rvec.end(),0.0,[](double sum, const unique_ptr<Rectangle>& rec){return sum+rec->area;});
                sumArea += accumulate(cvec.begin(),cvec.end(),0.0,[](double sum, const unique_ptr<Circle>& cir){return sum+cir->area;});
                cout<<sumArea<<endl;
                break;

            case CLEAR:
                rvec.clear(); cvec.clear();
                break;

            case QUIT:
                return 0;

            case INVALID:
                cout << "Invalid Command" << '\n';
                break;


        }
    }
}
