#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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
        printf("\033[1;32m%s\033[0m", pesan);  // Hijau terang
    } else {
        printf("%s\n", pesan);  // Tanpa warna
    }
}

//input int
int input_angka() {
       char buffer[100];
    int value;

    fflush(stdout);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Input gagal!\n");
        return -1;
    }

    // Hapus newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // Validasi: hanya angka (boleh negatif di awal)
    int valid = 1;
    for (int i = 0; buffer[i]; i++) {
        if (!isdigit(buffer[i]) && !(i == 0 && buffer[i] == '-')) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("Input bukan angka!\n");
        return -1;
    }

    // Konversi ke integer
    sscanf(buffer, "%d", &value);
    return value;
}

//input string
void input_huruf(char *input, size_t size) {
    cetak("untuk Bulan : ", "open");
    fflush(stdout);

    if (fgets(input, size, stdin)) {
        input[strcspn(input, "\n")] = 0;  // Hapus newline
    } else {
        cetak("input gagal\n", "error");
        input[0] = '\0';  // Kosongkan string
    }
}




bool cek_bulan(const char *pilih_bulan){
    char *bulan[12]= {
        "januari","februari","maret","april","mei","juni","juli",
        "agustus","september","oktober","november","desember"};
    int cek;
    int ukuran_bulan = sizeof(bulan) / sizeof(bulan[0]);
    for(int i = 0 ; i < ukuran_bulan ; i++){
        if(strcmp(bulan[i],pilih_bulan) ==0){
            cek = 1;
            break;
        }
    }
    if(cek == 1){
        return true;
    }
    return false;
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
