#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

void encode(string sifre, string dosya, string sifreleme){
    ifstream existFile(dosya);
    ifstream checkFile("check.txt");
    if (existFile.is_open() and checkFile.is_open()){
        existFile.close();
        checkFile.close();
    }
    else{
        cout << dosya << " dosyasi olusturuldu." << endl;
        ofstream createTextFile(dosya);
        createTextFile << "Ornek Metin";
        createTextFile.close();

        ofstream createCheckFile("check.txt");
        createCheckFile << "-1\n";
        createCheckFile << "0";
        createCheckFile.close();
    }

    unsigned int key = 0;
    for (int i = 0; i < sifre.length(); i++){
       key += sifre[i];
    }
    srand(key);

    ifstream inputFile("check.txt");
    int checkCode;
    int checkKey;
    string line1, line2;
    getline(inputFile, line1);
    getline(inputFile, line2);
    checkCode = stoi(line1);
    checkKey = stoi(line2);
    inputFile.close();

    if (checkCode == -1 and sifreleme =="off"){
        cout <<"Bu dosya daha once sifrelenmedi." << endl;
        cout <<"Dosya sifrelenmeye hazir." << endl;
    }
    else if (checkCode == 1 and sifreleme =="on"){
        cout <<"Bu dosya daha once sifrelenmis." << endl;
        cout <<"Dosya desifrelenmeye hazir." << endl;
    }
    else if (checkKey != key and sifreleme == "off"){
        cout << "Yanlis sifre girdiniz." << endl;
        cout << "Icerik siliniyor." << endl;
        ofstream deleteContent(dosya);
        deleteContent << "";
        deleteContent.close();
        ofstream resetCheck("check.txt");
        resetCheck << "-1" << endl;
        resetCheck << "0" << endl;
        resetCheck.close();
        
    }
    else{

        string data;
        ifstream myFile(dosya);
        getline(myFile, data);
        myFile.close();


        char chart[] = {' ', '!', '"', '#', '$', '%', '&', '\'',
                        '(', ')', '*', '+', ',', '-', '.', '/',
                        '0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', ':', ';', '<', '=', '>', '?',
                        '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                        'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
                        '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                        'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                        'x', 'y', 'z', '{', '|', '}', '~','\n'};
        
        int size = sizeof(chart)/sizeof(char);
        int fileLen = data.length();
        int jump[fileLen];
        for(int i = 0; i < fileLen; i++){
            jump[i] = rand();
        }
        if (sifreleme == "off"){
            for (int i = 0; i < sizeof(jump) / sizeof(int); i++)
            {
                jump[i] = -jump[i];
            }
        }

        string crypted = "";
        for(int i = 0; i < fileLen; i++){
            char letter = data[i];
            char *result = find(begin(chart), end(chart), letter);
            if (result != end(chart))
            {
                int position = result - chart;
                position += jump[i];
                position %= size;
                if (position < 0){
                    position += size;
                } 
                char newChar = chart[position];
                crypted += newChar; 
            }
            else{
                cout << "***";
            }
    }
        ofstream writeFile(dosya);
        writeFile << crypted;
        writeFile.close();

        ofstream updateCheck("check.txt");
        checkCode *= -1;
        updateCheck << to_string(checkCode) << endl; 
        updateCheck << to_string(key) << endl; 
        updateCheck.close();
}
}

int main(){

    string password = "canali";
    string fileName = "can.txt";
    string encodeType = "off";
    encode(password, fileName, encodeType);
}

