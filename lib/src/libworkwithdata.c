#include "../include/standardclib.h"
#include "../include/workwithdata.h"

/* Prosedur untuk meng-assign tanggal, bulan, dan tahun ke struct tanggal*/
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
void readPasienData(const char* filename, Pasien **list_px) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File tidak bisa dibuka!");
        return;
    }

    Pasien* head = NULL;
    Pasien* tail = NULL;
    char line[512];
    fgets(line, sizeof(line), file);  // Skip the header line

    while (fgets(line, sizeof(line), file)) {
        Pasien* newPasien = (Pasien*)malloc(sizeof(Pasien));
        char tanggal_lahir[30];
        sscanf(line, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%[^;];%[^\n]",
               &newPasien->nomor, newPasien->nama_lengkap, newPasien->alamat,
               newPasien->kota, newPasien->tempat_lahir, tanggal_lahir,
               &newPasien->umur, newPasien->bpjs, newPasien->id_pasien);

        assignTanggal(tanggal_lahir, &(newPasien->tanggal_lahir));
        newPasien->next = NULL;
        newPasien->prev = tail;

        if (tail) {
            tail->next = newPasien;
        } else {
            head = newPasien;
        }
        tail = newPasien;
    }

    fclose(file);
    *list_px = head;
}
 
/* Prosedur untuk membaca CSV yang menyimpan data diagnosis pasien */
void readDiagnosisData(const char* filename, Diagnosis **list_dx) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File tidak bisa dibuka!");
        return;
    }

    Diagnosis* head = NULL;
    Diagnosis* tail = NULL;
    char line[512];
    fgets(line, sizeof(line), file);  // Skip the header line

    while (fgets(line, sizeof(line), file)) {
        Diagnosis* newDiagnosis = (Diagnosis*)malloc(sizeof(Diagnosis));
        char tanggal_cek[30], tanggal_kontrol[30];
        sscanf(line, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d",
               &newDiagnosis->nomor, tanggal_cek, newDiagnosis->id_pasien,
               newDiagnosis->diagnosis, newDiagnosis->tindakan,
               tanggal_kontrol, &newDiagnosis->biaya);

		assignTanggal(tanggal_cek, &(newDiagnosis->tanggal_cek));
		assignTanggal(tanggal_kontrol, &(newDiagnosis->tanggal_kontrol));
        newDiagnosis->next = NULL;
        newDiagnosis->prev = tail;

        if (tail) {
            tail->next = newDiagnosis;
        } else {
            head = newDiagnosis;
        }
        tail = newDiagnosis;
    }

    fclose(file);
	*list_dx = head;
}

/* Prosedur untuk membac CSV yng menyimpan data biaya*/
void readBiayaPengobatanData(const char* filename, BiayaPengobatan **list_biaya) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File tidak bisa dibuka!\n");
        return;
    }

    BiayaPengobatan* head = NULL;
    BiayaPengobatan* tail = NULL;
    char line[512];
    fgets(line, sizeof(line), file);  // Skip the header line

    while (fgets(line, sizeof(line), file)) {
        BiayaPengobatan* newBiayaPengobatan = (BiayaPengobatan*)malloc(sizeof(BiayaPengobatan));
        sscanf(line, "%d;%[^;];%d",
               &newBiayaPengobatan->nomor, newBiayaPengobatan->aktivitas, &newBiayaPengobatan->biaya);

        newBiayaPengobatan->next = NULL;
        newBiayaPengobatan->prev = tail;

        if (tail) {
            tail->next = newBiayaPengobatan;
        } else {
            head = newBiayaPengobatan;
        }
        tail = newBiayaPengobatan;
    }

    fclose(file);
    *list_biaya = head;
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

void printBiayaPengobatan(BiayaPengobatan *list_biaya){
	BiayaPengobatan *temp = list_biaya;
	if(temp == NULL){
		printf("Data kosong!\n");
		return;
	}
	while(temp != NULL){
		printf("%d, %s, %d\n", temp->nomor, temp->aktivitas, temp->biaya);
		temp = temp->next;
	}
	printf("\n");
}

void countLenPasien(Pasien *list_pt, int *a){
    Pasien *temp = list_pt;
	if (temp == NULL){
		printf("Data kosong!\n");
		return;
	}
	while(temp != NULL){
        temp = temp->next;
        (*a) = (*a) + 1;
    }
}

void countLenDiagnosis(Diagnosis *list_dt, int *a){
    Diagnosis *temp = list_dt;
	if (temp == NULL){
		printf("Data kosong!\n");
		return;
	}
	while(temp != NULL){
        temp = temp->next;
        (*a) = (*a) + 1;
    }
}

void free_pasien_list(Pasien* head) {
    Pasien* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void free_diagnosis_list(Diagnosis* head) {
    Diagnosis* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}