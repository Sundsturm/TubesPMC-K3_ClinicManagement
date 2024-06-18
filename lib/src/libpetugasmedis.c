#include "../include/standardclib.h"
#include "../include/workwithdata.h"
#include "../include/petugasmedis.h"

Pasien* cariPasienByID(Pasien* head, const char* id_pasien) {
    Pasien* temp = head;
    while (temp) {
        if (strcmp(temp->id_pasien, id_pasien) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Jika tidak ditemukan
}

char* informasiPasienRiwayatMedis(Pasien* headPasien, const char *id_pasien) {
    char *message = (char*)malloc(MAX_STRING*sizeof(char));
    Pasien* pasien = cariPasienByID(headPasien, id_pasien);
    if (pasien == NULL) {
        snprintf(message, MAX_STRING, "Pasien dengan ID %s tidak ditemukan.\n", id_pasien);
    } else {
        snprintf(message, MAX_STRING, "Informasi Pasien:\nNomor: %d\nNama Lengkap: %s\nAlamat: %s\nKota: %s\nTempat Lahir: %s\nTanggal Lahir: %d %s %d\nUmur: %d\nBPJS: %s\nID Pasien: %s\n\n",
                                    pasien->nomor,
                                    pasien->nama_lengkap,
                                    pasien->alamat,
                                    pasien->kota,
                                    pasien->tempat_lahir,
                                    pasien->tanggal_lahir.hari,
                                    pasien->tanggal_lahir.bulan,
                                    pasien->tanggal_lahir.tahun,
                                    pasien->umur,
                                    pasien->bpjs,
                                    pasien->id_pasien);
    }
    return message;
}

Diagnosis* PasienForKontrol(Diagnosis* head, char *tanggal_k, int *count) {
    Diagnosis* temp = head;
    Date temptanggal;
    assignTanggal(tanggal_k, &temptanggal);
    int counter = 0;
	Diagnosis *head_t = NULL;
	Diagnosis *tail_t = NULL;
    while (temp != NULL) {
        if (temp->tanggal_kontrol.hari == temptanggal.hari &&
            strcmp(temp->tanggal_kontrol.bulan, temptanggal.bulan) == 0 &&
            temp->tanggal_kontrol.tahun == temptanggal.tahun) {
                Diagnosis *filtered_date = (Diagnosis*)malloc(sizeof(Diagnosis));
                filtered_date->tanggal_cek = temp->tanggal_cek;
                filtered_date->tanggal_kontrol = temp->tanggal_kontrol;
                strcpy(filtered_date->id_pasien, temp->id_pasien);
                strcpy(filtered_date->diagnosis, temp->diagnosis);
                strcpy(filtered_date->tindakan, temp->tindakan);
                filtered_date->nomor = temp->nomor;
                filtered_date->biaya = temp->biaya;
                filtered_date->next = NULL;
                filtered_date->prev = tail_t;
                if(tail_t){
                    tail_t->next = filtered_date;
                } else {
                    head_t = filtered_date;
                }
                tail_t = filtered_date;
                counter++;
        }
        temp = temp->next;
    }
    if (counter == 0) {
        printf("Tidak ada pasien yang perlu kontrol pada tanggal tersebut.\n");
    }
    *count = counter;
    return head_t;
}