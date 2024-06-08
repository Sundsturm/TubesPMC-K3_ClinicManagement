#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/workwithdata.h"

/* Prosedur untuk meng-assign tanggal, bulan, dan tahun ke */
void assignTanggal(char* str_t, Date* tanggal_t) {
	char *token;
	int num_t;

	token = strtok(str_t, " ");
	num_t = atoi(token);
	tanggal_t->hari = num_t;

	token = strtok(NULL, " ");
	strcpy(tanggal_t->bulan, token);

	token = strtok(NULL, " ");
	num_t = atoi(token);
	tanggal_t->tahun = num_t;
}

/* Prosedur untuk membaca CSV yang menyimpan data pasien */
void readCSVPasien(char *file, char *del, Pasien** list_pt) {
	/* Definisi variabel dan data yang dipakai untuk pembacaan CSV*/
	char* token;
	char lines[MAX_STRING];
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
		Date *temp_tanggal = malloc(sizeof(*temp_tanggal));
		char* temp_str[MAX_STRING] = NULL;
		int temp_num = 0;
		
		/* Membaca data baris pertama */
		if (*list_pt == NULL) {
			token = strtok(lines, del);
			temp_num = atoi(token);
			read_data->nomor = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->nama_lengkap, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->alamat, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->kota, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->tempat_lahir, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			read_data->tanggal_lahir = *temp_tanggal;
			
			token = strtok(NULL, del);
			temp_num = atoi(token);
			read_data->umur = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->bpjs, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->id_pasien, temp_str);

			read_data->next = NULL;
			read_data->prev = NULL;
			*list_pt = read_data;
			temp = *list_pt;
		}
		/* Membaca data untuk baris-baris selanjutnya*/
		else {
			while (temp->next != NULL) temp = temp->next;

			token = strtok(lines, del);
			temp_num = atoi(token);
			read_data->nomor = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->nama_lengkap, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->alamat, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->kota, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->tempat_lahir, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			read_data->tanggal_lahir = *temp_tanggal;
			
			token = strtok(NULL, del);
			temp_num = atoi(token);
			read_data->umur = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->bpjs, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->id_pasien, temp_str);

			read_data->prev = temp;
			temp->next = read_data;
			read_data->next = NULL;
		}

		free(&(read_data->tanggal_lahir));
		free(read_data);
	}

	/* Menutup file setelah pembacaan*/
	fclose(file);
}

/* Prosedur untuk membaca CSV yang menyimpan data diagnosis pasien */
void readCSVDiagnosis(char* file, char* del, Diagnosis** list_dx) {
	/* Definisi variabel dan data yang dipakai untuk pembacaan CSV*/
	char* token;
	char lines[MAX_STRING];
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
		Date *temp_tanggal = malloc(sizeof(Date));
		char* temp_str[MAX_STRING] = NULL;
		int temp_num = 0;

		/* Membaca data baris pertama */
		if (*list_dx == NULL) {
			token = strtok(lines, del);
			temp_num = atoi(token);
			read_data->nomor = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			(read_data)->tanggal_cek = *temp_tanggal;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->id_pasien, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->diagnosis, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->tindakan, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			read_data->tanggal_kontrol = *temp_tanggal;

			token = strtok(NULL, del);
			temp_num = atoi(token);
			read_data->biaya = temp_num;

			read_data->next = NULL;
			read_data->prev = NULL;
			*list_dx = read_data;
			temp = *list_dx;
		}
		/* Membaca data untuk baris-baris selanjutnya*/
		else {
			while (temp->next != NULL) temp = temp->next;

			token = strtok(lines, del);
			temp_num = atoi(token);
			read_data->nomor = temp_num;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			(read_data)->tanggal_cek = *temp_tanggal;

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->id_pasien, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->diagnosis, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			strcpy(read_data->tindakan, temp_str);

			token = strtok(NULL, del);
			strcpy(temp_str, token);
			assignTanggal(temp_str, temp_tanggal);
			read_data->tanggal_kontrol = *temp_tanggal;

			token = strtok(NULL, del);
			temp_num = atoi(token);
			read_data->biaya = temp_num;

			read_data->prev = temp;
			temp->next = read_data;
			read_data->next = NULL;
		}

		free(&(read_data->tanggal_cek));
		free(&(read_data->tanggal_kontrol));
		free(read_data);
	}

	/* Menutup file setelah pembacaan*/
	fclose(file);
}