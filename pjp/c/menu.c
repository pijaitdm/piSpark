#include <stdio.h>
#include <string.h>
#include "util.h"

void header(){
	char hari[8]; 
	char tanggal[12];
	char header_str[65];

	waktu("hari",hari);
	waktu("tanggal",tanggal); 

	sprintf(header_str,"|| %s || PJ Project Management Bengkel || %s ||\n",hari,tanggal);
	
	garis_batas(strlen(header_str),"-");
	printf("\033[036m%s\033[0m", header_str);
	garis_batas(strlen(header_str),"-");
	printf("\n");
}

void menu_nav(int pilih){
	char *menu_arr[] = {"[1].LCR ","[2].LBB ","[3].SPAREPART ","[4].TOOLS ","[5].HOME "};
	char keluar[]= "[0].KELUAR ";
	int ukuran_array = sizeof(menu_arr) / sizeof(menu_arr[0]);
	
	for(int i = 0; i < ukuran_array ; ++i){
		if(i == pilih -1){
			printf("\033[1;33m%s\033[0m",menu_arr[i]);
		}
		else{
			printf("\033[1;37m%s\033[0m", menu_arr[i]);
		}
	}

	printf("\033[37m%s\033[0m", keluar);
	printf("\n \n");
}

void menu_pilih(int pilihan_menu){
	clear_screen();
	header();
	menu_nav(pilihan_menu);
}

void menu_utama(){


	int batasan_input = 3;
	int pilihan = 0;
	menu_pilih(pilihan);
	do{

		cetak("Pilih Menu : ", "angka");
		int pilih_menu = input_angka();
		fflush(stdout);

			if(pilih_menu > 5 || pilih_menu < 0){
				cetak("Pilihan tidak ada !!\n","error");
				batasan_input--;
			}
			else if(pilih_menu == 0){
				printf("Keluar, ");
				break;
			}


		switch(pilih_menu){
			case 1 :
				pilihan = 1;
				menu_pilih(pilihan);
				printf("INI MENU 1\n");
				break;
			case 2 :
				pilihan = 2;
				menu_pilih(pilihan);
				printf("INI MENU 2\n");
				break;
			case 3 :
				pilihan = 3;
				menu_pilih(pilihan);
				printf("INI MENU 3\n");
				break;
			case 4 :
				pilihan = 4;
				menu_pilih(pilihan);
				printf("INI MENU 4\n");
				break;
			case 5 :
				pilihan = 5;
				menu_pilih(pilihan);
				printf("INI MENU 5\n");
				break;					
		}

		}while(batasan_input != 0);
}
