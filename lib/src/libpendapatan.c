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

void rataRataPendapatan(Diagnosis* headDiagnosis,BiayaPengobatan* headBiayaPengobatan ){
 // Contoh penggunaan fungsi totalPendapatanBulanan
    char bulan[15];
    int tahun;

    // Input bulan dan tahun untuk rata-rata pendapatan
    printf("Masukkan bulan : ");
    scanf("%s", bulan);
    printf("Masukkan tahun: ");
    scanf("%d", &tahun);

    // Cetak informasi total pendapatan bulanan
    printf("\nInformasi Pendapatan Bulan %s %d:\n", bulan, tahun);
    int totalBulanan = totalPendapatanBulanan(headDiagnosis, headBiayaPengobatan, bulan, tahun);
    printf("Total Pendapatan Bulan: Rp %d\n", totalBulanan);

    // Cetak informasi total pendapatan tahunan
    printf("\nInformasi Pendapatan Tahun %d:\n", tahun);
    int totalTahunan = totalPendapatanTahunan(headDiagnosis, headBiayaPengobatan, tahun);
    printf("Total Pendapatan Tahun: Rp %d\n", totalTahunan);

    // Cetak informasi rata-rata pendapatan per tahun
    printf("\nInformasi Rata-rata Pendapatan per Transaksi Tahun %d:\n", tahun);
    float rataRata = rataRataPendapatanPerTahun(headDiagnosis, headBiayaPengobatan, tahun);
    printf("Rata-rata Pendapatan per Transaksi: Rp %.2f\n", rataRata);
}