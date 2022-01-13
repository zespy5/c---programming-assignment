#include <iostream>
#include <map>
#include <string>
#include <regex>

using namespace std;

int main() {
    string str;
    map<string, int> words;

    while(cin>>str&&str!="^"){
        auto filtered {regex_replace(str,regex("[.|,|:|;|]"),"")};
        ++words[filtered];

    }
    int n = 0;
    for (auto i:words)
        n++;

    cout<<"words: "<<n<<endl;

    while(1){
        string cmd;
        cin>>cmd;

        if(cmd == "QUIT"){
            cout<<"Bye!";
            break;
        }
        else{
            auto foundWord = words.find(cmd);
            if(foundWord != words.end())
                cout<<foundWord->first<<": "<<foundWord->second<<endl;
            else
                cout<<"NOT FOUND"<<endl;
        }
    }
}
