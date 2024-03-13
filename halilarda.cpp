#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    string dosyad = string(argv[1]);
    string sifreleme = string(argv[2]);
    string anahtar = "asfhudsf4775214sfsdaf65244s2f1a6dgds46a5fds1rh8y4rets21fa654fdw8r42f1vds6f54e8yt4sd1gf3da1fa6w8r4h2123daf1as8fw6ras2df1e45tga6s5dsaf1212g4jhbfhjaduhaoiwfkasjf98y9287hrisaf7821sf2134ucfsd";
    srand(static_cast<unsigned int>(time(0)));
 
    if (sifreleme == "on") {
        ifstream dosya(dosyad);
        if (!dosya) {
            cout << "Dosya bulunamadi." << endl;
            return 1;
        }

        string metin;
        getline(dosya, metin);
        dosya.close();

        ofstream outFile(dosyad);
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
    } else if (sifreleme == "off") {
        ifstream dosya(dosyad);
        if (!dosya) {
            cout << "Dosya bulunamadi." << endl;
            return 1;
        }

        string sifreMetni;
        getline(dosya, sifreMetni);
        dosya.close();

        ofstream outFile(dosyad);
        int sifreleyici;
        for (int i = 0; i < sifreMetni.length() / 5; i++) {
            char arr_anahtar = anahtar[i % (anahtar.length() / 7)];
            sifreleyici = sifreMetni[i * 5] - arr_anahtar;
            outFile << static_cast<char>(sifreleyici);
        }
        outFile.close();
    } else {
        cout << "Lutfen gecerli bir arguman giriniz. (on / off)" << endl;
        return 1;
    }
   

    return 0;
}