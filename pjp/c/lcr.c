#include <stdio.h>
#include <string.h>
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

void lcr(){
int batasan = 3;
menu_pilih_lcr(1);
do{

int pilih_lcr = input_angka();

			if(pilih_lcr > 2 || pilih_lcr < 0){
				cetak("Pilihan tidak ada !!\n","error");
				batasan-- ;
			}
			else if(pilih_lcr == 0){
				printf("kembali ke menu\n");
				break;
			}

	switch(pilih_lcr){
		case 1 : {
			menu_pilih_lcr(1);
			printf("TODO INPUT UE LCR\n");
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

}