#include <iostream>
#include <string>

using namespace std;

string sifre = "can"; // c++ tipi string
const char* cSifre = sifre.c_str(); // c tipi sabit dizi  
// cSifre size parametre olarak gelecek

// bu kod size verilen sabit diziyi eğer değiştirecekseniz
// yeni bir string dizisine atabilmeniz için  
int main()
{
            printf("sifre: %s\n", cSifre);
            
            // c tipi yeni değişken oluşturma
            int boyut = 100;
            char newSifre[100];
            for (int i = 0; i < boyut; i++)
            {
                newSifre[i] = cSifre[i];
            }
            printf("sifre: %s\n", newSifre);    
}      
