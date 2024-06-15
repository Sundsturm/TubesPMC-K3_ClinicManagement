#ifndef __MANAJEMENTDATA_H__
#define __MANAJEMENDATA_H__
#include "workwithdata.h"

void TambahPasien(Pasien** list_pt);
void NameSearch(Pasien** list_pt);
void IDSearch(Pasien** list_pt);
void CariPasien(Pasien** list_pt);
void UbahDataPasien(Pasien** list_pt);
void UbahPasien(Pasien** list_pt);
void HapusDataPasien(Pasien** list_pt, Pasien* target);
void HapusPasien(Pasien** list_pt);
void ManajemenDataPasien(Pasien** list_pt);

void KonversiKontrol(Date* tanggal_kedatangan);
void OpsiTindakan(BiayaPengobatan* list_tdk, int* nomortindakan, int* biaya);
void TambahDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk);
void DateSearch(Diagnosis* list_diag, int* count, Date* input);
void DiagIDSearch(Diagnosis* list_diag, int* count, char input[MAX_STRING]);
void CariDiag(Diagnosis* list_diag);
void UbahDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk);
void UbahDiag(Diagnosis** list_diag, Tindakan* list_tdk);
void HapusDataDiag(Diagnosis** list_diag, Diagnosis* target);
void HapusDiag(Diagnosis** list_diag);
void ManajemenDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk);

#endif