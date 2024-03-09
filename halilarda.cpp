#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <cstdlib>
#include <time.h>

int main()
{
	char sifreleme[4] = "on";
    char anahtar[5000] = "asfhudsf4775214sfsdaf65244s2f1a6dgds46a5fds1rh8y4rets21fa654fdw8r42f1vds6f54e8yt4sd1gf3da1fa6w8r4h2123daf1as8fw6ras2df1e45tga6s5dsaf1212g4jhbfhjaduhaoiwfkasjf98y9287hrisaf7821sf2134ucfsd";
	srand(static_cast<unsigned int>(time(0)));

	if (strcmp(sifreleme, "on") == 0)
	{   		
		FILE *dosya = fopen("sifreleme.txt", "r");
        char metin[5000];
		fgets(metin, 5000, dosya);
		dosya = fopen("sifreleme.txt", "w");
        int sifreleyici;
		for (int i = 0; i < strlen(metin) * 5; i++)
		{
			if(i % 5 == 0){
            char arr_anahtar = anahtar[(i / 5) % (strlen(anahtar) / 7)];
			sifreleyici = metin[i / 5] + arr_anahtar;
			fprintf(dosya, "%c", sifreleyici);
		}
        else{
         sifreleyici = (rand() % 150) + 64;
         fprintf(dosya, "%c", sifreleyici);
        }}
		fclose(dosya);
	}
	else if(strcmp(sifreleme, "off") == 0){
		FILE *dosya = fopen("sifreleme.txt", "r");
		char sifreMetni[5000];
		fgets(sifreMetni, 5000, dosya);
		int sifreleyici;
		dosya = fopen("sifreleme.txt", "w");

		for (int i = 0; i < strlen(sifreMetni) / 5; i++)
		{
			char arr_anahtar = anahtar[i % (strlen(anahtar) / 7)];
			sifreleyici = sifreMetni[i * 5] - arr_anahtar;
			fprintf(dosya, "%c", sifreleyici);
		}
		fclose(dosya);
	}
	else{
		printf("Lutfen gecerli bir arguman giriniz. (On / Off)");
	}	
 return 0;
}