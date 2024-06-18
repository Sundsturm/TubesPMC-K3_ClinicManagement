#ifndef __MANAJEMENTDATA_H__
#define __MANAJEMENDATA_H__
#include "workwithdata.h"

void TambahPasien(Pasien** list_pt, char *input_nama_lengkap, char *input_alamat, char* input_kota, char *input_tempat_lahir, char*input_tanggal_lahir, int input_umur, char* input_bpjs, int *count_px);
Pasien* NameSearch(Pasien* list_pt, char* nama_lengkap, int*found);
Pasien* IDSearch(Pasien* list_pt, char* id_pasien, int*found);
void UbahDataPasien(Pasien** list_pt, char *input, char *opsi, int pos);
void HapusDataPasien(Pasien** list_pt, int num);

void OpsiTindakan(BiayaPengobatan* list_tdk, int* biaya, char* pilihan);
void TambahDiag(Diagnosis** list_diag, BiayaPengobatan *list_tdk, char *tanggal_kunjungan, char *id_pasien, char *diagnosis, char *tindakan, int*count_diag);
Diagnosis* DateSearch(Diagnosis* list_diag, char *tanggal_kunjungan, int*found);
Diagnosis* DiagIDSearch(Diagnosis* list_diag, char *id_pasien, int*found);
void UbahDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk, char *input, char *opsi, int pos);
void HapusDataDiag(Diagnosis** list_diag, int num);

#endif