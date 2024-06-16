#include "../include/workwithdata.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node {
    int v;
    char diagnose[MAX_STRING];
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char diagnose[], int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> left = temp -> right = NULL;
    temp -> v = v;
    strcpy(temp -> diagnose, diagnose);
    return temp;
}

void insert(struct Node* current, char diagnose[], int v) {
    if(v <= (current -> v)) {
        if(current -> left != NULL) {
            insert(current -> left, diagnose, v);
        } else {
            current -> left = newNode(diagnose, v);
        }
    } else {
        if(current -> right != NULL) {
            insert(current -> right, diagnose, v); 
        } else {
            current -> right = newNode(diagnose, v);
        }
    }
    return;
}

void dfs_tree(struct Node* current) {
    if(current -> left != NULL) {
        dfs_tree(current -> left);
    }

    printf("%s with total %d\n", current ->diagnose, current -> v);

    if(current -> right != NULL) {
        dfs_tree(current -> right);
    }
}

void freeTree(struct Node* cur) {
    if(cur == NULL) return;
    freeTree(cur -> left);
    freeTree(cur -> right);
    free(cur);
}

int findMax(Diagnosis* list_dx) {
    int idx = 0;
    while(list_dx != NULL) {
        idx++;
        list_dx = list_dx -> next;
    }
    return idx;
}


char months[][MAX_STRING] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

int toInt(char month[]) {
    for(int i = 0; i < 12; ++i) {
        if(strcmp(month, months[i]) == 0) return i;
    }
}

char* toMonth(int m) {
    return months[m];
}

void findUnique(Diagnosis* list_dx, char diagnose[][MAX_STRING], int* ret_idx) {
    Diagnosis* cur = list_dx;
    int idx = 0;
    while(cur != NULL) {
        int found = 0;
        for(int i = 0; i < idx; ++i) {
            if(strcmp(cur ->diagnosis, diagnose[i]) == 0) found = 1;
        }

        if(!found) {
            strcpy(diagnose[idx++], cur -> diagnosis);
        }
        cur = cur -> next;
    }

    *ret_idx = idx;
}

void findYear(Diagnosis* list_dx, int* min_year, int* max_year) {
    Diagnosis* temp = list_dx;
    int mx = -1, mn = INT_MAX;
    while(temp != NULL) {
        if(temp ->tanggal_cek.tahun > mx) mx = temp ->tanggal_cek.tahun;
        if(temp -> tanggal_cek.tahun < mn) mn = temp -> tanggal_cek.tahun;
        temp = temp -> next;
    }
    *min_year = mn;
    *max_year = mx;
}

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

void allYear(Diagnosis *list_dx, struct Tahun** years, int* total_year, int* total_diagnose) {
    int idx, min_year, max_year; 
    const int mx = findMax(list_dx); // find maximal diagnose
    char diagnose [mx][MAX_STRING]; 

    findUnique(list_dx, diagnose, &idx);
    findYear(list_dx, &min_year, &max_year);

    const int Y = max_year - min_year + 1;
    struct Tahun* current_year = (struct Tahun*)malloc(Y * sizeof(struct Tahun));
    *years = current_year;
    *total_year = Y;
    *total_diagnose = idx;
    for(int i = 0; i < Y; ++i) {
        (*years)[i].year = i + min_year;
        Data* total_diagnose = (Data*)malloc(idx * sizeof(Data));
        for(int j = 0; j < idx; ++j) {
            strcpy(total_diagnose[j].diagnose, diagnose[j]);
            total_diagnose[j].total = 0;
        }
        (*years)[i].diagnoses = total_diagnose;
    }
    
    Diagnosis* current_data = list_dx;
    while(current_data != NULL) {
        for(int i = 0; i < Y; ++i) {
            if(i + min_year == current_data->tanggal_cek.tahun) {
                for(int j = 0; j < idx; ++j) {
                    if(strcmp(current_data -> diagnosis, (*years)[i].diagnoses[j].diagnose) == 0) {
                        (*years)[i].diagnoses[j].total += 1;
                    }
                }
            }
        }
        current_data = current_data -> next;
    }

    for(int i = 0; i < Y; ++i) {
        for(int j = 0; j < idx; ++j) {
            for(int k = 0; k + 1 < idx; ++k) {
                if((*years)[i].diagnoses[k].total > (*years)[i].diagnoses[k + 1].total) {
                    int temp = (*years)[i].diagnoses[k].total;
                    (*years)[i].diagnoses[k].total = (*years)[i].diagnoses[k + 1].total;
                    (*years)[i].diagnoses[k + 1].total = temp;
                }
            }
        }
    }
}

