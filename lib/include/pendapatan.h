#ifndef __PENDAPATAN_H__
#define __PENDAPATAN_H__
#include "workwithdata.h"
int totalPendapatanBulanan(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, char* bulan, int tahun);
int totalPendapatanTahunan(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, int tahun);
float rataRataPendapatanPerTahun(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, int tahun);
char* rataRataPendapatan(Diagnosis* headDiagnosis,BiayaPengobatan* headBiayaPengobatan, char *bulan, int tahun);
#endif