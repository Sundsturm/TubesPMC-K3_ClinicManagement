#include "workwithdata.h"
#ifndef _TOTALDIAGNOSE_H_
#define _TOTALDIAGNOSE_H_
#define MAX_STRING 256
#define MAX_MONTH 12


typedef struct data{
    char diagnose[MAX_STRING];
    int total;
}Data;

struct Tahun{
    int year;
    Data* diagnoses;
};

struct Bulan {
    char bulan[MAX_STRING];
    Data* diagnoses;
};

char* toMonth(int m);

void perMonth(Diagnosis *list_dx, int year, char month[], Data** bulan, int* total_diagnose);
void perYear(Diagnosis *list_dx, int year, struct Bulan** bulan, int* total_diagnose);
void allYear(Diagnosis *list_dx, struct Tahun** years, int* total_year, int* total_diagnose);

#endif
