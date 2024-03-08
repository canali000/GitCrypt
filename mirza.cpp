#include<stdio.h>
#include<string.h>
#include<stdlib.h>

mirza_sifre (char *metin,char *key)
{
	int sifre;
	
    printf("sifrelemek istediginiz metni giriniz: ");
    gets(metin);
    
    printf("anahtarini gir: ");
    gets(key);
    
    FILE *dosya = fopen("sifreli_metin.txt", "w");
	 
	int kelime_boyutu=strlen(metin);
	int anahtar_boyutu=strlen(key);
	
	for(int i=0;i<kelime_boyutu;i++){
		char key_1=key[i%anahtar_boyutu];
		sifre=metin[i]+key_1;
		sifre%=128;
		fprintf(dosya, "%c", sifre);
		printf(" %c ",sifre);
		
	}
	fclose(dosya);
	printf("\n");
		
}

mirza_desifre(char *sifre, char *key) {
    int sifre_boyut = strlen(sifre);
    int key_boyut = strlen(key);
    for(int i = 0; i < sifre_boyut; i++) {
        int acilan_key = sifre[i] - key[i % key_boyut];
        acilan_key %= 128;
        printf("desifrelenmis metin:%c", (char)acilan_key);
    }
    printf("\n");
}


int main()
{	
	char metin[100];
	char key [100];
	char sifre[100];
	mirza_sifre(metin,key);
	mirza_desifre(sifre,key);
	
	
}
