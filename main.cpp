#include <iostream>
#include<limits>
#include<string>
#include<algorithm>

using namespace std;


int main() {

    string cmd;
    string cmdInt = "int";
    string cmdLong = "long";
    string cmdFloat = "float";
    string cmdDouble = "double";
    string cmdQuit = "quit";
    int count[4] = {0,0,0,0};

    while(1){
        cin>>cmd;

        transform(begin(cmd),end(cmd),begin(cmd),[](unsigned char c){return tolower(c);});

        if(cmd == cmdQuit)
            break;
        else if(cmd == cmdInt){
            cout<<numeric_limits<int>::max()<<" "<<numeric_limits<int>::min()<<endl;
            count[0]++;
        }
        else if(cmd == cmdLong){
            cout<<numeric_limits<long>::max()<<" "<<numeric_limits<long>::min()<<endl;
            count[1]++;
        }
        else if(cmd == cmdFloat){
            cout<<numeric_limits<float>::max()<<" "<<numeric_limits<float>::min()<<endl;
            count[2]++;
        }
        else if(cmd == cmdDouble){
            cout<<numeric_limits<double>::max()<<" "<<numeric_limits<double>::min()<<endl;
            count[3]++;
        }
        else{
            cout<<"Invalid Command"<<endl;
        }
    }

    cout<<"=== the number of types ==="<<endl;
    cout<<"int: "<<count[0]<<endl;
    cout<<"long: "<<count[1]<<endl;
    cout<<"float: "<<count[2]<<endl;
    cout<<"double: "<<count[3]<<endl;

}
