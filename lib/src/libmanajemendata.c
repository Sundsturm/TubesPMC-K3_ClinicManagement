#include "../include/standardclib.h"
#include "../include/workwithdata.h"

void TambahPasien(Pasien** list_pt){
	
	Pasien *PasienBaru = malloc(sizeof(Pasien)) , *templist = *list_pt;
	int idnum;
	char id[MAX_STRING];
	Date temptanggal;

	printf("Nama Pasien: ");
	scanf("%*c%[^\n]%*c", PasienBaru->nama_lengkap);
	printf("Alamat: ");
	scanf("%[^\n]%*c", PasienBaru->alamat);
	printf("Kota: ");
	scanf("%[^\n]%*c", PasienBaru->kota);
	printf("Tempat Lahir: ");
	scanf("%[^\n]%*c", PasienBaru->tempat_lahir);
	printf("Tanggal Lahir (dd bulan yyyy): ");
	scanf("%d %s %d", &temptanggal.hari, temptanggal.bulan, &temptanggal.tahun);
	PasienBaru->tanggal_lahir = temptanggal;
	printf("Umur: ");
	scanf("%d", &PasienBaru->umur);
	printf("No. BPJS: ");
	scanf("%s", PasienBaru->bpjs);
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

	printf("\nData pasien berhasil ditambahkan!\n");

	return;
}

void NameSearch(Pasien** list_pt){
	Pasien *templist = *list_pt;
	char tempstr[MAX_STRING];

	printf("Nama Pasien: ");
	scanf("%*c%[^\n]%*c", tempstr);
	printf("\n");

	while(templist != NULL && strcmp(templist->nama_lengkap, tempstr) != 0 ){
		templist = templist->next;
	}

	if(templist == NULL){
		printf("Pasien Tidak Ditemukan!\n");
	}

	else{
		printf("Data Pasien:\n\nNama: %s\nID Pasien: %s\nAlamat: %s\nKota: %s\nTempat Lahir: %s\nTanggal Lahir: %d %s %d\nUmur: %d\nNo. BPJS: %s\n", templist->nama_lengkap, templist->id_pasien, templist->alamat, templist->kota, templist->tempat_lahir, templist->tanggal_lahir.hari, templist->tanggal_lahir.bulan, templist->tanggal_lahir.tahun, templist->umur, templist->bpjs);
	}

	*list_pt = templist;

	return;
}

void IDSearch(Pasien** list_pt){
	Pasien *templist = *list_pt;
	char tempstr[MAX_STRING];

	printf("ID Pasien: ");
	scanf("%*c%[^\n]%*c", tempstr);
	printf("\n");

	strcat(tempstr, "\n");

	while(templist != NULL && strcmp(templist->id_pasien, tempstr) != 0 ){
		templist = templist->next;
	}

	if(templist == NULL){
		printf("Pasien Tidak Ditemukan!\n");
	}

	else{
		printf("Data Pasien:\n\nNama: %s\nID Pasien: %s\nAlamat: %s\nKota: %s\nTempat Lahir: %s\nTanggal Lahir: %d %s %d\nUmur: %d\nNo. BPJS: %s\n", templist->nama_lengkap, templist->id_pasien, templist->alamat, templist->kota, templist->tempat_lahir, templist->tanggal_lahir.hari, templist->tanggal_lahir.bulan, templist->tanggal_lahir.tahun, templist->umur, templist->bpjs);
	}

	*list_pt = templist;

	return;
}

void CariPasien(Pasien** list_pt){
	int opsi, tempjadi;
	printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Scroll\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){
		Pasien *templist = *list_pt;
		if(opsi == 1){
			NameSearch(&templist);
		}
		else if(opsi == 2){
			IDSearch(&templist);
		}
		else if(opsi == 3){
			printPasien(templist);
		}
		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Scroll\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}
	return;
}

