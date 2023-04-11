#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int ile_znakow(string a, char znak)
{
    int ile=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==znak){
            ile++;
        }
    }
    return ile;
}

int ile_spolglosk(string a)
{
    int ile=0;
    int ile_max=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!='A' && a[i]!='E' && a[i]!='I' && a[i]!='O' && a[i]!='U' && a[i]!='Y'){
            ile++;
            if(ile>ile_max){
                ile_max=ile;
            }
        }else{
            ile=0;
        }
    }
    return ile;
}

bool czy_takie_same_2(string a){
    for(int i=0; i<a.size()-1; i++){
        if(a[i] == a[i+1]){
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    string s[1876];
    int ile=0;
    ifstream in("tekst.txt");
    for(int i=0; i<1876; i++)
    {
        in>>s[i];
    }
    for(int i=0; i<1876; i++){
        if(czy_takie_same_2(s[i])){
            ile++;
        }
    }
    cout << "1." << endl;
    cout << ile << endl;
    cout << "2." << endl;
    int ile1=0;
    int ile2=0;
    double ileznakow=0;
    double z=1876;
    double g=0;
    string s1[1876];
    string s2[1876];
    ifstream in1("tekst.txt");
    ifstream in2("tekst.txt");
    for(int i=0; i<1876; i++)
    {
        in1>>s1[i];
    }


    for(char i='A'; i<='Z'; i++)
    {
        for(int j=0; j<1876; j++)
        {

            ile1=ile1+ile_znakow(s1[j],i);
        }
        ileznakow+=ile1;
        ile1=0;g=0;
    }

    for(int i=0; i<1876; i++)
    {
        in2>>s2[i];
    }
    for(char i='A'; i<='Z'; i++)
    {
        for(int j=0; j<1876; j++)
        {

            ile2=ile2+ile_znakow(s2[j],i);
        }
        g=(((ile2/ileznakow)*100));

        cout<<i<<" : "<<ile2<<fixed<<setprecision(2)<<" ("<<g<<" %)"<<endl;
        ile2=0;g=0;
    }

    int ile3=0;
    int ile4=0;
    int iletakich=0;
    int ile_max=0;
    int pierwsze=0;
    string s3[1876];
    string s4[1876];
    string pierwszeslowo;
    ifstream in3("tekst.txt");
    ifstream in4("tekst.txt");
    cout << "3." << endl;
    for(int i=0; i<1876; i++)
    {
        in3>>s3[i];
    }
    for(char i='A'; i<='Z'; i++)
    {
        for(int j=0; j<1876; j++)
        {

            ile3=ile_spolglosk(s3[j]);
            if(ile3>ile_max){
                ile_max=ile3;
            }
        }

    }

    for(int i=0; i<1876; i++)
    {
        in4>>s4[i];
    }
    for(char i='A'; i<='Z'; i++)
    {
        for(int j=0; j<1876; j++)
        {

            ile3=ile_spolglosk(s3[j]);
            if(ile3==ile_max){
                if(pierwsze==0){
                    pierwszeslowo=s3[j];
                    pierwsze++;
                }

                iletakich++;;
            }
        }

    }
    cout << ile_max <<" "<< iletakich << " " << pierwszeslowo << endl;

    return 0;
}
