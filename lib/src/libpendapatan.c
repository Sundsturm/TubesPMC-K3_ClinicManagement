#include "../include/standardclib.h"
#include "../include/workwithdata.h"
#include "../include/pendapatan.h"

int totalPendapatanBulanan(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, char* bulan, int tahun) {
    int total = 0;
    Diagnosis* temp = headDiagnosis;
    while (temp) {
        if (strcmp(temp->tanggal_cek.bulan, bulan) == 0 && temp->tanggal_cek.tahun == tahun) {
            BiayaPengobatan* biayaTemp = headBiayaPengobatan;
            while (biayaTemp) {
                if (strcmp(biayaTemp->aktivitas, temp->tindakan) == 0) {
                    total += biayaTemp->biaya;
                    break;
                }
                biayaTemp = biayaTemp->next;
            }
        }
        temp = temp->next;
    }
    return total;
}

int totalPendapatanTahunan(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, int tahun) {
    int total = 0;
    Diagnosis* temp = headDiagnosis;
    while (temp) {
        if (temp->tanggal_cek.tahun == tahun) {
            BiayaPengobatan* biayaTemp = headBiayaPengobatan;
            while (biayaTemp) {
                if (strcmp(biayaTemp->aktivitas, temp->tindakan) == 0) {
                    total += biayaTemp->biaya;
                    break;
                }
                biayaTemp = biayaTemp->next;
            }
        }
        temp = temp->next;
    }
    return total;
}

float rataRataPendapatanPerTahun(Diagnosis* headDiagnosis, BiayaPengobatan* headBiayaPengobatan, int tahun) {
    int totalPendapatan = 0;
    int jumlahTransaksi = 0;
    Diagnosis* temp = headDiagnosis;

    while (temp) {
        if (temp->tanggal_cek.tahun == tahun) {
            BiayaPengobatan* biayaTemp = headBiayaPengobatan;
            while (biayaTemp) {
                if (strcmp(biayaTemp->aktivitas, temp->tindakan) == 0) {
                    totalPendapatan += biayaTemp->biaya;
                    jumlahTransaksi++;
                    break;
                }
                biayaTemp = biayaTemp->next;
            }
        }
        temp = temp->next;
    }

    if (jumlahTransaksi > 0) {
        return (float)totalPendapatan / jumlahTransaksi;
    } else {
        return 0.0;
    }
}

char* rataRataPendapatan(Diagnosis* headDiagnosis,BiayaPengobatan* headBiayaPengobatan, char *bulan, int tahun){
    char *message = (char*)malloc(MAX_STRING*sizeof(char));
    int totalBulanan = totalPendapatanBulanan(headDiagnosis, headBiayaPengobatan, bulan, tahun);
    int totalTahunan = totalPendapatanTahunan(headDiagnosis, headBiayaPengobatan, tahun);
    float rataRata = rataRataPendapatanPerTahun(headDiagnosis, headBiayaPengobatan, tahun);
    snprintf(message, MAX_STRING, "Informasi Pendapatan Bulan %s %d:\nTotal Pendapatan Bulan: Rp %d\n\nInformasi Pendapatan Tahun %d:\nTotal Pendapatan Tahun: Rp %d\n\nInformasi Rata-rata Pendapatan per Transaksi Tahun %d:\nRata-rata Pendapatan per Transaksi: Rp %.2f\n",
    bulan, tahun, totalBulanan, tahun, totalTahunan, tahun, rataRata);
    return message;
}