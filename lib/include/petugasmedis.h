#ifndef __PETUGASMEDIS_H__
#define __PETUGASMEDIS_H_
#include "workwithdata.h"
Pasien* cariPasienByID(Pasien* head, const char* id_pasien);
void informasiPasienRiwayatMedis(Pasien* headPasien, Diagnosis* headDiagnosis);
void printPasienForKontrol(Diagnosis* head, Date kontrolDate);
void PasienForKontrol(Pasien* pasienHead, Diagnosis* diagnosisHead);
#endif
