#include "../include/standardclib.h"
#include "../include/workwithdata.h"

void TambahPasien(Pasien** list_pt, char *input_nama_lengkap, char *input_alamat, char* input_kota, char *input_tempat_lahir, char*input_tanggal_lahir, int input_umur, char* input_bpjs, int *count_px){
	
	Pasien *PasienBaru = malloc(sizeof(Pasien)) , *templist = *list_pt;
	int idnum;
	char id[MAX_STRING];
	Date temptanggal;

	strcpy(PasienBaru->nama_lengkap, input_nama_lengkap);
	strcpy(PasienBaru->alamat, input_alamat);
	strcpy(PasienBaru->kota, input_kota);
	strcpy(PasienBaru->tempat_lahir, input_tempat_lahir);
	assignTanggal(input_tanggal_lahir, &temptanggal);
	PasienBaru->tanggal_lahir = temptanggal;
	PasienBaru->umur = input_umur;
	strcpy(PasienBaru->bpjs, input_bpjs);
	strcpy(PasienBaru->id_pasien, "KX ");

	while(templist->next != NULL){
		templist = templist->next;
	}

	PasienBaru->nomor = templist->nomor + 1;
	sscanf(templist->id_pasien, "KX %d", &idnum);
	idnum++;
	sprintf(id, "%d\n", idnum);
	strcat(PasienBaru->id_pasien, id);

	templist->next = PasienBaru;
	PasienBaru->prev = templist;
	PasienBaru->next = NULL;
	++(*count_px);
	return;
}

Pasien* NameSearch(Pasien* list_pt, char* nama_lengkap, int *found){
	Pasien *templist = list_pt;
	Pasien *filtered = (Pasien*)malloc(sizeof(Pasien));
	while(templist != NULL && strcmp(templist->nama_lengkap, nama_lengkap) != 0 ){
		templist = templist->next;
	}
	filtered->nomor = templist->nomor;
	filtered->umur = templist->umur;
	strcpy(filtered->nama_lengkap, templist->nama_lengkap);
	strcpy(filtered->alamat, templist->alamat);
	strcpy(filtered->kota, templist->kota);
	strcpy(filtered->tempat_lahir, templist->tempat_lahir);
	strcpy(filtered->bpjs, templist->bpjs);
	strcpy(filtered->id_pasien, templist->id_pasien);
	filtered->tanggal_lahir = templist->tanggal_lahir;

	++(*found);
	return filtered;
}

Pasien* IDSearch(Pasien* list_pt, char* id_pasien, int*found){
	Pasien *templist = list_pt;
	Pasien *filtered = (Pasien*)malloc(sizeof(Pasien));
	while(templist != NULL && strcmp(templist->id_pasien, id_pasien) != 0 ){
		templist = templist->next;
	}
	filtered->nomor = templist->nomor;
	filtered->umur = templist->umur;
	strcpy(filtered->nama_lengkap, templist->nama_lengkap);
	strcpy(filtered->alamat, templist->alamat);
	strcpy(filtered->kota, templist->kota);
	strcpy(filtered->tempat_lahir, templist->tempat_lahir);
	strcpy(filtered->bpjs, templist->bpjs);
	strcpy(filtered->id_pasien, templist->id_pasien);
	filtered->tanggal_lahir = templist->tanggal_lahir;
	++(*found);
	return filtered;
}

