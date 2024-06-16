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

void informasiPasienRiwayatMedis(Pasien* headPasien, Diagnosis* headDiagnosis) {
    char id_pasien[MAX_STRING];
    printf("Masukkan ID Pasien: ");
    gets(id_pasien);
    Pasien* pasien = cariPasienByID(headPasien, id_pasien);
    if (pasien == NULL) {
        printf("Pasien dengan ID %s tidak ditemukan.\n", id_pasien);
        return;
    }

    printf("Informasi Pasien:\n");
    printf("Nomor: %d\n", pasien->nomor);
    printf("Nama Lengkap: %s\n", pasien->nama_lengkap);
    printf("Alamat: %s\n", pasien->alamat);
    printf("Kota: %s\n", pasien->kota);
    printf("Tempat Lahir: %s\n", pasien->tempat_lahir);
    printf("Tanggal Lahir: %d %s %d\n", pasien->tanggal_lahir.hari, pasien->tanggal_lahir.bulan, pasien->tanggal_lahir.tahun);
    printf("Umur: %d\n", pasien->umur);
    printf("BPJS: %s\n", pasien->bpjs);
    printf("ID Pasien: %s\n\n", pasien->id_pasien);

    printf("Riwayat Medis:\n");
    Diagnosis* tempDiagnosis = headDiagnosis;
    while (tempDiagnosis) {
        if (strcmp(tempDiagnosis->id_pasien, id_pasien) == 0) {
            printf("Nomor: %d\n", tempDiagnosis->nomor);
            printf("Tanggal Cek: %d %s %d\n", tempDiagnosis->tanggal_cek.hari, tempDiagnosis->tanggal_cek.bulan, tempDiagnosis->tanggal_cek.tahun);
            printf("Diagnosis: %s\n", tempDiagnosis->diagnosis);
            printf("Tindakan: %s\n", tempDiagnosis->tindakan);
            printf("Tanggal Kontrol: %d %s %d\n", tempDiagnosis->tanggal_kontrol.hari, tempDiagnosis->tanggal_kontrol.bulan, tempDiagnosis->tanggal_kontrol.tahun);
            printf("Biaya: %d\n\n", tempDiagnosis->biaya);
        }
        tempDiagnosis = tempDiagnosis->next;
    }
}

void printPasienForKontrol(Diagnosis* head, Date kontrolDate) {
    Diagnosis* temp = head;
    int found = 0;
    while (temp) {
        if (temp->tanggal_kontrol.hari == kontrolDate.hari &&
            strcmp(temp->tanggal_kontrol.bulan, kontrolDate.bulan) == 0 &&
            temp->tanggal_kontrol.tahun == kontrolDate.tahun) {
            printf("Nomor: %d\n", temp->nomor);
            printf("Tanggal Cek: %d %s %d\n", temp->tanggal_cek.hari, temp->tanggal_cek.bulan, temp->tanggal_cek.tahun);
            printf("ID Pasien: %s\n", temp->id_pasien);
            printf("Diagnosis: %s\n", temp->diagnosis);
            printf("Tindakan: %s\n", temp->tindakan);
            printf("Biaya: %d\n\n", temp->biaya);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Tidak ada pasien yang perlu kontrol pada tanggal tersebut.\n");
    }
}

void PasienForKontrol(Pasien* pasienHead, Diagnosis* diagnosisHead){
// Example usage of the new function
    char dateStr[MAX_STRING];
    printf("Masukkan tanggal kontrol yang diinginkan (format: DD MMM YYYY): ");
    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strcspn(dateStr, "\n")] = '\0'; // Remove trailing newline

    Date kontrolDate;
    assignTanggal(dateStr, &kontrolDate);
    printf("Pasien yang perlu kontrol pada tanggal %d %s %d:\n", kontrolDate.hari, kontrolDate.bulan, kontrolDate.tahun);
    printPasienForKontrol(diagnosisHead, kontrolDate);
}