void UbahDataPasien(Pasien** list_pt){
	
	Date temptanggal;
	int opsi, tempint;
	char tempstr[MAX_STRING];

	printf("Pilih Data yang ingin diubah:\n1. Nama Lengkap\n2. Alamat\n3. Kota\n4. Tempat Lahir\n5. Tanggal Lahir\n6. Umur\n7. No BPJS\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n\n");

	while(opsi != 0){
		Pasien *templist = *list_pt;
		if(opsi == 1){
			printf("Nama Lengkap: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->nama_lengkap, tempstr); 

			printf("Data berhasil diubah!");
		}
		else if(opsi == 2){
			printf("Alamat: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->alamat, tempstr); 

			printf("Data berhasil diubah!");
		}
		else if(opsi == 3){
			printf("Kota: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->kota, tempstr); 

			printf("Data berhasil diubah!");

		}
		else if(opsi == 4){
			printf("Tempat Lahir: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->tempat_lahir, tempstr); 

			printf("Data berhasil diubah!");

		}
		else if(opsi == 5){
			printf("Tanggal Lahir (dd bulan yyyy): ");
			scanf("%d %s %d", &temptanggal.hari, temptanggal.bulan, &temptanggal.tahun);
			printf("\n\n");

			templist->tanggal_lahir = temptanggal;

			printf("Data berhasil diubah!");
		}
		else if(opsi == 6){
			printf("Tempat Lahir: ");
			scanf("%d", tempint);
			printf("\n\n");

			templist->umur = tempint; 

			printf("Data berhasil diubah!");
		}
		else if(opsi == 7){
			printf("No. BPJS: ");
			scanf("%s", tempstr);
			printf("\n\n");

			strcpy(templist->bpjs, tempstr);  

			printf("Data berhasil diubah!");
		}
		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("Data Pasien:\n\nNama: %s\nID Pasien: %s\nAlamat: %s\nKota: %s\nTempat Lahir: %s\nTanggal Lahir: %d %s %d\nUmur: %d\nNo. BPJS: %s\n\n", templist->nama_lengkap, templist->id_pasien, templist->alamat, templist->kota, templist->tempat_lahir, templist->tanggal_lahir.hari, templist->tanggal_lahir.bulan, templist->tanggal_lahir.tahun, templist->umur, templist->bpjs);

		*list_pt = templist;

		printf("Pilih Data yang ingin diubah:\n1. Nama Lengkap\n2. Alamat\n3. Kota\n4. Tempat Lahir\n5. Tanggal Lahir\n6. Umur\n7. No BPJS\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n\n");
	}

	return;
}

void UbahPasien(Pasien** list_pt){
	Pasien *templist = *list_pt;
	int opsi, opsi2 = 0, counter = 0;
	printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Tampil semuanya\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(templist != NULL){
		templist = templist->next;
		counter++;
	}


	while(opsi != 0){
		opsi2 = 0;
		templist = malloc(sizeof(Pasien));
		templist = *list_pt;

		if(opsi == 1){
			NameSearch(&templist);
			if(templist != NULL){				
				UbahDataPasien(&templist);
			}
		}

		else if(opsi == 2){
			IDSearch(&templist);
			if(templist != NULL){
				UbahDataPasien(&templist);
			}
		}

		else if(opsi == 3){
			printPasien(templist);
			printf("Pilih nomor pasien yang ingin diatur: ");
			scanf("%d", &opsi2);
			printf("\n");

			while(opsi2 < 1 || opsi2 > counter){
				printf("Opsi tidak ditemukan!\n");
				printf("Pilih nomor pasien yang ingin diatur: ");
				scanf("%d", &opsi2);
				printf("\n");
			}
			
			templist = malloc(sizeof(Pasien));
			templist = *list_pt;

			while(templist->nomor != opsi2){
				templist = templist->next;
			}
			UbahDataPasien(&templist);

		}

		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Tampil semuanya\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}

	return;
}

void HapusDataPasien(Pasien** list_pt, Pasien *target){
	Pasien *templist = *list_pt;
	int counter = 1;
	if(target->next == NULL){
		while(templist->next->next != NULL){
			templist = templist->next;
		}
		templist->next = NULL;
	}
	else if(target->prev == NULL){
		templist = templist->next;
		templist->prev = NULL;
		*list_pt = templist;
	}
	else{
		while(templist->next != target){
			templist = templist->next;
		}
		templist->next->next->prev = templist;
		templist->next = templist->next->next;
	}

	templist = malloc(sizeof(Pasien));
	templist = *list_pt;

	while(templist != NULL){
		templist->nomor = counter;
		templist = templist->next;
		counter++;
	}

	printf("Data pasien berhasil dihapus!");

	return;
}

void HapusPasien(Pasien** list_pt){
	Pasien *templist = *list_pt, *base = *list_pt;
	int opsi, opsi2 = 0, counter = 0;
	printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Tampil semuanya\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(templist != NULL){
		templist = templist->next;
		counter++;
	}


	while(opsi != 0){
		opsi2 = 0;
		templist = malloc(sizeof(Pasien));
		base = malloc(sizeof(Pasien));
		templist = *list_pt;
		base = *list_pt;

		if(opsi == 1){
			NameSearch(&templist);
			if(templist != NULL){
				printf("Yakin ingin dihapus?\n1. Hapus\n0.Batal\nOpsi: ");
				scanf("%d", &opsi2);
				printf("\n");	
				if(opsi2 == 1){			
					HapusDataPasien(&base, templist);
					*list_pt = base;
				}
			}
		}

		else if(opsi == 2){
			IDSearch(&templist);
			if(templist != NULL){
				printf("Yakin ingin dihapus?\n1. Hapus\n0.Batal\nOpsi: ");
				scanf("%d", &opsi2);
				printf("\n");	
				if(opsi2 == 1){			
					HapusDataPasien(&base, templist);
					*list_pt = base;
				}
			}
		}

		else if(opsi == 3){
			printPasien(templist);
			printf("Pilih nomor pasien yang ingin dihapus: ");
			scanf("%d", &opsi2);
			printf("\n");

			while(opsi2 < 1 || opsi2 > counter){
				printf("Opsi tidak ditemukan!\n");
				printf("Pilih nomor pasien yang ingin dihapus: ");
				scanf("%d", &opsi2);
				printf("\n");
			}
			
			templist = malloc(sizeof(Pasien));
			templist = *list_pt;

			while(templist->nomor != opsi2){
				templist = templist->next;
			}
			HapusDataPasien(&base, templist);
			*list_pt = base;
		}

		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nMetode Pencarian:\n1. Nama\n2. ID Pasien\n3. Tampil semuanya\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}

	return;
}

void ManajemenDataPasien(Pasien** list_pt) {
	Pasien *templist = *list_pt;
	int opsi;

	printf("\nManajemen Data Pasien:\n1. Tambah data pasien\n2. Cari data pasien\n3. Ubah data pasien\n4. Hapus data pasien\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){

		if(opsi == 1){
			TambahPasien(&templist);
		}
		else if(opsi == 2){
			CariPasien(&templist);
		}
		else if(opsi == 3){
			UbahPasien(&templist);
		}
		else if(opsi == 4){
			HapusPasien(&templist);
		}
		else{
			printf("Opsi tidak ditemukan!");
		}

		printf("\nManajemen Data Pasien:\n1. Tambah data Pasien\n2. Cari data pasien\n3. Ubah data pasien\n4. Hapus data pasien\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}

	*list_pt = templist;
	return;
}


void KonversiKontrol(Date* tanggal_kedatangan){
    int limithari, tahun, i, nobulan;
    char bulan[MAX_STRING];
    char calendar[12][MAX_STRING] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    tahun = tanggal_kedatangan->tahun;
    strcpy(bulan, tanggal_kedatangan->bulan);

	for(i = 0; i < 12; i++){
		if(strcmp(bulan, calendar[i]) == 0){
			nobulan = i;
		}
	}

	//nobulan = nomor bulan - 1
	if(nobulan == 0 || nobulan == 2 || nobulan == 4 || nobulan == 6 || nobulan == 7 || nobulan == 9 || nobulan == 11){
		limithari = 31;
	}

    else if(nobulan == 3 || nobulan == 5 || nobulan == 8 || nobulan == 10){
		limithari == 30;
	}
	else if(nobulan == 1 && (tahun % 4) != 0){
		limithari == 28;
	}
	else{
		limithari == 29;
	}

	int hari = tanggal_kedatangan->hari + 3;

	if (hari > limithari){
		hari = hari - limithari;
		nobulan++;
	}

	if(nobulan > 11){
		nobulan = nobulan - 11;
		tahun++;
	}

	tanggal_kedatangan->hari = hari;
	strcpy(tanggal_kedatangan->bulan, calendar[nobulan]);
	tanggal_kedatangan->tahun = tahun;
}

void OpsiTindakan(BiayaPengobatan* list_tdk, int* nomortindakan, int* biaya){
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

	printf("Pilih salah satu tindakan dibawah:\n");

	while(temptdk != NULL){
		printf("%d. %s ", temptdk->nomor, temptdk->aktivitas, temptdk->biaya);

		if(temptdk->nomor == 1){
		biayatotal = temptdk->biaya;
		}
		else if(temptdk->nomor == 2){
		biayatotal = biayadaftar + temptdk->biaya;
		}
		else{
		biayatotal = biayadaftar + biayaperiksa + temptdk->biaya;
		}

		printf("(%d)\n", biayatotal);

		temptdk = temptdk->next;
	}

	printf("Opsi: ");
	scanf("%d", &opsi);
	printf("\n");
	*nomortindakan = opsi;

	temptdk = list_tdk;

	while(temptdk != NULL && temptdk->nomor != opsi){
		temptdk = temptdk->next;
	}


	while(temptdk == NULL){
		temptdk = list_tdk;
		printf("Opsi tidak ditemukan!\n");
		printf("Pilih salah satu tindakan dibawah:\n");
		while(temptdk != NULL){
			printf("%d. %s ", temptdk->nomor, temptdk->aktivitas, temptdk->biaya);

			if(temptdk->nomor == 1){
			biayatotal = temptdk->biaya;
			}
			else if(temptdk->nomor == 2){
			biayatotal = biayadaftar + temptdk->biaya;
			}
			else{
			biayatotal = biayadaftar + biayaperiksa + temptdk->biaya;
			}

			printf("(%d)\n", biayatotal);

			temptdk = temptdk->next;
		}
		printf("Opsi: ");
		scanf("%d", &opsi);
		printf("\n");
		*nomortindakan = opsi;
		while(temptdk != NULL && temptdk->nomor != opsi){
			temptdk = temptdk->next;
		}
	}

	if(opsi == 1){
		*biaya = temptdk->biaya;
	}			
	else if(opsi == 2){
		*biaya = biayadaftar + temptdk->biaya;
	}
	else{
		*biaya = biayadaftar + biayaperiksa + temptdk->biaya;
	}
	
	return;
}

void TambahDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk){
    Diagnosis *RiwayatBaru = malloc(sizeof(Diagnosis)) , *templist = *list_diag;
	BiayaPengobatan *temptdk = list_tdk;
	int biaya, nomor, nomortindakan;
	char tindakan[MAX_STRING];
	Date temptanggal;

    printf("Tanggal Kedatangan (dd bulan yyyy): ");
	scanf("%d %s %d", &temptanggal.hari, temptanggal.bulan, &temptanggal.tahun);
	RiwayatBaru->tanggal_cek = temptanggal;
	KonversiKontrol(&temptanggal);
	RiwayatBaru->tanggal_kontrol = temptanggal;

	printf("ID Pasien: ");
	scanf("%*c%[^\n]%*c", RiwayatBaru->id_pasien);
	printf("Diagnosis: ");
	scanf("%[^\n]%*c", RiwayatBaru->diagnosis);
	printf("Tindakan:\n");
	OpsiTindakan(list_tdk, &nomortindakan, &RiwayatBaru->biaya);
	while(temptdk != NULL && nomortindakan != temptdk->nomor){
		temptdk = temptdk->next;
	}
	strcpy(RiwayatBaru->tindakan, temptdk->aktivitas);

	templist = *list_diag;
	while(templist->next != NULL){
		
		templist = templist->next;
	}
	RiwayatBaru->nomor = templist->nomor+1;

	templist->next = RiwayatBaru;
	RiwayatBaru->prev = templist;
	RiwayatBaru->next = NULL;

	printf("\nData kedatangan berhasil ditambahkan!\n");

	return;
}

void DateSearch(Diagnosis* list_diag, int* count, Date* input){
	Diagnosis *templist = list_diag;
	Date tanggal;
	int counter = 0;

	printf("Tanggal Kedatangan (dd Bulan yyyy): ");
	scanf("%d %s %d", &tanggal.hari, tanggal.bulan, &tanggal.tahun);
	printf("\n");

	while(templist != NULL){
		if(tanggal.hari == templist->tanggal_cek.hari && tanggal.tahun == templist->tanggal_cek.tahun && strcmp(tanggal.bulan, templist->tanggal_cek.bulan) == 0){
			counter++;
			printf("\n(%d)\nTanggal: %d %s %d\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nBiaya: %d\n", counter,templist->tanggal_cek.hari, templist->tanggal_cek.bulan, templist->tanggal_cek.tahun, templist->id_pasien, templist->diagnosis, templist->tindakan, templist->biaya);
		}
		templist = templist->next;
	}

	if(counter == 0){
		printf("Tidak ada data kedatangan pada tanggal tersebut!");
	}

	*count = counter;

	return;

}

void DiagIDSearch(Diagnosis* list_diag, int* count, char input[MAX_STRING]){
	Diagnosis *templist = list_diag;
	char IDPasien[MAX_STRING];
	int counter = 0;

	printf("ID Pasien: ");
	scanf("%*c%[^\n]%*c", IDPasien);
	printf("\n");

	while(templist != NULL){
		if(strcmp(IDPasien, templist->id_pasien) == 0){
			counter++;
			printf("\n(%d)\nTanggal: %d %s %d\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nBiaya: %d\n", counter, templist->tanggal_cek.hari, templist->tanggal_cek.bulan, templist->tanggal_cek.tahun, templist->id_pasien, templist->diagnosis, templist->tindakan, templist->biaya);
		}
		templist = templist->next;
	}

	if(counter == 0){
		printf("Tidak ada data kedatangan dari pasien dengan ID tersebut!");
	}

	*count = counter;
	strcpy(input, IDPasien);
}

void CariDiag(Diagnosis* list_diag){
	Diagnosis *templist = list_diag;
	int opsi, ph;
	Date phd;
	char phs[MAX_STRING];

	printf("\nMetode Pencarian:\n1. Tanggal kedatangan\n2. ID Pasien\n3. Tunjukkan semua\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){
		ph = 0;
		Diagnosis *templist = list_diag;
		if(opsi == 1){
			DateSearch(templist, &ph, &phd);
		}
		else if(opsi == 2){
			DiagIDSearch(templist, &ph, phs);
		}
		else if(opsi = 3){
			printDiagnosis(templist);
		}
		else{
			printf("Opsi tidak ditemukan!\n");
		}
		

		printf("\nMetode Pencarian:\n1. Tanggal\n2. ID Pasien\n3. Tunjukkan Semua\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}
	return;
}

void UbahDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk){
	Date temptanggal;
	BiayaPengobatan *temptdk = list_tdk;
	int opsi, tempint, biaya;
	char tempstr[MAX_STRING];

	printf("Pilih Data yang ingin diubah:\n1. Tanggal kedatangan\n2. ID Pasien\n3. Diagnosis\n4. Tindakan\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n\n");

	while(opsi != 0){
		Diagnosis *templist = *list_diag;
		if(opsi == 1){
			printf("Tanggal kedatangan (dd bulan yyyy): ");
			scanf("%d %s %d", &temptanggal.hari, temptanggal.bulan, &temptanggal.tahun);
			printf("\n\n");

			templist->tanggal_cek = temptanggal;

			KonversiKontrol(&temptanggal);
			templist->tanggal_kontrol = temptanggal;

			printf("Data berhasil diubah!");
		}
		else if(opsi == 2){
			printf("ID Pasien: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->id_pasien, tempstr); 

			printf("Data berhasil diubah!");
		}
		else if(opsi == 3){
			printf("Diagnosis: ");
			scanf("%*c%[^\n]%*c", tempstr);
			printf("\n\n");

			strcpy(templist->diagnosis, tempstr); 

			printf("Data berhasil diubah!");

		}
		else if(opsi == 4){
			printf("Tindakan:\n");
			OpsiTindakan(list_tdk, &tempint, &biaya);
			templist->biaya = biaya;

			while(temptdk->nomor != tempint){
				temptdk = temptdk->next;
			}

			strcpy(templist->tindakan, temptdk->aktivitas);

			printf("Data berhasil diubah!");

		}
		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nTanggal: %d %s %d\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nBiaya: %d\n", templist->tanggal_cek.hari, templist->tanggal_cek.bulan, templist->tanggal_cek.tahun, templist->id_pasien, templist->diagnosis, templist->tindakan, templist->biaya);

		*list_diag = templist;

		printf("Pilih Data yang ingin diubah:\n1. Tanggal kedatangan\n2. ID Pasien\n3. Diagnosis\n4. Tindakan\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n\n");
	}

	return;
}

void UbahDiag(Diagnosis** list_diag, Tindakan* list_tdk){
	Diagnosis *templist = *list_diag;
	Date dateinput;
	char idinput[MAX_STRING];
	int opsi, count, subopsi;

	printf("\nMetode Pencarian:\n1. Tanggal kedatangan\n2. ID Pasien\n3. Tunjukkan semua\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){
		Diagnosis *templist = *list_diag;
		count = 0;
		if(opsi == 1){
			DateSearch(templist, &count, &dateinput);
			if(count != 0){	

				printf("Pilih nomor data yang ingin diubah: ");
				scanf("%d", &subopsi);
				printf("\n");
				
				while(subopsi > count || subopsi < 1){
					if(subopsi > count || subopsi < 1){
						printf("Opsi tidak ditemukan!\n");
					}
					printf("Pilih nomor data yang ingin diubah: ");
					scanf("%d", &subopsi);
					printf("\n");
				}
				
				count = 0;

				while(count != subopsi){
					if(templist->tanggal_cek.hari == dateinput.hari && templist->tanggal_cek.tahun == dateinput.tahun && strcmp(templist->tanggal_cek.bulan, dateinput.bulan) == 0){
						count++;
					}
					templist = templist->next;
				}
				UbahDataDiag(&templist, list_tdk);
			}
		}

		else if(opsi == 2){
			DiagIDSearch(templist, &count, idinput);
			if(count != 0){	

				printf("Pilih nomor data yang ingin diubah: ");
				scanf("%d", &subopsi);
				printf("\n");

				while(subopsi > count || subopsi < 1){
					if(subopsi > count || subopsi < 1){
						printf("Opsi tidak ditemukan!\n");
					}
					printf("Pilih nomor data yang ingin diubah: ");
					scanf("%d", &subopsi);
					printf("\n");
				}

				count = 0;
				while(count != subopsi){
					
					if(strcmp(templist->id_pasien, idinput) == 0){
						count++;
					}
					templist = templist->next;
				}
				UbahDataDiag(&templist, list_tdk);
			}
		}

		else if(opsi = 3){
			printDiagnosis(templist);

			while(templist != NULL){
				templist = templist->next;
				count++;
			}

			printf("Pilih nomor data yang ingin diubah: ");
			scanf("%d", &subopsi);
			printf("\n");			
			
			templist = *list_diag;

			while(subopsi > count || subopsi < 1){
				printf("Opsi tidak ditemukan!\n");
				printf("Pilih nomor data yang ingin diubah: ");
				scanf("%d", &subopsi);
				printf("\n");
			}
			
			count = 1;

			while(count != subopsi){
			    count++;
				templist = templist->next;
			}
			UbahDataDiag(&templist, list_tdk);
		}

		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nMetode Pencarian:\n1. Tanggal\n2. ID Pasien\n3. Tunjukkan Semua\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}
	return;
}

void HapusDataDiag(Diagnosis** list_diag, Diagnosis* target){
	Diagnosis *templist = *list_diag;
	int counter = 1;
	if(target->next == NULL){
		while(templist->next->next != NULL){
			templist = templist->next;
		}
		templist->next = NULL;
	}
	else if(target->prev == NULL){
		templist = templist->next;
		templist->prev = NULL;
		*list_diag = templist;
	}
	else{
		while(templist->next != target){
			templist = templist->next;
		}
		templist->next->next->prev = templist;
		templist->next = templist->next->next;
	}

	templist = malloc(sizeof(Diagnosis));
	templist = *list_diag;

	while(templist != NULL){
		templist->nomor = counter;
		templist = templist->next;
		counter++;
	}

	printf("Data kedatangan berhasil dihapus!");

	return;
}

void HapusDiag(Diagnosis** list_diag){

	Diagnosis *templist = *list_diag, *base = *list_diag;
	Date dateinput;
	char idinput[MAX_STRING];
	int opsi, count, subopsi;

	printf("\nMetode Pencarian:\n1. Tanggal kedatangan\n2. ID Pasien\n3. Tunjukkan semua\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){
		Diagnosis *templist = *list_diag, *base = *list_diag;
		count = 0;
		if(opsi == 1){
			DateSearch(templist, &count, &dateinput);
			if(count != 0){	

				printf("Pilih nomor data yang ingin dihapus: ");
				scanf("%d", &subopsi);
				printf("\n");
				

				while(subopsi > count || subopsi < 1){
					if(subopsi > count || subopsi < 1){
						printf("Opsi tidak ditemukan!\n");
					}
					printf("Pilih nomor data yang ingin dihapus: ");
					scanf("%d", &subopsi);
					printf("\n");
				}
				
				count = 0;

				while(count != subopsi){
					if(templist->tanggal_cek.hari == dateinput.hari && templist->tanggal_cek.tahun == dateinput.tahun && strcmp(templist->tanggal_cek.bulan, dateinput.bulan) == 0){
						count++;
					}
					templist = templist->next;
				}
				HapusDataDiag(&base, templist);
				*list_diag = base;
			}
		}

		else if(opsi == 2){
			DiagIDSearch(templist, &count, idinput);
			if(count != 0){	

				printf("Pilih nomor data yang ingin dihapus: ");
				scanf("%d", &subopsi);
				printf("\n");

				while(subopsi > count || subopsi < 1){
					if(subopsi > count || subopsi < 1){
						printf("Opsi tidak ditemukan!\n");
					}
					printf("Pilih nomor data yang ingin dihapus: ");
					scanf("%d", &subopsi);
					printf("\n");
				}

				count = 0;
				while(count != subopsi){
					
					if(strcmp(templist->id_pasien, idinput) == 0){
						count++;
					}
					templist = templist->next;
				}
				HapusDataDiag(&base, templist);
				*list_diag = base;
			}
		}

		else if(opsi = 3){
			printDiagnosis(templist);

			while(templist != NULL){
				templist = templist->next;
				count++;
			}

			printf("Pilih nomor data yang ingin dihapus: ");
			scanf("%d", &subopsi);
			printf("\n");			
			
			templist = *list_diag;

			while(subopsi > count || subopsi < 1){
				printf("Opsi tidak ditemukan!\n");
				printf("Pilih nomor data yang ingin dihapus: ");
				scanf("%d", &subopsi);
				printf("\n");
			}
			
			count = 1;

			while(count != subopsi){
			    count++;
				templist = templist->next;
			}
			HapusDataDiag(&base, templist);
			*list_diag = base;
		}
		else{
			printf("Opsi tidak ditemukan!\n");
		}

		printf("\nMetode Pencarian:\n1. Tanggal\n2. ID Pasien\n3. Tunjukkan Semua\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}
	return;
	
}

void ManajemenDataDiag(Diagnosis** list_diag, BiayaPengobatan* list_tdk) {
	Diagnosis *templist = *list_diag;
	int opsi;

	printf("\nManajemen Riwayat Kedatangan:\n1. Tambah riwayat kedatangan\n2. Cari riwayat kedatangan\n3. Ubah data riwayat kedatangan\n4. Hapus riwayat kedatangan\n0. Kembali\nOpsi: ");
	scanf("%d", &opsi);
	printf("\n");

	while(opsi != 0){

		if(opsi == 1){
			TambahDiag(&templist, list_tdk);
		}
		else if(opsi == 2){
			CariDiag(templist);
		}
		else if(opsi == 3){
			UbahDiag(&templist, list_tdk);
		}
        else if(opsi == 4){
            HapusDiag(&templist);
        }
		else{
			printf("Opsi tidak ditemukan!");
		}

		printf("\nManajemen Riwayat Kedatangan:\n1. Tambah riwayat kedatangan\n2. Cari riwayat kedatangan\n3. Ubah data riwayat kedatangan\n4. Hapus riwayat kedatangan\n0. Kembali\nOpsi: ");
		scanf("%d", &opsi);
		printf("\n");

	}

	*list_diag = templist;
	return;
}
