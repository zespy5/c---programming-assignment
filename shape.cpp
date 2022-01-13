#include "shape.h"
#include <iostream>
#include <map>

using namespace std;


unique_ptr<Rectangle> make_rectangle(){
    unique_ptr<Rectangle>pRec(new Rectangle);
    cin>>pRec->width>>pRec->height;
    pRec->area = pRec->width*pRec->height;
    return pRec;
}

unique_ptr<Circle> make_circle(){
    unique_ptr<Circle>pCir(new Circle);
    cin>>pCir->radius;
    pCir->area = pCir->radius*pCir->radius*3.14;
    return pCir;
}

Command getCommand(const string& command){
    if (command == "rect") return RECT;
    else if (command == "circle") return CIRCLE;
    else if (command == "print") return PRINT;
    else if (command == "sum") return SUM;
    else if (command == "sort") return SORT;
    else if (command == "clear") return CLEAR;
    else if (command == "quit") return QUIT;
    else return INVALID;

}