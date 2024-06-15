#include "../include/workwithdata.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct Node {
    int v;
    char* diagnose;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char* diagnose, int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> left = temp -> right = NULL;
    temp -> v = v;
    strcpy(temp -> diagnose, diagnose);
    printf("%s with total %d\n", diagnose, v);
    return temp;
}

void eulerTour(struct Node* current, char* diagnose, int v) {
    if(v <= (current -> v)) {
        if(current -> left != NULL) {
            eulerTour(current -> left, diagnose, v);
        } else {
            current -> left = newNode(diagnose, v);
        }
    } else {
        if(current -> right != NULL) {
            eulerTour(current -> right, diagnose, v); 
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

    printf("%s with total %d ", current ->diagnose, current -> v);

    if(current -> right != NULL) {
        dfs_tree(current -> right);
    }
}

int findMax(Diagnosis* list_dx) {
    int idx = 0;
    while(list_dx != NULL) {
        idx++;
        list_dx = list_dx -> next;
    }
    return idx;
}

int toInt(char* month) {
    if(strcmp(month, "Januari")) return 0;
    if(strcmp(month, "Februari")) return 1;
    if(strcmp(month, "Maret")) return 2;
    if(strcmp(month, "April")) return 3;
    if(strcmp(month, "Mei")) return 4;
    if(strcmp(month, "Juni")) return 5;
    if(strcmp(month, "Juli")) return 6;
    if(strcmp(month, "Agustus")) return 7;
    if(strcmp(month, "September")) return 8;
    if(strcmp(month, "Oktober")) return 9;
    if(strcmp(month, "November")) return 10;
    if(strcmp(month, "Desember")) return 11;
}



void diagnosePerMonth(Pasien *list_pt, Diagnosis *list_dx) {
    struct Node* root = NULL;
    const int mx = findMax(list_dx);
    char diagnose[mx][MAX_STRING];
    int idx = 0;
    Diagnosis* temp = list_dx;
    int max_year = 0, min_year = INT_MAX;
    while(temp != NULL) {
        int found = 0;
        for(int i = 0; i < idx; ++i) {
            if(strcmp(diagnose[i], temp ->diagnosis) == 0) found = 1;
        }

        Date cur = temp->tanggal_cek;
        max_year = cur.tahun > max_year ? cur.tahun : max_year;
        min_year = cur.tahun < min_year ? cur.tahun : min_year;

        if(!found) {
            strcpy(diagnose[idx++], temp ->diagnosis);
        }
        temp = temp -> next;
    }

    for(int d = 0; d < idx; ++d) {
        printf("%s\n", diagnose[d]);
    }
    
    for(int year = min_year; year <= max_year; ++year) {
        Diagnosis* i = list_dx;
        int counting[12][idx];
        for(int j = 0; j < 12; ++j) {
            for(int k = 0; k < idx; ++k) counting[j][k] = 0;
        }

        while(i != NULL) {
            Date cur = i -> tanggal_cek;
            if(cur.tahun == year) {
                for(int d = 0; d < idx; ++d) {
                    if(strcmp(i -> diagnosis, diagnose[d]) == 0) {
                        puts("YES");
                        counting[toInt(cur.bulan)][d]++;
                    }
                }
            }
            i = i -> next;
        }

        printf("Tahun %d\n", year);

        for(int month = 0; month < 12; month++) {
            for(int d = 0; d < idx; ++d) {
                //printf("%d ", counting[month][d]);
            }
        }
        break;
    }
}

void perYear(Pasien *list_pt, Diagnosis *list_dx){
    
}


int main() {
    Pasien *list_pasien = NULL;
	Diagnosis *list_diagnosis = NULL;
	readCSVPasien("../../resources/DataPMC20232024(1).csv", &list_pasien);
	readCSVDiagnosis("../../resources/DataPMC20232024(2).csv", &list_diagnosis);
    diagnosePerMonth(list_pasien, list_diagnosis);
}