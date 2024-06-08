#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/workwithdata.h"

/* Prosedur untuk meng-assign tanggal, bulan, dan tahun ke */
void assignTanggal(char *str_t, Date* tanggal_t) {
	char *saveptr;
	char *temp_string;
	
	// Membaca hari
	temp_string = strtok_r(str_t, " ", &saveptr);
	tanggal_t->hari = atoi(temp_string);

	// Membaca bulan
	temp_string = strtok_r(NULL, " ", &saveptr);
	strcpy(tanggal_t->bulan, temp_string);

	// Membaca tahun
	temp_string = strtok_r(NULL, " ", &saveptr);
	tanggal_t->tahun = atoi(temp_string);
}
 
/* Prosedur untuk membaca CSV yang menyimpan data pasien */
void readCSVPasien(char *file, Pasien** list_pt) {
	/* Definisi variabel dan data yang dipakai untuk pembacaan CSV*/
	char* token;
	char lines[MAX_STRING];
	char del[2] = ";";
	Pasien* temp = NULL;
 
	/* Membuka file */
	FILE* file_path = fopen(file, "r");
 
	/* Cek kebenaran file input */
	if (!file_path) {
		printf("File tidak bisa dibuka.\n");
		return;
	}
 
	/* Membaca baris pertama yang berisi keterangan data CSV*/
	fgets(lines, MAX_STRING, file_path);
	strtok(lines, del);
 
	/* Membaca data dengan loop */
	while (fgets(lines, MAX_STRING, file_path)) {
		/* Variabel sementara untuk membaca data baru*/
		Pasien* read_data = malloc(sizeof(*read_data));
		Date temp_tanggal;

		/* Pembacaan data dan assign data ke read_data*/
		// Nomor
		token = strtok(lines, del);
		read_data->nomor = atoi(token);

		// Nama Lengkap
		token = strtok(NULL, del);
		strcpy(read_data->nama_lengkap, token);

		// Alamat
		token = strtok(NULL, del);
		strcpy(read_data->alamat, token);

		// Kota
		token = strtok(NULL, del);
		strcpy(read_data->kota, token);
		
		// Tempat Lahir
		token = strtok(NULL, del);
		strcpy(read_data->tempat_lahir, token);

		// Tanggal Lahir
		token = strtok(NULL, del);
		assignTanggal(token, &temp_tanggal);
		read_data->tanggal_lahir = temp_tanggal;

		// Umur
		token = strtok(NULL, del);
		read_data->umur = atoi(token);

		// BPJS
		token = strtok(NULL, del);
		strcpy(read_data->bpjs, token);

		// ID Pasien
		token = strtok(NULL, del);
		strcpy(read_data->id_pasien, token);

		/* Membaca data baris pertama */
		if (*list_pt == NULL) {
			read_data->next = NULL;
			read_data->prev = NULL;
			*list_pt = read_data;
			temp = *list_pt;
		}
		/* Membaca data untuk baris-baris selanjutnya*/
		else {
			while (temp->next != NULL) temp = temp->next;
			read_data->prev = temp;
			temp->next = read_data;
			read_data->next = NULL;
		}
	}

	/* Menutup file setelah pembacaan*/
	fclose(file_path);
}
 
/* Prosedur untuk membaca CSV yang menyimpan data diagnosis pasien */
void readCSVDiagnosis(char* file, Diagnosis** list_dx) {
	/* Definisi variabel dan data yang dipakai untuk pembacaan CSV*/
	char* token;
	char lines[MAX_STRING];
	char del[2] = ";";
	Diagnosis* temp = NULL;
 
	/* Membuka file */
	FILE* file_path = fopen(file, "r");
 
	/* Cek kebenaran file input */
	if (!file_path) {
		printf("File tidak bisa dibuka.\n");
		return;
	}
 
	/* Membaca baris pertama yang berisi keterangan data CSV*/
	fgets(lines, MAX_STRING, file_path);
	strtok(lines, del);
 
	/* Membaca data dengan loop */
	while (fgets(lines, MAX_STRING, file_path)) {
		/* Variabel sementara untuk membaca data baru*/
		Diagnosis* read_data = malloc(sizeof(*read_data));
		Date temp_tanggal;
		
		/* Membaca data dan assign ke read_data */
		// Nomor
		token = strtok(lines, del);
		read_data->nomor = atoi(token);

		// Tanggal Cek
		token = strtok(NULL, del);
		assignTanggal(token, &temp_tanggal);
		(read_data)->tanggal_cek = temp_tanggal;

		// ID Pasien
		token = strtok(NULL, del);
		strcpy(read_data->id_pasien, token);

		// Diagnosis
		token = strtok(NULL, del);
		strcpy(read_data->diagnosis, token);

		// Tindakan
		token = strtok(NULL, del);
		strcpy(read_data->tindakan, token);

		// Tanggal Kontrol
		token = strtok(NULL, del);
		assignTanggal(token, &temp_tanggal);
		read_data->tanggal_kontrol = temp_tanggal;

		// Biaya
		token = strtok(NULL, del);
		read_data->biaya = atoi(token);

		/* Membaca data baris pertama */
		if (*list_dx == NULL) {
			read_data->next = NULL;
			read_data->prev = NULL;
			*list_dx = read_data;
			temp = *list_dx;
		}
		/* Membaca data untuk baris-baris selanjutnya*/
		else {
			while (temp->next != NULL) temp = temp->next; 
			read_data->prev = temp;
			temp->next = read_data;
			read_data->next = NULL;
		}
	}
 
	/* Menutup file setelah pembacaan*/
	fclose(file_path);
}

void printPasien(Pasien *list_pt){
	Pasien *temp = list_pt;
	if (temp == NULL){
		printf("Data kosong!\n");
		return;
	}
	while(temp != NULL){
		printf("%d, %s, %s, %s, %s, %d %s %d, %d, %s, %s\n",
		temp->nomor, temp->nama_lengkap, temp->alamat, temp->kota, temp->tempat_lahir,
		temp->tanggal_lahir.hari, temp->tanggal_lahir.bulan, temp->tanggal_lahir.tahun,
		temp->umur, temp->bpjs, temp->id_pasien);
		temp = temp->next;
	}
	printf("\n");
}

void printDiagnosis(Diagnosis *list_dx){
	Diagnosis *temp = list_dx;
	if (temp == NULL){
		printf("Data kosong!\n");
		return;
	}
	while(temp != NULL){
		printf("%d, %d %s %d, %s, %s, %s, %d %s %d, %d\n",
		temp->nomor,
		temp->tanggal_cek.hari, temp->tanggal_cek.bulan, temp->tanggal_cek.tahun,
		temp->id_pasien, temp->diagnosis, temp->tindakan,
		temp->tanggal_kontrol.hari, temp->tanggal_kontrol.bulan, temp->tanggal_kontrol.tahun,
		temp->biaya);
		temp = temp->next;
	}
	printf("\n");
}