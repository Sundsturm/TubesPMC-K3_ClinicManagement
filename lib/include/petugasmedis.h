#ifndef __PETUGASMEDIS_H__
#define __PETUGASMEDIS_H_
#include "workwithdata.h"
Pasien* cariPasienByID(Pasien* head, const char* id_pasien);
char* informasiPasienRiwayatMedis(Pasien* headPasien, const char *id_pasien);
Diagnosis* PasienForKontrol(Diagnosis* head, char *tanggal_k, int *counter);
#endif
