//EL2008 - Pemecahan Masalah dengan C 2023/2024
//Topik				: Tugas Besar - Clinic Management
//Kelompok/Kelas	: 03/02
//Nama File			: main.c
//Deskripsi			: Program utama atau main hub dari aplikasi manajemen data klinik

// Import header
#include "../lib/include/includeall.h"

// Program utama
int main() {
	// Define and read datas
	Pasien *list_pasien = NULL;
	Diagnosis *list_diagnosis = NULL;
	BiayaPengobatan *list_biayapengobatan = NULL;
	readPasienData("../resources/DataPMC20232024(1).csv", &list_pasien);
	readDiagnosisData("../resources/DataPMC20232024(2).csv", &list_diagnosis);
	readBiayaPengobatanData("../resources/DataPMC20232024(3).csv", &list_biayapengobatan);

	// Fitur Petugas Medis: Pasien dan Riwayat Medis
	informasiPasienRiwayatMedis(list_pasien, list_diagnosis);

	// Fitur Petugas Medis: Pasien dan Kontrol
	PasienForKontrol(list_pasien, list_diagnosis);

	// Fitur: Laporan Pendapatan
	rataRataPendapatan(list_diagnosis, list_biayapengobatan);
	return 0;
}
