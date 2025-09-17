#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "util.h"
#include "menu.h"

void menu_lcr(int pilih){
	char *menu_arr[] = {"[1].Input UE LCR ","[2].Laporan LCR"};
	int ukuran_array = sizeof(menu_arr) / sizeof(menu_arr[0]);
	
	for(int i = 0; i < ukuran_array ; ++i){
		if(i == pilih -1){
			printf("\033[1;33m%s\033[0m",menu_arr[i]);
		}
		else{
			printf("\033[1;37m%s\033[0m", menu_arr[i]);
		}
	}
	printf("\n\n");

}

void menu_pilih_lcr(int pilihan_menu){
	clear_screen();
	header();
	menu_nav(1);
	menu_lcr(pilihan_menu);
}


void folder_lcr(){
	const char *path_folder_lcr  = "lib/lcr"; 
	if(mkdir(path_folder_lcr, 0755) == 0){
		printf("membuat %s\n",path_folder_lcr);
	}
	else{
		printf("membuka %s\n",path_folder_lcr);
	}
}

void inputan_ue(){
	folder_lcr();

	int cek = 3;

	while(1){
		char input_bulan[20];
		input_huruf(input_bulan,sizeof(input_bulan));
		bool valid = cek_bulan(input_bulan);
		if(valid == false){
			cetak("bulan tidak ditemukan\n","error");
			cek--;
		}

		printf("membuka %s ditemukan\n",input_bulan);


		if(cek == 0){break;}

	}	

}

//proses utama
void lcr(){
	int batasan = 3;
	menu_pilih_lcr(0);
	do{
	garis_batas(60,"-");
	cetak("Pilih Menu LCR : ","angka");
	fflush(stdout);
	int pilih_lcr =  input_angka();

	if(pilih_lcr > 2 || pilih_lcr < 0){
		cetak("Pilihan tidak ada !!\n","error");
		batasan-- ;
	}
	else if(pilih_lcr == 0){
		printf("kembali ke menu\n");
		break;
	}

	switch(pilih_lcr){
		//input ue lcr
		case 1 : {
				menu_pilih_lcr(1);
				printf("TODO INPUT UE LCR\n");
				inputan_ue();
				break;
			}

		case 2 : {
				menu_pilih_lcr(2);
				printf("TODO LAPORAN LCR\n");
				break;
			}

	}

	if(batasan == 0){
		printf("kembali ke menu\n");
	}
	}while(batasan != 0);
	header();
	menu_nav(0);
}