#include <iostream>
#include <string>

using namespace std;

// function prototype

void can(string dosya, string sifreleme);
void mirza(string dosya, string sifreleme);
void halil(string dosya, string sifreleme);
void sila(string dosya, string sifreleme);

int main(int argc, char *argv[])
{

    if (argc == 4){
            string dosya = argv[1];
            string ogrenci = argv[2];
            string sifreleme = argv[3];
            
            if (ogrenci == "can"){
                can(dosya,sifreleme);
            } 
            else if (ogrenci == "mirza"){
                mirza(dosya,sifreleme);
            } 
            else if (ogrenci == "halil"){
                halil(dosya,sifreleme);
            } 
            else if (ogrenci == "sila"){
                sila(dosya,sifreleme);
            } 
            else{
                cout << "4 ogrenciden birinin adini girmeniz gerek" << endl;
                cout << "(can/mirza/halil/sila)";
            }
    }
    else if (argc < 4){
        cout << "Eksik arguman girdiniz";
    }
    else{
        cout << "Fazladan arguman girdiniz\n";
        cout << "Dosya ismiyle birlikte maksimum 4 arguman girilebilir";
    }


    return 0;
}

// prototype

void can(string dosya, string sifreleme)
{
    cout << "Can calisti" << endl; 
    cout << dosya << endl;
    cout << sifreleme << endl;
}
void mirza(string dosya, string sifreleme)
{
    cout << "Mirza calisti" << endl; 
    cout << dosya << endl;
    cout << sifreleme << endl;
}
void halil(string dosya, string sifreleme)
{
    cout << "Halil calisti" << endl; 
    cout << dosya << endl;
    cout << sifreleme << endl;
}
void sila(string dosya, string sifreleme)
{
    cout << "Sila calisti" << endl; 
    cout << dosya << endl;
    cout << sifreleme << endl;
}