void UbahDataPasien(Pasien** list_pt, char *input, char *opsi, int pos){
	Date temptanggal;
	Pasien *templist = *list_pt;
	while(templist != NULL){
		if(templist->nomor == pos){
			break;
		}
		templist = templist->next;
	}
	if(strcmp(opsi, "Nama Lengkap") == 0){
		strcpy(templist->nama_lengkap, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Alamat") == 0){
		strcpy(templist->alamat, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Kota") == 0){
		strcpy(templist->kota, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Tempat Lahir") == 0){
		strcpy(templist->tempat_lahir, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Tanggal Lahir") == 0){
		assignTanggal(input, &temptanggal);
		templist->tanggal_lahir = temptanggal;
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Umur") == 0){
		templist->umur = atoi(input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "No. BPJS") == 0){
		strcpy(templist->bpjs, input);  
		printf("Data berhasil diubah!");
	}
	else{
		printf("Opsi tidak ditemukan!\n");
	}
	return;
}

void HapusDataPasien(Pasien** list_pt, int num){
	Pasien *temp = *list_pt;
	if (temp== NULL) {
        return;
    }

	while((temp) != NULL){
		if(temp->nomor == num){
			break;
		}
		temp = temp->next;
	}
    
	if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        // Deleting the head node
        *list_pt = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    
    // Renumber the list
    Pasien* templist = *list_pt;
    int counter = 1;
    while (templist != NULL) {
        templist->nomor = counter;
        templist = templist->next;
        counter++;
    }

	return;
}

void OpsiTindakan(BiayaPengobatan* list_tdk, int* biaya, char* pilihan){
	int opsi, biayadaftar, biayaperiksa, biayatotal;
	BiayaPengobatan *temptdk = list_tdk;

	while(temptdk != NULL){
			if(strcmp(temptdk->aktivitas, "Pendaftaran") == 0){
				biayadaftar = temptdk->biaya;
			}
			if(strcmp(temptdk->aktivitas, "Pemeriksaan") == 0){
				biayaperiksa = temptdk->biaya;
			}
		temptdk = temptdk->next;	
	}
	temptdk = list_tdk;

	while(temptdk != NULL){
		if(strcmp(temptdk->aktivitas, pilihan) == 0){
		biayatotal = biayadaftar + biayaperiksa + temptdk->biaya;
		break;
		}
		temptdk = temptdk->next;
	}
	*biaya = biayatotal;
	
	return;
}

void TambahDiag(Diagnosis** list_diag, BiayaPengobatan *list_tdk, char *tanggal_kunjungan, char *id_pasien, char *diagnosis, char *tindakan, int*count_diag){
    Diagnosis *RiwayatBaru = malloc(sizeof(Diagnosis)) , *templist = *list_diag;
	Date temptanggal, temptanggalkontrol;
	int biayaTotal;
	OpsiTindakan(list_tdk, &biayaTotal, tindakan);
	assignTanggal(tanggal_kunjungan, &temptanggal);
	RiwayatBaru->tanggal_cek = temptanggal;
	temptanggalkontrol = temptanggal;
	temptanggalkontrol.hari += 3;
	RiwayatBaru->tanggal_kontrol = temptanggalkontrol;
	strcpy(RiwayatBaru->diagnosis, diagnosis);
	strcpy(RiwayatBaru->tindakan, tindakan);
	strcpy(RiwayatBaru->id_pasien, id_pasien);
	RiwayatBaru->biaya = biayaTotal;

	templist = *list_diag;
	while(templist->next != NULL){
		templist = templist->next;
	}
	RiwayatBaru->nomor = templist->nomor+1;
	templist->next = RiwayatBaru;
	RiwayatBaru->prev = templist;
	RiwayatBaru->next = NULL;
	++(*count_diag);
	return;
}

Diagnosis* DateSearch(Diagnosis* list_diag, char *tanggal_kunjungan, int*found){
	Diagnosis *templist = list_diag;
	Date tanggal_s;
	assignTanggal(tanggal_kunjungan, &tanggal_s);
	int counter = 0;
	Diagnosis *head_t = NULL;
	Diagnosis *tail_t = NULL;

	while(templist != NULL){
		if(tanggal_s.hari == templist->tanggal_cek.hari && tanggal_s.tahun == templist->tanggal_cek.tahun && strcmp(tanggal_s.bulan, templist->tanggal_cek.bulan) == 0){
			Diagnosis *filtered_date = (Diagnosis*)malloc(sizeof(Diagnosis));
			filtered_date->tanggal_cek = tanggal_s;
			filtered_date->tanggal_kontrol = templist->tanggal_kontrol;
			strcpy(filtered_date->id_pasien, templist->id_pasien);
			strcpy(filtered_date->diagnosis, templist->diagnosis);
			strcpy(filtered_date->tindakan, templist->tindakan);
			filtered_date->nomor = templist->nomor;
			filtered_date->biaya = templist->biaya;
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
		templist = templist->next;
	}
	*found = counter;
	return head_t;
}

Diagnosis* DiagIDSearch(Diagnosis* list_diag, char *id_pasien, int*found){
	Diagnosis *templist = list_diag;
	int counter = 0;
	Diagnosis *head_t = NULL;
	Diagnosis *tail_t = NULL;
	while(templist != NULL){
		if(strcmp(id_pasien, templist->id_pasien) == 0){
			Diagnosis *filtered_date = (Diagnosis*)malloc(sizeof(Diagnosis));
			filtered_date->tanggal_cek = templist->tanggal_cek;
			filtered_date->tanggal_kontrol = templist->tanggal_kontrol;
			strcpy(filtered_date->id_pasien, templist->id_pasien);
			strcpy(filtered_date->diagnosis, templist->diagnosis);
			strcpy(filtered_date->tindakan, templist->tindakan);
			filtered_date->nomor = templist->nomor;
			filtered_date->biaya = templist->biaya;
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
		templist = templist->next;
	}

	*found = counter;
	return head_t;
}

void UbahDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk, char *input, char *opsi, int pos){
	Date temptanggal;
	BiayaPengobatan *temptdk = list_tdk;
	int biaya;

	Diagnosis *templist = *list_diag;
	while(templist != NULL){
		if(templist->nomor == pos){
			break;
		}
		templist = templist->next;
	}
	if(strcmp(opsi, "Tanggal Kunjungan") == 0){
		assignTanggal(input, &temptanggal);
		templist->tanggal_cek = temptanggal;
		temptanggal.hari += 3;
		templist->tanggal_kontrol = temptanggal;
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "ID Pasien") == 0){
		strcpy(templist->id_pasien, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Diagnosis") == 0){
		strcpy(templist->diagnosis, input); 
		printf("Data berhasil diubah!");
	}
	else if(strcmp(opsi, "Tindakan") == 0){
		strcpy(templist->tindakan, input);
		OpsiTindakan(list_tdk, &biaya, input);
		templist->biaya = biaya;
		printf("Data berhasil diubah!");
	}
	else{
		printf("Opsi tidak ditemukan!\n");
	}
	return;
}

void HapusDataDiag(Diagnosis** list_dt, int num){
	Diagnosis *temp = *list_dt;
	if (temp== NULL) {
        return;
    }

	while((temp) != NULL){
		if(temp->nomor == num){
			break;
		}
		temp = temp->next;
	}
    
	if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        // Deleting the head node
        *list_dt = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    
    // Renumber the list
    Diagnosis* templist = *list_dt;
    int counter = 1;
    while (templist != NULL) {
        templist->nomor = counter;
        templist = templist->next;
        counter++;
    }

	return;
}