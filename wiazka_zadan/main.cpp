#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("napisy.txt");
    string a, b;
    int ile_1=0;
    string a1, b1;
    while(in >> a >> b){
        if(a.size()>b.size()*3 || b.size()>a.size()*3){
            ile_1++;
            if(ile_1==1){
                a1=a;
                b1=b;
            }
        }
    }
    cout << "1." << endl;
    cout << ile_1 <<" "<< a1 <<" "<<b1 << endl;
    cout << "2." << endl;
    ifstream in2("napisy.txt");
    string a2, b2;
    while(in2 >> a2 >> b2){
        if(b2.size() > a2.size()){
            bool takie_same = true;
            for(int i=0; i < a2.size(); i++) {
                if(a2[i] != b2[i]) {
                    takie_same = false;
                }
            }
            if(takie_same){
                string dodane_litery(b2, a2.size());
                cout << a2 <<" "<< b2 <<" "<< dodane_litery << endl;
            }
        }else if(a2.size() > b2.size()){
            bool takie_same = true;
            for(int i=0; i < b2.size(); i++) {
                if(b2[i] != a2[i]) {
                    takie_same = false;
                }
            }
            if(takie_same){
                string dodane_litery(a2, b2.size());
                cout << a2 <<" "<< b2 <<" "<< dodane_litery << endl;
            }
        }
    }
    ifstream in3("napisy.txt");
    ifstream in4("napisy.txt");
    string a3, b3;
    string a4, b4;
    int ile_2=0;
    int ile_3=0;
    int ile_max=0;
    cout << "3." << endl;
    while(in3 >> a3 >> b3){
        if(b3.size() < a3.size()){
            for(int i=0; i<b3.size(); i++){
                if(a3[a3.size()-i]==b3[b3.size()-i]){
                    ile_2++;
                }
            }
            if(ile_2>ile_max){
                ile_max=ile_2;
            }
            ile_2=0;
        }else if(a3.size() < b3.size()){
            for(int i=0; i<a3.size(); i++){
                if(a3[a3.size()-i]==b3[b3.size()-i]){
                    ile_2++;
                }
            }
            if(ile_2>ile_max){
                ile_max=ile_2;
            }

            ile_2=0;
        }
    }
    cout << ile_max << endl;
    while(in4 >> a4 >> b4){
        if(b4.size() <= a4.size()){
            for(int i=0; i<b4.size(); i++){
                if(a4[a4.size()-i]==b4[b4.size()-i]){
                    ile_2++;
                }
            }
            if(ile_2==ile_max){
                cout << a4 << " " << b4 << endl;
            }
            ile_2=0;
        }else if(a4.size() <= b4.size()){
            for(int i=0; i<a4.size(); i++){
                if(a4[a4.size()-i]==b4[b4.size()-i]){
                    ile_2++;
                }
            }
            if(ile_2==ile_max){
                cout << a4 << " " << b4 << endl;
            }
            ile_2=0;
        }
    }
    return 0;
}