void perYear(Diagnosis *list_dx, int year, struct Bulan** bulan, int* total_diagnose) {
    int idx, min_year, max_year; 
    const int mx = findMax(list_dx); // find maximal diagnose
    char diagnose [mx][MAX_STRING]; 

    findUnique(list_dx, diagnose, &idx);
    *bulan = (struct Bulan*)malloc(12 * sizeof(struct Bulan));
    *total_diagnose = idx;
    Diagnosis* current_diagnose = list_dx;
    for(int b = 0; b < 12; ++b) {
        strcpy((*bulan)[b].bulan, toMonth(b));
        Data* total_diagnose = (Data*)malloc(idx * sizeof(Data));
        for(int j = 0; j < idx; ++j) {
            strcpy(total_diagnose[j].diagnose, diagnose[j]);
            total_diagnose[j].total = 0;
        }
        (*bulan)[b].diagnoses = total_diagnose;
    }

    while(current_diagnose != NULL) {
        Date cur_date = current_diagnose -> tanggal_cek;
        if(cur_date.tahun == year) {
            int ke = toInt(cur_date.bulan);
            for(int d = 0; d < idx; ++d) {
                if(strcmp(current_diagnose -> diagnosis, diagnose[d]) == 0) {
                    (*bulan)[ke].diagnoses[d].total += 1;
                }
            }
        }
        current_diagnose = current_diagnose -> next;
    }

    for(int b = 0; b < 12; ++b) {
        for(int j = 0; j < idx; ++j) {
            for(int k = 0; k + 1 < idx; ++k) {
                if((*bulan)[b].diagnoses[k].total > (*bulan)[b].diagnoses[k + 1].total) {
                    int temp = (*bulan)[b].diagnoses[k].total;
                    (*bulan)[b].diagnoses[k].total = (*bulan)[b].diagnoses[k + 1].total;
                    (*bulan)[b].diagnoses[k + 1].total = temp;
                }
            }
        }
    }
}

void perMonth(Diagnosis *list_dx, int year, char month[]) {
    
}

int main() {
    Pasien *list_pasien = NULL;
	Diagnosis *list_diagnosis = NULL;
	readCSVPasien("../../resources/DataPMC20232024(1).csv", &list_pasien);
	readCSVDiagnosis("../../resources/DataPMC20232024(2).csv", &list_diagnosis);

    /* contoh Diagnose all Year
    struct Tahun* data_year = NULL;
    int total_year, total_diagnose;
    allYear(list_diagnosis, &data_year, &total_year, &total_diagnose);
    for(int i = 0; i < total_year; ++i) {
        printf("Data %d : \n", data_year[i].year);
        for(int j = 0; j < total_diagnose; ++j) {
            printf("%s with total %d\n", data_year[i].diagnoses[j].diagnose, data_year[i].diagnoses[j].total);
        }
    }
    */

    /* Contoh Diagnose per month
    struct Bulan* data_month = NULL;
    int total_diagnose;
    perYear(list_diagnosis, 2022, &data_month, &total_diagnose); // (list penyakit, tahun, struct data bulan, total diagnosis);
    for(int b = 0; b < 12; ++b) {
        printf("Data bulan %s : \n", data_month[b].bulan);
        for(int d = 0; d < total_diagnose; ++d) {
            printf("%s with total %d\n", data_month[b].diagnoses[d].diagnose, data_month[b].diagnoses[d].total);
        }
        puts("");
    }
    */


}