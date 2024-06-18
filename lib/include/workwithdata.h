#ifndef __WORKWITHDATA_H__
#define __WORKWITHDATA_H__
#define MAX_STRING 256
#define MAX_MONTH 20

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
typedef struct BiayaPengobatan {
    int nomor;
    char aktivitas[MAX_STRING];
    int biaya;
    struct BiayaPengobatan* next;
    struct BiayaPengobatan* prev;
} BiayaPengobatan;

void assignTanggal(char* str_t, Date* tanggal_t);
void readPasienData(const char* filename, Pasien **list_px);
void readDiagnosisData(const char* filename, Diagnosis **list_dx);
void readBiayaPengobatanData(const char* filename, BiayaPengobatan **list_biaya);
void printPasien(Pasien *list_pt);
void printDiagnosis(Diagnosis *list_dx);
void printBiayaPengobatan(BiayaPengobatan *list_biaya);
void countLenPasien(Pasien *list_pt, int *a);
void countLenDiagnosis(Diagnosis *list_dt, int *a);
void free_pasien_list(Pasien* head);
void free_diagnosis_list(Diagnosis* head);
void writeCSVPasien(char* file, Pasien* list_pt);
void writeCSVDiagnosis(char* file, Diagnosis* list_diag);
#endif