#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// function prototype

void can(string sifre, string dosya, string sifreleme);
void mirza(const char* cSifre, const char* cDosya, const char* cSifreleme);
void halil(string sifre, string dosya, string sifreleme);
void sila(string sifre, string dosya, string sifreleme);

int main(int argc, char *argv[])
{

    if (argc == 5){
            string sifre = argv[1];
            string dosya = argv[2];
            string ogrenci = argv[3];
            string sifreleme = argv[4];
            
            if (ogrenci == "can"){
                can(sifre, dosya, sifreleme);
            } 
            else if (ogrenci == "mirza"){
                const char* cSifre = sifre.c_str();
                const char* cDosya = dosya.c_str();
                const char* cSifreleme = sifreleme.c_str();
                mirza(cSifre, cDosya, cSifreleme);
            } 
            else if (ogrenci == "halil"){
                halil(sifre, dosya, sifreleme);
            } 
            else if (ogrenci == "sila"){
                sila(sifre, dosya, sifreleme);
            } 
            else{
                cout << "4 ogrenciden birinin adini girmeniz gerek" << endl;
                cout << "(can/mirza/halil/sila)";
            }
    }
    else if (argc < 5){
        cout << "Eksik arguman girdiniz";
    }
    else{
        cout << "Fazladan arguman girdiniz\n";
        cout << "Dosya ismiyle birlikte maksimum 4 arguman girilebilir";
    }


    return 0;
}

// prototype

void can(string sifre, string dosya, string sifreleme)
{
    cout << "Can calisti" << endl; 
    cout << sifre << endl;
    cout << dosya << endl;
    cout << sifreleme << endl;
}
void mirza(const char* cSifre, const char* cDosya, const char* cSifreleme)
{
    printf("Mirza calisti\n"); 
    printf("%s\n",cSifre);
    printf("%s\n",cDosya);
    printf("%s\n",cSifreleme);
}
void halil(string sifre, string dosya, string sifreleme)
{
    cout << "Halil calisti" << endl; 
    cout << sifre << endl;
    cout << dosya << endl;
    cout << sifreleme << endl;
}
void sila(string sifre, string dosya, string sifreleme)
{
    cout << "Sila calisti" << endl; 
    cout << sifre << endl;
    cout << dosya << endl;
    cout << sifreleme << endl;
}

