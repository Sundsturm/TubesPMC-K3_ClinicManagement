#include "workwithdata.h"
#include "../include/workwithdata.h"
#include "../include/standardclib.h"
#ifndef _TOTALDIAGNOSE_H_
#define _TOTALDIAGNOSE_H_

typedef struct data{
    char diagnose[MAX_STRING];
    int total;
} Data;

typedef struct Tahun{
    int year;
    Data* diagnoses;
} Tahun;

typedef struct Bulan {
    char bulan[MAX_STRING];
    Data* diagnoses;
} Bulan;

char* toMonth(int m);

void perMonth(Diagnosis *list_dx, int year, char *month, Data** bulan, int* total_diagnose);
void perYear(Diagnosis *list_dx, int year, Bulan** bulan, int* total_diagnose);
void allYear(Diagnosis *list_dx, Tahun** years, int* total_year, int* total_diagnose);

#endif
