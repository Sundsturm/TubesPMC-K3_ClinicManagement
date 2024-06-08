#ifndef __WORKWITHDATA_H__
#define __WORKWITHDATA_H__
#define MAX_STRING 256
#define MAX_MONTH 10

/* Struktur data yang digunakan untuk pembacaan CSV*/
typedef struct Date {
	int hari;
	char bulan[MAX_MONTH];
	int tahun;
} Date;

typedef struct Pasien {
	int nomor;
	char nama_lengkap[MAX_STRING];
	char alamat[MAX_STRING];
	char kota[MAX_STRING];
	char tempat_lahir[MAX_STRING];
	Date tanggal_lahir;
	int umur;
	char bpjs[MAX_STRING];
	char id_pasien[MAX_STRING];
	struct Pasien* next;
	struct Pasien* prev;
} Pasien;

typedef struct Diagnosis {
	int nomor;
	Date tanggal_cek;
	char id_pasien[MAX_STRING];
	char diagnosis[MAX_STRING];
	char tindakan[MAX_STRING];
	Date tanggal_kontrol;
	int biaya;
	struct Diagnosis* next;
	struct Diagnosis* prev;
} Diagnosis;

void assignTanggal(char* str_t, Date* tanggal_t);
void readCSVPasien(char* file, char* del, Pasien** list_pt);
void readCSVDiagnosis(char* file, char* del, Diagnosis** list_dx);
void printPasien(Pasien *list_pt);
void print(Pasien *list_pt);

#endif