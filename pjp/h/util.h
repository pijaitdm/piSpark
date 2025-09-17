#ifndef UTIL_H
#define UTIL_H

void waktu(const char *pilih_waktu, char *output);
void garis_batas(int panjang, const char *karakter);
void cetak(const char *pesan, const char *warnai);
int input_angka();
void input_huruf(char *input, size_t size);
bool cek_bulan(const char *pilih_bulan);
void clear_screen();



#endif