#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mirza(char *metin, char *key, char *sifrelemeturu)
{
	if (strcmp(sifrelemeturu, "on") == 0)
	{
		int sifre;
		int metin_boyutu = strlen(metin);
		int anahtar_boyutu = strlen(key);

		FILE *dosya = fopen("sifreli_metin.txt", "w");

		for (int i = 0; i < metin_boyutu; i++)
		{
			char key_1 = key[i % anahtar_boyutu];
			sifre = metin[i] + key_1;
			sifre %= 65535;
			fprintf(dosya, "%c", sifre);
			printf("%c", sifre);
		}
		fclose(dosya);
		printf("\n");
	}
	else{
		FILE *dosya = fopen("sifreli_metin.txt", "r");
		char sifrelenmisMetin[100];
		fgets(sifrelenmisMetin, 100, dosya);
		fclose(dosya);

		int acilan_sifre;
		int sifre_boyut = strlen(sifrelenmisMetin);
		int key_boyut = strlen(key);

		dosya = fopen("sifreli_metin.txt", "w");

		for (int i = 0; i < sifre_boyut; i++)
		{
			char key_2 = key[i % key_boyut];
			acilan_sifre = sifrelenmisMetin[i] - key_2;
			acilan_sifre %= 65535;
			fprintf(dosya, "%c", acilan_sifre);
			printf("%c", acilan_sifre);
		}
		fclose(dosya);
		printf("\n");
	}
}



int main()
{
	char metin[100] = "test text XDDD";
	char key[100] = "asdöçşiğü";
	char sifrelemeturu[100] = "on";

	mirza(metin, key, sifrelemeturu);	

}