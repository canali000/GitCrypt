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
void halil(string sifre, string dosyaad, string sifreleme)
{

    string anahtar = "asfhudsf4775214sfsdaf65244s2f1a6dgds46a5fds1rh8y4rets21fa654fdw8r42f1vds6f54e8yt4sd1gf3da1fa6w8r4h2123daf1as8fw6ras2df1e45tga6s5dsaf1212g4jhbfhjaduhaoiwfkasjf98y9287hrisaf7821sf2134ucfsd";
    srand(static_cast<unsigned int>(time(0)));
 
    if (sifreleme == "on") {
        ifstream dosya(dosyaad);
        if (!dosya) {
            cout << "Dosya bulunamadi." << endl;
           
        }
        else{
        string metin;
        getline(dosya, metin);
        dosya.close();

        ofstream outFile(dosyaad);
        int sifreleyici;
        for (int i = 0; i < metin.length() * 5; i++) {
            if (i % 5 == 0) {
                char arr_anahtar = anahtar[(i / 5) % (anahtar.length() / 7)];
                sifreleyici = metin[i / 5] + arr_anahtar;
                outFile << static_cast<char>(sifreleyici);
            } else {
                sifreleyici = (rand() % 150) + 64;
                outFile << static_cast<char>(sifreleyici);
            }
        }
        outFile.close();
    }} else if (sifreleme == "off") {
        ifstream dosya(dosyaad);
        if (!dosya) {
            cout << "Dosya bulunamadi." << endl;
        }
        else {
        string sifreMetni;
        getline(dosya, sifreMetni);
        dosya.close();

        ofstream outFile(dosyaad);
        int sifreleyici;
        for (int i = 0; i < sifreMetni.length() / 5; i++) {
            char arr_anahtar = anahtar[i % (anahtar.length() / 7)];
            sifreleyici = sifreMetni[i * 5] - arr_anahtar;
            outFile << static_cast<char>(sifreleyici);
        }
        outFile.close();
    }
    }}
   
void sila(string sifre, string dosya, string sifreleme)
{
    cout << "Sila calisti" << endl; 
    cout << sifre << endl;
    cout << dosya << endl;
    cout << sifreleme << endl;
}