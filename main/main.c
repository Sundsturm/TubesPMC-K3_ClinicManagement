//EL2008 - Pemecahan Masalah dengan C 2023/2024
//Topik				: Tugas Besar - Clinic Management
//Kelompok/Kelas	: 03/02
//Nama File			: main.c
//Deskripsi			: Program utama atau main hub dari aplikasi manajemen data klinik

// Import headers
#include "../lib/include/workwithdata.h"
#include <stdio.h>
#include <stdlib.h>

// Program utama
int main() {
    // Tulis kode di sini!
	Pasien *list_pasien = NULL;
	Diagnosis *list_diagnosis = NULL;
	readCSVPasien("resources/DataPMC20232024(1).csv", &list_pasien);
	readCSVDiagnosis("resources/DataPMC20232024(2).csv", &list_diagnosis);
	printPasien(list_pasien);
	printDiagnosis(list_diagnosis);
	return 0;
}
