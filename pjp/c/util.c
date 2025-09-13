#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <menu.h>

void waktu(const char *pilih_waktu, char *output) {
	const char *hari[] ={"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

    time_t sekarang = time(NULL);
    struct tm *info = localtime(&sekarang);

    if (strcmp(pilih_waktu, "jam") == 0) {
        sprintf(output, "%02d:%02d:%02d", info->tm_hour, info->tm_min, info->tm_sec);
    } 
    else if (strcmp(pilih_waktu, "tanggal") == 0) {
        sprintf(output, "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
    } 

    else if (strcmp(pilih_waktu, "hari") == 0 ){
    	sprintf(output, "%s", hari[info -> tm_wday]);
    }
    else {
        strcpy(output, "??:??");
    }
}

void cetak(const char *pesan, const char *kondisi) {
    if (strcmp(kondisi, "angka") == 0) {
        printf("\033[1;33m%s\033[0m", pesan);  // Kuning terang
    } else if (strcmp(kondisi, "error") == 0) {
        printf("\033[1;31m%s\033[0m", pesan);  // Merah terang
    } else if (strcmp(kondisi, "open") == 0) {
        printf("\033[1;32%s\033[0m", pesan);  // Hijau terang
    } else {
        printf("%s\n", pesan);  // Tanpa warna
    }
}


int input_angka(){

    char buffer[100];
    int value;

    if(fgets(buffer, sizeof(buffer),stdin) == NULL ){
        cetak("Inputan tidak valid!", "error");
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    int valid = 1;
        for (int i = 0; buffer[i]; i++) {
            if (!isdigit(buffer[i]) && !(i == 0 && buffer[i] == '-')) {
                valid = 0;
                break;
            }
        }

        if(!valid){
            cetak("Inputan tidak valid!", "error");
            return -1;
        }

    sscanf(buffer,"%d",&value);

return value;
}



void garis_batas(int panjang, const char *karakter){
	for (int i = 0 ; i < panjang ; ++i){
		printf("%s", karakter);
	}
	printf("\n");
}

void clear_screen() {
    printf("\033[2J\033[H");
}
