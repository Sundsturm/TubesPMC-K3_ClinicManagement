//EL2008 - Pemecahan Masalah dengan C 2023/2024
//Topik				: Tugas Besar - Clinic Management
//Kelompok/Kelas	: 03/02
//Nama File			: app.c
//Deskripsi			: 
// Program utama atau main hub dari aplikasi manajemen data klinik
// Program dapat berhasil berjalan jika fitur-fiturnya dijalankan satu per satu (tidak langsung semua fitur dijalankan)

#include "../include/app.h"

// Global variables of windows/popups
GtkWindow* add_diagnosis_form;
GtkWindow* add_pasien_form;
GtkWindow* list_pasien_riwayat_window;
GtkWindow* edit_diagnosis_form;
GtkWindow* edit_pasien_form;
GtkWindow* list_search_diagnosis;
GtkWindow* list_search_pasien;
GtkWindow* main_window;
GtkWindow* pasien_kontrol_form;
GtkWindow* pendapatan_form;
GtkWindow* search_diagnosis_form;
GtkWindow* search_pasien_form;
GtkWindow* pasien_penyakit_form;
GtkWindow* pasien_riwayat_medis_form;

// Global variables of buttons (Normal buttons and radio buttons)
GtkButton* add_diagnosis_submit;
GtkButton* add_pasien_submit;
GtkRadioButton* tanggal_kunjungan_sel_radio;
GtkRadioButton* id_pasien_sel_diagnosis_radio;
GtkRadioButton* diagnosis_sel_radio;
GtkRadioButton* tindakan_sel_radio;
GtkButton* value_diagnosis_submit;
GtkRadioButton* nama_lengkap_sel_radio;
GtkRadioButton* alamat_sel_radio;
GtkRadioButton* kota_sel_radio;
GtkRadioButton* tempat_lahir_sel_radio;
GtkRadioButton* tanggal_lahir_sel_radio;
GtkRadioButton* umur_sel_radio;
GtkRadioButton* bpjs_sel_radio;
GtkButton* value_pasien_submit;
GtkButton* num_diagnosis_submit;
GtkButton* num_pasien_submit;
GtkButton* delete_stack_1;
GtkButton* update_stack_1;
GtkButton* search_stack_1;
GtkButton* create_stack_1;
GtkButton* prev_stack_1;
GtkButton* next_stack_1;
GtkButton* delete_stack_2;
GtkButton* update_stack_2;
GtkButton* search_stack_2;
GtkButton* create_stack_2;
GtkButton* prev_stack_2;
GtkButton* next_stack_2;
GtkButton* button_pasien_riwayat_medis;
GtkButton* button_riwayat_medis;
GtkButton* button_pasien_kontrol;
GtkButton* button_pasien_penyakit;
GtkButton* button_pendapatan;
GtkButton* pasien_kontrol_submit;
GtkButton* pendapatan_submit;
GtkRadioButton* ID_Pasien_diagnosis_element_radio;
GtkRadioButton* Tanggal_Kunjungan_diagnosis_element_radio;
GtkButton* diagnosis_search_submit;
GtkRadioButton* ID_Pasien_pasien_element_radio;
GtkRadioButton* Nama_Lengkap_pasien_element_radio;
GtkButton* pasien_search_submit;
GtkRadioButton* pasien_penyakit_mode1;
GtkRadioButton* pasien_penyakit_mode2;
GtkRadioButton* pasien_penyakit_mode3;
GtkButton* pasien_penyakit_submit;
GtkButton* pasien_riwayat_medis_submit;
GtkFileChooserButton* file_chooser_px;
GtkFileChooserButton* file_chooser_dx;
GtkFileChooserButton* file_chooser_biaya;
GtkButton* button_save;
GtkButton* button_clear_list;
GtkButton* next_penyakit;

// Global variables of labels
GtkLabel* choose_diagnosis_label;
GtkLabel* choose_pasien_label;
GtkLabel* enter_value_search_diagnosis_label;
GtkLabel* enter_value_search_pasien_label;
GtkLabel* pasien_penyakit_mode_bulan_tahun_label;
GtkLabel* pasien_penyakit_mode3_label;

// Global variables of entries
GtkEntry* nama_lengkap_entry;
GtkEntry* alamat_entry;
GtkEntry* kota_entry;
GtkEntry* tempat_lahir_entry;
GtkEntry* tanggal_lahir_entry;
GtkEntry* umur_entry;
GtkEntry* bpjs_entry;
GtkEntry* tanggal_kunjungan_entry;
GtkEntry* ID_Pasien_entry;
GtkEntry* diagnosis_entry;
GtkEntry* tindakan_entry;
GtkEntry* value_diagnosis_entry;
GtkEntry* value_pasien_entry;
GtkEntry* num_diagnosis_entry;
GtkEntry* num_pasien_entry;
GtkEntry* pasien_kontrol_entry;
GtkEntry* bulan_pendapatan_entry;
GtkEntry* tahun_pendapatan_entry;
GtkEntry* value_search_diagnosis_entry;
GtkEntry* value_search_pasien_entry;
GtkEntry* pasien_penyakit_mode_bulan_tahun_entry;
GtkEntry* pasien_penyakit_mode3_entry;
GtkEntry* pasien_riwayat_medis_entry;

// Global variables of treeview and textview
GtkTreeView* filtered_pasien_riwayat;
GtkTreeView* table_search_diagnosis;
GtkTreeView* table_search_pasien;
GtkTreeView* pasien_table;
GtkTreeView* diagnosis_table;
GtkTextView* filtered_pasien_data;
GtkTreeView* filtered_diagnosis_list;
GtkTextView* textview_pasien_penyakit;
GtkTextView* textview_pendapatan;
GtkTreeView* treeview_pasien_penyakit;

// Global variables for images
GtkImage* delete_icon_1;
GtkImage* edit_icon_1;
GtkImage* search_icon_1;
GtkImage* create_icon_1;
GtkImage* delete_icon_2;
GtkImage* edit_icon_2;
GtkImage* search_icon_2;
GtkImage* create_icon_2;
GtkImage* data_pasien_icon;
GtkImage* data_diagnosis_icon;
GtkImage* data_pasien_riwayat_medis_icon;
GtkImage* data_pasien_kontrol_icon;
GtkImage* data_pasien_penyakit_icon;
GtkImage* data_pendapatan_icon;
GtkImage* pasien_riwayat_medis_icon;
GtkImage* pasien_kontrol_icon;
GtkImage* pasien_penyakit_icon;
GtkImage* pendapatan_icon;

// Global variables for builder
GtkBuilder* builder;

// Global variables for list stores
GtkListStore *diagnosis_list;
GtkListStore *pasien_list;
GtkListStore *filter_px_list;
GtkListStore *filter_dx_list;
GtkListStore *list_penyakit_tahun;
GtkListStore *list_penyakit_bulan;
GtkListStore *list_penyakit_spes;

// Global variables for checking
gchar* edit_search_delete_pasien_check;
gchar* edit_search_delete_diagnosis_check;
gchar* penyakit_form_check;
gchar* passing_string;

// Global variables for input
BiayaPengobatan *list_biayapengobatan;
Pasien* list_pasien;
Diagnosis *list_diagnosis;

// Global variables for structs
Diagnosis* filtered_diag;
Pasien* filtered_pasien;
Tahun* penyakit_tahun;
Bulan* penyakit_bulan;
Data* penyakit_spec;

// Global variables for list loaders
int list_pasien_riwayat_loader;
int curr_idd_main;
int curr_idp_main;
int curr_idd_search;
int curr_idp_search;
int curr_idp_riwayat;

// Global variables for data length
int list_px;
int list_dx;
int px_search;
int dx_search;
int px_riwayat;
int count_tahun;
int count_diag;
int curr_penyakit;

// GUI function and procedures
// Handler to hide the window instead of destroying it
void append_to_textview(char *message, GtkTextView* tv){
	GtkTextBuffer* buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
	GtkTextIter iter;

	gtk_text_buffer_get_end_iter(buffer, &iter);
	gtk_text_buffer_insert(buffer, &iter, message, -1);
}

void clear_textview(GtkTextView *text_view){
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    GtkTextIter start_iter, end_iter;
    gtk_text_buffer_get_start_iter(buffer, &start_iter);
    gtk_text_buffer_get_end_iter(buffer, &end_iter);
    gtk_text_buffer_delete(buffer, &start_iter, &end_iter);
}

void remove_all_cols(GtkTreeView *tree_view){
    gint num_columns = gtk_tree_view_get_n_columns(tree_view);
    for (gint i = num_columns - 1; i >= 0; i--) {
        GtkTreeViewColumn *column = gtk_tree_view_get_column(tree_view, i);
        gtk_tree_view_remove_column(tree_view, column);
    }
}

gboolean on_window_delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    gtk_widget_hide(widget);
    return TRUE;  // Prevents the default handler from running
}

void create_cols_px(GtkTreeView* tree_view){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn * col;
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("No.", renderer, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Nama Lengkap", renderer, "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Alamat", renderer, "text", 2, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Kota", renderer, "text", 3, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Tempat Lahir", renderer, "text", 4, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Tanggal Lahir", renderer, "text", 5, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Umur", renderer, "text", 6, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("No. BPJS", renderer, "text", 7, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
	renderer = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("ID Pasien", renderer, "text", 8, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col);
}

void create_cols_dx(GtkTreeView *tree_view){
	GtkCellRenderer *rend_dx;
	GtkTreeViewColumn * col_dx;
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("No.", rend_dx, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("Tanggal Kunjungan", rend_dx, "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("ID Pasien", rend_dx, "text", 2, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("Diagnosis", rend_dx, "text", 3, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("Tindakan", rend_dx, "text", 4, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("Tanggal Kontrol", rend_dx, "text", 5, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
	rend_dx = gtk_cell_renderer_text_new();
	col_dx = gtk_tree_view_column_new_with_attributes("Biaya (Rp)", rend_dx, "text", 6, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), col_dx);
}

void create_cols_one(GtkTreeView *treev){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn * column;
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Tahun", renderer, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Diagnosis", renderer, "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Total", renderer, "text", 2, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
}

void create_cols_two(GtkTreeView *treev){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn * column;
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Bulan", renderer, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Diagnosis", renderer, "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Total", renderer, "text", 2, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
}

void create_cols_three(GtkTreeView *treev){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn * column;
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Diagnosis", renderer, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Total", renderer, "text", 1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treev), column);
}

void populate_list_modeone(GtkListStore* list_store, Tahun *list_one, int len_tahun, int len_diagnose) {
	GtkTreeIter iter;
	gtk_list_store_clear(list_store);
	Tahun *temp = list_one;

	for(int i = 0; i < len_tahun; i++){
		for(int j = 0; j < len_diagnose; j++){
			gtk_list_store_append(list_store, &iter);
			gtk_list_store_set(list_store, &iter,
				0, temp[i].year,
				1, temp[i].diagnoses[j].diagnose,
				2, temp[i].diagnoses[j].total,
				-1);
		}
	}
}

void populate_list_modetwo(GtkListStore* list_store, Bulan *list_one, int len_diagnose, int *curr_x) {
	GtkTreeIter iter;
	gtk_list_store_clear(list_store);
	Bulan *temp = list_one;
	if(*curr_x == 12){
		*curr_x = 0;
	}
	for(int j = 0; j < len_diagnose; j++){
		gtk_list_store_append(list_store, &iter);
		gtk_list_store_set(list_store, &iter,
			0, temp[*curr_x].bulan,
			1, temp[*curr_x].diagnoses[j].diagnose,
			2, temp[*curr_x].diagnoses[j].total,
			-1);
	}
	++(*curr_x);
}

void populate_list_modethree(GtkListStore* list_store, Data *list_one, int len_diagnose) {
	GtkTreeIter iter;
	gtk_list_store_clear(list_store);
	Data *temp = list_one;
	for(int j = 0; j < len_diagnose; j++){
		gtk_list_store_append(list_store, &iter);
		gtk_list_store_set(list_store, &iter,
			0, temp[j].diagnose,
			1, temp[j].total,
			-1);
	}
}

void populate_list_pasien(GtkListStore* list_store, Pasien* list_pt, int len_pt, int *curr_id_px, int cond_prev_next) {
	GtkTreeIter iter;
	gtk_list_store_clear(list_store);
	Pasien *temp = list_pt;
	int null_checker;
	null_checker = 0;

	// Iterate based on current id
	for(int i = 0; i < (*curr_id_px); i++){
		if(temp == NULL) break;
		temp = temp -> next;
	}


	// Handling extreme case on next button (NULL cases)
	if(temp == NULL){
		null_checker = 1;
		temp = list_pt;
		*curr_id_px = len_pt - CHUNK;
		for(int i = 0; i < (*curr_id_px); i++){
			if(temp == NULL) break;
			temp = temp -> next;
		}
	}

	// Handling extreme cases on previous button (NULL cases)
	if(cond_prev_next == 1){
		if(temp->prev == NULL){
			temp = list_pt;
			*curr_id_px = 0;
		} else {
			if(null_checker == 1){
				for(int i = 0; i < CHUNK && temp->prev != NULL; i++){
					temp = temp -> prev;
					--(*curr_id_px);
				}
				null_checker = 0;
			} else {
				for(int i = 0; i < 2*CHUNK && temp->prev != NULL; i++){
					temp = temp -> prev;
					--(*curr_id_px);
				}
			}
		}
	}

	for(int i = 0; (i < CHUNK) && temp != NULL; i++){
		char res_t_lahir[MAX_STRING];
		snprintf(res_t_lahir, sizeof(res_t_lahir), "%d %s %d", temp->tanggal_lahir.hari, temp->tanggal_lahir.bulan, temp->tanggal_lahir.tahun);
		gtk_list_store_append(list_store, &iter);
		gtk_list_store_set(list_store, &iter,
			0, temp->nomor,
			1, temp->nama_lengkap,
			2, temp->alamat,
			3, temp->kota,
			4, temp->tempat_lahir,
			5, res_t_lahir,
			6, temp->umur,
			7, temp->bpjs,
			8, temp->id_pasien,
			-1);
		temp = temp->next;
		++(*curr_id_px);
	}
}

void populate_list_diagnosis(GtkListStore* list_store, Diagnosis* list_dt, int len_dt, int *curr_id_dx, int cond_prev_next) {
	GtkTreeIter iter;
	gtk_list_store_clear(list_store);
	Diagnosis *temp = list_dt;
	int null_checker;
	null_checker = 0;

	// Iterate based on current id
	for(int i = 0; i < (*curr_id_dx); i++){
		if(temp == NULL) break;
		temp = temp -> next;
	}


	// Handling extreme case on next button (NULL cases)
	if(temp == NULL){
		null_checker = 1;
		temp = list_dt;
		*curr_id_dx = len_dt - CHUNK;
		for(int i = 0; i < (*curr_id_dx); i++){
			if(temp == NULL) break;
			temp = temp -> next;
		}
	}

	// Handling extreme cases on previous button (NULL cases)
	if(cond_prev_next == 1){
		if(temp->prev == NULL){
			temp = list_dt;
			*curr_id_dx = 0;
		} else {
			if(null_checker == 1){
				for(int i = 0; i < CHUNK && temp->prev != NULL; i++){
					temp = temp -> prev;
					--(*curr_id_dx);
				}
				null_checker = 0;
			} else {
				for(int i = 0; i < 2*CHUNK && temp->prev != NULL; i++){
					temp = temp -> prev;
					--(*curr_id_dx);
				}
			}
		}
	}

	for(int i = 0; (i < CHUNK) && temp != NULL; i++){
		char res_t_cek[MAX_STRING];
		snprintf(res_t_cek, sizeof(res_t_cek), "%d %s %d", temp->tanggal_cek.hari, temp->tanggal_cek.bulan, temp->tanggal_cek.tahun);
		char res_t_kon[MAX_STRING];
		snprintf(res_t_kon, sizeof(res_t_kon), "%d %s %d", temp->tanggal_kontrol.hari, temp->tanggal_kontrol.bulan, temp->tanggal_kontrol.tahun);
		gtk_list_store_append(list_store, &iter);
		gtk_list_store_set(list_store, &iter,
			0, temp->nomor,
			1, res_t_cek,
			2, temp->id_pasien,
			3, temp->diagnosis,
			4, temp->tindakan,
			5, res_t_kon,
			6, temp->biaya,
			-1);
		temp = temp->next;
		++(*curr_id_dx);
	}
}

void on_entry_changed (GtkEntry* e, gpointer user_data){
	int string_length = strlen((char*)gtk_entry_get_text(GTK_ENTRY(e)));
	int curr_entry = gtk_editable_get_position(GTK_EDITABLE(e));
	if(curr_entry < 0 || curr_entry > string_length) curr_entry = string_length;
	gtk_editable_set_position(GTK_EDITABLE(e), curr_entry);
}

void on_add_diagnosis_submit_clicked (GtkButton*  b, gpointer user_data){
	TambahDiag(&list_diagnosis, list_biayapengobatan, (char*)gtk_entry_get_text(GTK_ENTRY(tanggal_kunjungan_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(ID_Pasien_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(diagnosis_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(tindakan_entry)), &list_dx);
	gtk_entry_set_text(GTK_ENTRY(tanggal_kunjungan_entry), "");
	gtk_entry_set_text(GTK_ENTRY(ID_Pasien_entry), "");
	gtk_entry_set_text(GTK_ENTRY(diagnosis_entry), "");
	gtk_entry_set_text(GTK_ENTRY(tindakan_entry), "");

	gtk_widget_hide(GTK_WIDGET(add_diagnosis_form));
}	

void on_add_pasien_submit_clicked (GtkButton*  b, gpointer user_data){
	TambahPasien(&list_pasien, (char*)gtk_entry_get_text(GTK_ENTRY(nama_lengkap_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(alamat_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(kota_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(tempat_lahir_entry)), (char*)gtk_entry_get_text(GTK_ENTRY(tanggal_lahir_entry)), atoi((char*)gtk_entry_get_text(GTK_ENTRY(umur_entry))), (char*)gtk_entry_get_text(GTK_ENTRY(bpjs_entry)), &list_px);
	gtk_entry_set_text(GTK_ENTRY(nama_lengkap_entry), "");
	gtk_entry_set_text(GTK_ENTRY(alamat_entry), "");
	gtk_entry_set_text(GTK_ENTRY(kota_entry), "");
	gtk_entry_set_text(GTK_ENTRY(tempat_lahir_entry), "");
	gtk_entry_set_text(GTK_ENTRY(tanggal_lahir_entry), "");
	gtk_entry_set_text(GTK_ENTRY(umur_entry), "");
	gtk_entry_set_text(GTK_ENTRY(bpjs_entry), "");
	gtk_widget_hide(GTK_WIDGET(add_pasien_form));
}

void on_tanggal_kunjungan_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_diagnosis_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_diagnosis_entry), "Format: DD Bulan YYYY");
	} else {
		g_print("Tanggal Kunjungan tidak aktif!\n");
	}
}

void on_id_pasien_sel_diagnosis_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_diagnosis_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_diagnosis_entry), "Format: KX ...");
	} else {
		g_print("ID Pasien tidak aktif!\n");
	}
}

void on_diagnosis_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_diagnosis_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_diagnosis_entry), "Contoh: Masuk Angin");
	} else {
		g_print("Diagnosis tidak aktif!\n");
	}
}

void on_tindakan_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_diagnosis_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_diagnosis_entry), "Contoh: Pemasangan infus");
	} else {
		g_print("Tindakan tidak aktif!\n");
	}
}

void on_value_diagnosis_submit_clicked (GtkButton*  b, gpointer user_data){
	gtk_widget_hide(GTK_WIDGET(edit_diagnosis_form));
	UbahDataDiag(&list_diagnosis, list_biayapengobatan, (char*)gtk_entry_get_text(GTK_ENTRY(value_diagnosis_entry)), edit_search_delete_diagnosis_check, atoi(passing_string));
	gtk_entry_set_text(GTK_ENTRY(value_diagnosis_entry), "");
}

void on_nama_lengkap_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: Budi Maknyus");
	} else {
		g_print("Nama Lengkap tidak aktif!\n");
	}
}

void on_alamat_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: Jl. Menuju Surga No. 12");
	} else {
		g_print("Alamat tidak aktif!\n");
	}
}

void on_kota_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: Kota Jakarta Adem");
	} else {
		g_print("Kota tidak aktif!\n");
	}
}

void on_tempat_lahir_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: Sumedang");
	} else {
		g_print("Tempat Lahir tidak aktif!\n");
	}
}

void on_tanggal_lahir_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Format: DD Bulan YYYY");
	} else {
		g_print("Tanggal Lahir tidak aktif!\n");
	}
}

void on_umur_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: 1");
	} else {
		g_print("Umur tidak aktif!\n");
	}
}

void on_bpjs_sel_radio_toggled (GtkRadioButton*  b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		strcpy(edit_search_delete_pasien_check, (char*)gtk_button_get_label(GTK_BUTTON(b)));
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_pasien_entry), "Contoh: 1111111111");
	} else {
		g_print("No. BPJS tidak aktif!\n");
	}
}

void on_value_pasien_submit_clicked (GtkButton*  b, gpointer user_data){
	gtk_widget_hide(GTK_WIDGET(edit_pasien_form));
	UbahDataPasien(&list_pasien, (char*)gtk_entry_get_text(GTK_ENTRY(value_pasien_entry)), edit_search_delete_pasien_check, atoi(passing_string));
	gtk_entry_set_text(GTK_ENTRY(value_pasien_entry), "");
}

void on_num_diagnosis_submit_clicked (GtkButton*  b, gpointer user_data){
	free_diagnosis_list(filtered_diag);
	strcpy(passing_string, (char*)gtk_entry_get_text(GTK_ENTRY(num_diagnosis_entry)));
	gtk_widget_hide(GTK_WIDGET(list_search_diagnosis));
	if(strcmp(edit_search_delete_diagnosis_check, "edit") == 0){
		gtk_widget_show(GTK_WIDGET(edit_diagnosis_form));
	} else if (strcmp(edit_search_delete_diagnosis_check, "delete") == 0){
		gtk_entry_set_text(GTK_ENTRY(num_diagnosis_entry), "");
		HapusDataDiag(&list_diagnosis, atoi(passing_string));
	} else {
		g_print("Tidak ada pilihan yang tepat!");
	}
}

void on_num_pasien_submit_clicked (GtkButton*  b, gpointer user_data){
	free_pasien_list(filtered_pasien);
	strcpy(passing_string, (char*)gtk_entry_get_text(GTK_ENTRY(num_pasien_entry)));
	gtk_widget_hide(GTK_WIDGET(list_search_pasien));
	if(strcmp(edit_search_delete_pasien_check, "edit") == 0){
		gtk_widget_show(GTK_WIDGET(edit_pasien_form));
	} else if (strcmp(edit_search_delete_pasien_check, "delete") == 0){
		gtk_entry_set_text(GTK_ENTRY(num_pasien_entry), "");
		HapusDataPasien(&list_pasien, atoi(passing_string));
	} else {
		g_print("Tidak ada pilihan yang tepat!");
	}
}

void on_delete_stack_1_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present((search_pasien_form));
	strcpy(edit_search_delete_pasien_check, "delete");
}

void on_update_stack_1_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present((search_pasien_form));
	strcpy(edit_search_delete_pasien_check, "edit");
}

void on_search_stack_1_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present(search_pasien_form);
	strcpy(edit_search_delete_pasien_check, "search");
}

void on_create_stack_1_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present(add_pasien_form);
}

void on_prev_stack_1_clicked (GtkButton*  b, gpointer user_data){
	populate_list_pasien(GTK_LIST_STORE(pasien_list), list_pasien, list_px, &curr_idp_main, 1);
}

void on_next_stack_1_clicked (GtkButton*  b, gpointer user_data){
	populate_list_pasien(GTK_LIST_STORE(pasien_list), list_pasien, list_px, &curr_idp_main, 0);
}

void on_delete_stack_2_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present((search_diagnosis_form));
	strcpy(edit_search_delete_diagnosis_check, "delete");
}

void on_update_stack_2_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present((search_diagnosis_form));
	strcpy(edit_search_delete_diagnosis_check, "edit");
}

void on_search_stack_2_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present((search_diagnosis_form));
	strcpy(edit_search_delete_diagnosis_check, "search");
}

void on_create_stack_2_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present(add_diagnosis_form);
}

void on_prev_stack_2_clicked (GtkButton*  b, gpointer user_data){
	populate_list_diagnosis(GTK_LIST_STORE(diagnosis_list), list_diagnosis, list_dx, &curr_idd_main, 1);
}

void on_next_stack_2_clicked (GtkButton*  b, gpointer user_data){
	populate_list_diagnosis(GTK_LIST_STORE(diagnosis_list), list_diagnosis, list_dx, &curr_idd_main, 0);
}

void on_button_pasien_riwayat_medis_clicked (GtkButton*  b, gpointer user_data){
	gtk_window_present(pasien_riwayat_medis_form);
}

void on_button_riwayat_medis_clicked (GtkButton* b, gpointer user_data){
	px_riwayat = 0;
	filtered_diag = DiagIDSearch(list_diagnosis, passing_string, &px_riwayat);
	populate_list_diagnosis(filter_dx_list, filtered_diag, px_riwayat, &curr_idp_riwayat, 0);
	gtk_window_present(list_pasien_riwayat_window);
}

void on_button_pasien_kontrol_clicked (GtkButton* b, gpointer user_data){
	gtk_window_present(pasien_kontrol_form);
}

void on_button_pasien_penyakit_clicked (GtkButton* b, gpointer user_data){
	gtk_window_present(pasien_penyakit_form);
	gtk_widget_hide(GTK_WIDGET(pasien_penyakit_mode3_entry));
	gtk_widget_hide(GTK_WIDGET(pasien_penyakit_mode_bulan_tahun_entry));
	gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode3_label), "");
	gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode_bulan_tahun_label), "");
}

void on_button_pendapatan_clicked (GtkButton *b, gpointer user_data){
	gtk_window_present(pendapatan_form);
}

void on_pasien_kontrol_submit_clicked (GtkButton *b, gpointer user_data){
	dx_search = 0;
	filtered_diag = PasienForKontrol(list_diagnosis, (char*)(gtk_entry_get_text(GTK_ENTRY(pasien_kontrol_entry))), &dx_search);
	populate_list_diagnosis(filter_dx_list, filtered_diag, dx_search, &curr_idd_search, 0);
	gtk_entry_set_text(GTK_ENTRY(pasien_kontrol_entry), "");
	gtk_widget_hide(GTK_WIDGET(pasien_kontrol_form));
}

void on_pendapatan_submit_clicked (GtkButton *b, gpointer user_data){
	char *message = (char*)malloc(MAX_STRING*sizeof(char));
	message = rataRataPendapatan(list_diagnosis, list_biayapengobatan, (char*)(gtk_entry_get_text(GTK_ENTRY(bulan_pendapatan_entry))), atoi((char*)(gtk_entry_get_text(GTK_ENTRY(tahun_pendapatan_entry)))));
	append_to_textview(message, GTK_TEXT_VIEW(textview_pendapatan));
	gtk_entry_set_text(GTK_ENTRY(bulan_pendapatan_entry), "");
	gtk_entry_set_text(GTK_ENTRY(tahun_pendapatan_entry), "");
	gtk_widget_hide(GTK_WIDGET(pendapatan_form));
	free(message);
}

void on_ID_Pasien_diagnosis_element_radio_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(enter_value_search_diagnosis_label), (const gchar*) "Masukkan ID Pasien");
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_search_diagnosis_entry), (const gchar*) "Format: KX ...");
	} else {
		g_print("Tombol ID Pasien tidak aktif!\n");
	}
}

void on_Tanggal_Kunjungan_diagnosis_element_radio_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(enter_value_search_diagnosis_label), (const gchar*) "Masukkan Tanggal Kunjungan");
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_search_diagnosis_entry), (const gchar*) "Format: DD Bulan YYYY");
	} else {
		g_print("Tombol Tanggal Kunjungan tidak aktif!\n");
	}
}

void on_ID_Pasien_pasien_element_radio_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(enter_value_search_pasien_label), (const gchar*) "Masukkan ID Pasien");
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_search_pasien_entry), (const gchar*) "Format: KX ...");
	} else {
		g_print("Tombol ID Pasien tidak aktif!\n");
	}
}

void on_Nama_Lengkap_pasien_element_radio_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(enter_value_search_pasien_label), (const gchar*) "Masukkan Nama Lengkap:");
		gtk_entry_set_placeholder_text(GTK_ENTRY(value_search_pasien_entry), (const gchar*) "Contoh: Budi Maknyus");
	} else {
		g_print("Tombol Nama Lengkap tidak aktif!\n");
	}
}

void on_pasien_search_submit_clicked (GtkButton *b, gpointer user_data){
	px_search = 0;
	curr_idp_search = 0;
	strcpy(passing_string, gtk_entry_get_text(GTK_ENTRY(value_search_pasien_entry)));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Nama_Lengkap_pasien_element_radio))){
		filtered_pasien = NameSearch(list_pasien, passing_string, &px_search);
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ID_Pasien_pasien_element_radio))){
		filtered_pasien = IDSearch(list_pasien, passing_string, &px_search);
	} else {
		g_print("Tidak ada button lain!\n");
	}
	gtk_widget_hide(GTK_WIDGET(search_pasien_form));
	populate_list_pasien(filter_px_list, filtered_pasien, px_search, &curr_idp_search, 0);
	gtk_widget_show_all(GTK_WIDGET(list_search_pasien));
	if(strcmp(edit_search_delete_pasien_check, "edit") == 0 || strcmp(edit_search_delete_pasien_check, "delete") == 0){
		gtk_label_set_text(GTK_LABEL(choose_pasien_label), "Masukkan Nomor sesuai data yang diinginkan:");
		gtk_entry_set_placeholder_text(GTK_ENTRY(num_pasien_entry), "Contoh: 1/Contoh: 20");
	} else if (strcmp(edit_search_delete_pasien_check, "search") == 0){
		gtk_widget_hide(GTK_WIDGET(choose_pasien_label));
		gtk_widget_hide(GTK_WIDGET(num_pasien_entry));
		gtk_widget_hide(GTK_WIDGET(num_pasien_submit));
	} else {
		g_print("Tidak ada modenya!\n");
	}
	gtk_entry_set_text(GTK_ENTRY(value_search_pasien_entry), "");
}

void on_diagnosis_search_submit_clicked (GtkButton *b, gpointer user_data){
	dx_search = 0;
	curr_idd_search = 0;
	strcpy(passing_string, gtk_entry_get_text(GTK_ENTRY(value_search_diagnosis_entry)));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Tanggal_Kunjungan_diagnosis_element_radio))){
		filtered_diag = DateSearch(list_diagnosis, passing_string, &dx_search);
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ID_Pasien_diagnosis_element_radio))){
		filtered_diag = DiagIDSearch(list_diagnosis, passing_string, &dx_search);
	} else {
		g_print("Tidak ada button lain!\n");
	}
	gtk_widget_hide(GTK_WIDGET(search_diagnosis_form));
	populate_list_diagnosis(filter_dx_list, filtered_diag, dx_search, &curr_idd_search, 0);
	gtk_widget_show_all(GTK_WIDGET(list_search_diagnosis));
	if(strcmp(edit_search_delete_diagnosis_check, "edit") == 0 || strcmp(edit_search_delete_diagnosis_check, "delete") == 0){
		gtk_label_set_text(GTK_LABEL(choose_diagnosis_label), "Masukkan Nomor sesuai data yang diinginkan:");
		gtk_entry_set_placeholder_text(GTK_ENTRY(num_diagnosis_entry), "Contoh: 1/Contoh: 20");
	} else if (strcmp(edit_search_delete_diagnosis_check, "search") == 0){
		gtk_widget_hide(GTK_WIDGET(choose_diagnosis_label));
		gtk_widget_hide(GTK_WIDGET(num_diagnosis_entry));
		gtk_widget_hide(GTK_WIDGET(num_diagnosis_submit));
	} else {
		g_print("Tidak ada modenya!\n");
	}
	gtk_entry_set_text(GTK_ENTRY(value_search_diagnosis_entry), "");
}

void on_pasien_penyakit_mode1_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode3_label), (const gchar*) " ");
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode_bulan_tahun_label), (const gchar*) " ");
		gtk_widget_hide(GTK_WIDGET(pasien_penyakit_mode_bulan_tahun_entry));
		gtk_widget_hide(GTK_WIDGET(pasien_penyakit_mode3_entry));
	} else {
		g_print("Mode 1 tidak aktif!\n");
	}
}

void on_pasien_penyakit_mode2_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode_bulan_tahun_label), (const gchar*) "Masukkan Tahun:");
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode3_label), (const gchar*) " ");
		gtk_widget_hide(GTK_WIDGET(pasien_penyakit_mode3_entry));
		gtk_widget_show(GTK_WIDGET(pasien_penyakit_mode_bulan_tahun_entry));
	} else {
		g_print("Mode 2 tidak aktif!\n");
	}
}

void on_pasien_penyakit_mode3_toggled (GtkRadioButton* b, gpointer user_data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))){
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode_bulan_tahun_label), (const gchar*) "Masukkan Bulan:");
		gtk_label_set_text(GTK_LABEL(pasien_penyakit_mode3_label), (const gchar*) "Masukkan Tahun:");
		gtk_widget_show(GTK_WIDGET(pasien_penyakit_mode_bulan_tahun_entry));
		gtk_widget_show(GTK_WIDGET(pasien_penyakit_mode3_entry));
	} else {
		g_print("Mode 3 tidak aktif!\n");
	}
}

void on_pasien_penyakit_submit_clicked (GtkButton *b, gpointer user_data){
	char* message;
	count_tahun = 0;
	count_diag = 0;
	curr_penyakit = 0;
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pasien_penyakit_mode1))){
		message = (char*)malloc(MAX_STRING*sizeof(char));
		gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_pasien_penyakit), GTK_TREE_MODEL(list_penyakit_tahun));
		allYear(list_diagnosis, &penyakit_tahun, &count_tahun, &count_diag);
		populate_list_modeone(list_penyakit_tahun, penyakit_tahun, count_tahun, count_diag);
		create_cols_one(GTK_TREE_VIEW(treeview_pasien_penyakit));
		snprintf(message, MAX_STRING, "Total tahun yang tercatat: %d\nTotal penyakit yang terdiagnosis: %d\n", count_tahun, count_diag);
		append_to_textview(message, GTK_TEXT_VIEW(textview_pasien_penyakit));
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pasien_penyakit_mode2))){
		message = (char*)malloc(MAX_STRING*sizeof(char));
		gtk_widget_show(GTK_WIDGET(next_penyakit));
		gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_pasien_penyakit), GTK_TREE_MODEL(list_penyakit_bulan));
		create_cols_two(GTK_TREE_VIEW(treeview_pasien_penyakit));
		perYear(list_diagnosis, atoi((char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry)))), &penyakit_bulan, &count_diag);
		populate_list_modetwo(list_penyakit_bulan, penyakit_bulan, count_diag, &curr_penyakit);
		snprintf(message, MAX_STRING, "Tahun: %d\nTotal penyakit yang terdiagnosis: %d\n", atoi((char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry)))), count_diag);
		append_to_textview(message, GTK_TEXT_VIEW(textview_pasien_penyakit));
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pasien_penyakit_mode3))) {
		message = (char*)malloc(MAX_STRING*sizeof(char));
		gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_pasien_penyakit), GTK_TREE_MODEL(list_penyakit_spes));
		create_cols_three(GTK_TREE_VIEW(treeview_pasien_penyakit));
		perMonth(list_diagnosis, atoi((char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode3_entry)))), (char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry))), &penyakit_spec, &count_diag);
		populate_list_modethree(list_penyakit_spes, penyakit_spec, count_diag);
		snprintf(message, MAX_STRING, "Bulan dan Tahun: %s %d\nTotal penyakit yang terdiagnosis: %d\n", (char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry))), atoi((char*)(gtk_entry_get_text(GTK_ENTRY(pasien_penyakit_mode3_entry)))), count_diag);
		append_to_textview(message, GTK_TEXT_VIEW(textview_pasien_penyakit));
	} else {
		g_print("Opsi tidak terpilih!\n");
	}
	gtk_widget_hide(GTK_WIDGET(pasien_penyakit_form));
	gtk_entry_set_text(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry), "");
	gtk_entry_set_text(GTK_ENTRY(pasien_penyakit_mode3_entry), "");
	free(message);
}

void on_next_penyakit_clicked(GtkButton *b, gpointer user_data){
	populate_list_modetwo(list_penyakit_bulan, penyakit_bulan, count_diag, &curr_penyakit);
}

void on_pasien_riwayat_medis_submit_clicked (GtkButton *b, gpointer user_data){
	char *new_message;
	strcpy(passing_string, (char*)gtk_entry_get_text(GTK_ENTRY(pasien_riwayat_medis_entry)));
	new_message = informasiPasienRiwayatMedis(list_pasien, (const char*)gtk_entry_get_text(GTK_ENTRY(pasien_riwayat_medis_entry)));
	append_to_textview(new_message, GTK_TEXT_VIEW(filtered_pasien_data));
	gtk_widget_hide(GTK_WIDGET(pasien_riwayat_medis_form));
	gtk_entry_set_text(GTK_ENTRY(pasien_riwayat_medis_entry), "");
	free(new_message);
}

void on_file_chooser_px_file_set (GtkFileChooserButton*b, gpointer user_data){
	readPasienData(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(b)), &list_pasien);
	populate_list_pasien(pasien_list, list_pasien, list_px, &curr_idp_main, 0);
	countLenPasien(list_pasien, &list_px);
}

void on_file_chooser_dx_file_set (GtkFileChooserButton*b, gpointer user_data){
	readDiagnosisData(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(b)), &list_diagnosis);
	populate_list_diagnosis(diagnosis_list, list_diagnosis, list_dx, &curr_idd_main, 0);
	countLenDiagnosis(list_diagnosis, &list_dx);
}

void on_file_chooser_biaya_file_set (GtkFileChooserButton*b, gpointer user_data){
	readBiayaPengobatanData(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(b)), &list_biayapengobatan);
}

void on_button_save_clicked (GtkButton*b, gpointer user_data){
	writeCSVDiagnosis("../resources/DataPMC20232024(2).csv", list_diagnosis);
	writeCSVPasien("../resources/DataPMC20232024(1).csv", list_pasien);
}

void on_button_clear_list_clicked (GtkButton*b, gpointer user_data){
	gtk_list_store_clear(GTK_LIST_STORE(filter_dx_list));
	gtk_list_store_clear(GTK_LIST_STORE(filter_px_list));
	gtk_list_store_clear(GTK_LIST_STORE(list_penyakit_tahun));
	gtk_list_store_clear(GTK_LIST_STORE(list_penyakit_bulan));
	gtk_list_store_clear(GTK_LIST_STORE(list_penyakit_spes));
	remove_all_cols(GTK_TREE_VIEW(treeview_pasien_penyakit));
	clear_textview(GTK_TEXT_VIEW(filtered_pasien_data));
	clear_textview(GTK_TEXT_VIEW(textview_pasien_penyakit));
	clear_textview(GTK_TEXT_VIEW(textview_pendapatan));
	px_search = 0;
	dx_search = 0;
	px_riwayat = 0;
	count_tahun = 0;
	count_diag = 0;
	curr_idd_search = 0;
	curr_idp_search = 0;
	curr_idp_riwayat = 0;
	gtk_widget_hide(GTK_WIDGET(next_penyakit));
}

int main(int argc, char *argv[]){
    // Define and read datas
	curr_idd_main = 0;
	curr_idp_main = 0;
	list_px = 0;
	list_dx = 0;
	penyakit_bulan = NULL;
	penyakit_tahun = NULL;
	penyakit_spec = NULL;
	edit_search_delete_pasien_check = (char*)malloc(MAX_STRING * sizeof(char)); 
	edit_search_delete_diagnosis_check = (char*)malloc(MAX_STRING * sizeof(char)); 
    passing_string = (char*)malloc(MAX_STRING * sizeof(char));
	penyakit_form_check = (char*)malloc(MAX_STRING*sizeof(char));

	// Create a GTK application
	gtk_init(&argc, &argv);

	// Connect builder 
	builder = gtk_builder_new_from_file("../app/ui/main_interface.glade");

	// Main window
	main_window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// Get everything from the builder
	// Windows
	add_diagnosis_form = GTK_WINDOW(gtk_builder_get_object(builder, "add_diagnosis_form"));
	add_pasien_form = GTK_WINDOW(gtk_builder_get_object(builder, "add_pasien_form"));
	list_pasien_riwayat_window = GTK_WINDOW(gtk_builder_get_object(builder, "list_pasien_riwayat_window"));
	edit_diagnosis_form = GTK_WINDOW(gtk_builder_get_object(builder, "edit_diagnosis_form"));
	edit_pasien_form = GTK_WINDOW(gtk_builder_get_object(builder, "edit_pasien_form"));
	list_search_diagnosis = GTK_WINDOW(gtk_builder_get_object(builder, "list_search_diagnosis"));
	list_search_pasien = GTK_WINDOW(gtk_builder_get_object(builder, "list_search_pasien"));
	pasien_kontrol_form = GTK_WINDOW(gtk_builder_get_object(builder, "pasien_kontrol_form"));
	pendapatan_form = GTK_WINDOW(gtk_builder_get_object(builder, "pendapatan_form"));
	search_diagnosis_form = GTK_WINDOW(gtk_builder_get_object(builder, "search_diagnosis_form"));
	search_pasien_form = GTK_WINDOW(gtk_builder_get_object(builder, "search_pasien_form"));
	pasien_penyakit_form = GTK_WINDOW(gtk_builder_get_object(builder, "pasien_penyakit_form"));
	pasien_riwayat_medis_form = GTK_WINDOW(gtk_builder_get_object(builder, "pasien_riwayat_medis_form"));
	g_signal_connect(add_diagnosis_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(add_pasien_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(list_pasien_riwayat_window, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(edit_diagnosis_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(edit_pasien_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(list_search_diagnosis, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(list_search_pasien, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(pasien_kontrol_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(pendapatan_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(search_diagnosis_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(search_pasien_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(pasien_penyakit_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
	g_signal_connect(pasien_riwayat_medis_form, "delete-event", G_CALLBACK(on_window_delete_event), NULL);

	// Buttons
	add_diagnosis_submit = GTK_BUTTON(gtk_builder_get_object(builder, "add_diagnosis_submit"));
	add_pasien_submit = GTK_BUTTON(gtk_builder_get_object(builder, "add_pasien_submit"));
	tanggal_kunjungan_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "tanggal_kunjungan_sel_radio"));
	id_pasien_sel_diagnosis_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "id_pasien_sel_diagnosis_radio"));
	diagnosis_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "diagnosis_sel_radio"));
	tindakan_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "tindakan_sel_radio"));
	value_diagnosis_submit = GTK_BUTTON(gtk_builder_get_object(builder, "value_diagnosis_submit"));
	nama_lengkap_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "nama_lengkap_sel_radio"));
	alamat_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "alamat_sel_radio"));
	kota_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "kota_sel_radio"));
	tempat_lahir_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "tempat_lahir_sel_radio"));
	tanggal_lahir_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "tanggal_lahir_sel_radio"));
	umur_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "umur_sel_radio"));
	bpjs_sel_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "bpjs_sel_radio"));
	value_pasien_submit = GTK_BUTTON(gtk_builder_get_object(builder, "value_pasien_submit"));
	num_diagnosis_submit = GTK_BUTTON(gtk_builder_get_object(builder, "num_diagnosis_submit"));
	num_pasien_submit = GTK_BUTTON(gtk_builder_get_object(builder, "num_pasien_submit"));
	delete_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "delete_stack_1"));
	update_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "update_stack_1"));
	search_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "search_stack_1"));
	create_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "create_stack_1"));
	prev_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "prev_stack_1"));
	next_stack_1 = GTK_BUTTON(gtk_builder_get_object(builder, "next_stack_1"));
	delete_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "delete_stack_2"));
	update_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "update_stack_2"));
	search_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "search_stack_2"));
	create_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "create_stack_2"));
	prev_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "prev_stack_2"));
	next_stack_2 = GTK_BUTTON(gtk_builder_get_object(builder, "next_stack_2"));
	button_pasien_riwayat_medis = GTK_BUTTON(gtk_builder_get_object(builder, "button_pasien_riwayat_medis"));
	button_riwayat_medis = GTK_BUTTON(gtk_builder_get_object(builder, "button_riwayat_medis"));
	button_pasien_kontrol = GTK_BUTTON(gtk_builder_get_object(builder, "button_pasien_kontrol"));
	button_pasien_penyakit = GTK_BUTTON(gtk_builder_get_object(builder, "button_pasien_penyakit"));
	button_pendapatan = GTK_BUTTON(gtk_builder_get_object(builder, "button_pendapatan"));
	pasien_kontrol_submit = GTK_BUTTON(gtk_builder_get_object(builder, "pasien_kontrol_submit"));
	pendapatan_submit = GTK_BUTTON(gtk_builder_get_object(builder, "pendapatan_submit"));
	ID_Pasien_diagnosis_element_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "ID_Pasien_diagnosis_element_radio"));
	Tanggal_Kunjungan_diagnosis_element_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "Tanggal_Kunjungan_diagnosis_element_radio"));
	diagnosis_search_submit = GTK_BUTTON(gtk_builder_get_object(builder, "diagnosis_search_submit"));
	ID_Pasien_pasien_element_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "ID_Pasien_pasien_element_radio"));
	Nama_Lengkap_pasien_element_radio = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "Nama_Lengkap_pasien_element_radio"));
	pasien_search_submit = GTK_BUTTON(gtk_builder_get_object(builder, "pasien_search_submit"));
	pasien_penyakit_mode1 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "pasien_penyakit_mode1"));
	pasien_penyakit_mode2 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "pasien_penyakit_mode2"));
	pasien_penyakit_mode3 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "pasien_penyakit_mode3"));
	pasien_penyakit_submit = GTK_BUTTON(gtk_builder_get_object(builder, "pasien_penyakit_submit"));
	pasien_riwayat_medis_submit = GTK_BUTTON(gtk_builder_get_object(builder, "pasien_riwayat_medis_submit"));
	file_chooser_px = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, "file_chooser_px"));
 	file_chooser_dx = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, "file_chooser_dx"));
 	file_chooser_biaya = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, "file_chooser_biaya"));
	button_save = GTK_BUTTON(gtk_builder_get_object(builder, "button_save"));
	button_clear_list = GTK_BUTTON(gtk_builder_get_object(builder, "button_clear_list"));
	next_penyakit = GTK_BUTTON(gtk_builder_get_object(builder, "next_penyakit"));
	g_signal_connect(add_diagnosis_submit, "clicked", G_CALLBACK(on_add_diagnosis_submit_clicked), NULL);
	g_signal_connect(add_pasien_submit, "clicked", G_CALLBACK(on_add_pasien_submit_clicked), NULL);
	g_signal_connect(tanggal_kunjungan_sel_radio, "toggled", G_CALLBACK(on_tanggal_kunjungan_sel_radio_toggled), NULL);
	g_signal_connect(id_pasien_sel_diagnosis_radio, "toggled", G_CALLBACK(on_id_pasien_sel_diagnosis_radio_toggled), NULL);
	g_signal_connect(diagnosis_sel_radio, "toggled", G_CALLBACK(on_diagnosis_sel_radio_toggled), NULL);
	g_signal_connect(tindakan_sel_radio, "toggled", G_CALLBACK(on_tindakan_sel_radio_toggled), NULL);
	g_signal_connect(value_diagnosis_submit, "clicked", G_CALLBACK(on_value_diagnosis_submit_clicked), NULL);
	g_signal_connect(nama_lengkap_sel_radio, "toggled", G_CALLBACK(on_nama_lengkap_sel_radio_toggled), NULL);
	g_signal_connect(alamat_sel_radio, "toggled", G_CALLBACK(on_alamat_sel_radio_toggled), NULL);
	g_signal_connect(kota_sel_radio, "toggled", G_CALLBACK(on_kota_sel_radio_toggled), NULL);
	g_signal_connect(tempat_lahir_sel_radio, "toggled", G_CALLBACK(on_tempat_lahir_sel_radio_toggled), NULL);
	g_signal_connect(tanggal_lahir_sel_radio, "toggled", G_CALLBACK(on_tanggal_lahir_sel_radio_toggled), NULL);
	g_signal_connect(umur_sel_radio, "toggled", G_CALLBACK(on_umur_sel_radio_toggled), NULL);
	g_signal_connect(bpjs_sel_radio, "toggled", G_CALLBACK(on_bpjs_sel_radio_toggled), NULL);
	g_signal_connect(value_pasien_submit, "clicked", G_CALLBACK(on_value_pasien_submit_clicked), NULL);
	g_signal_connect(num_diagnosis_submit, "clicked", G_CALLBACK(on_num_diagnosis_submit_clicked), NULL);
	g_signal_connect(num_pasien_submit, "clicked", G_CALLBACK(on_num_pasien_submit_clicked), NULL);
	g_signal_connect(delete_stack_1, "clicked", G_CALLBACK(on_delete_stack_1_clicked), NULL);
	g_signal_connect(update_stack_1, "clicked", G_CALLBACK(on_update_stack_1_clicked), NULL);
	g_signal_connect(search_stack_1, "clicked", G_CALLBACK(on_search_stack_1_clicked), NULL);
	g_signal_connect(create_stack_1, "clicked", G_CALLBACK(on_create_stack_1_clicked), NULL);
	g_signal_connect(prev_stack_1, "clicked", G_CALLBACK(on_prev_stack_1_clicked), NULL);
	g_signal_connect(next_stack_1, "clicked", G_CALLBACK(on_next_stack_1_clicked), NULL);
	g_signal_connect(delete_stack_2, "clicked", G_CALLBACK(on_delete_stack_2_clicked), NULL);
	g_signal_connect(update_stack_2, "clicked", G_CALLBACK(on_update_stack_2_clicked), NULL);
	g_signal_connect(search_stack_2, "clicked", G_CALLBACK(on_search_stack_2_clicked), NULL);
	g_signal_connect(create_stack_2, "clicked", G_CALLBACK(on_create_stack_2_clicked), NULL);
	g_signal_connect(prev_stack_2, "clicked", G_CALLBACK(on_prev_stack_2_clicked), NULL);
	g_signal_connect(next_stack_2, "clicked", G_CALLBACK(on_next_stack_2_clicked), NULL);
	g_signal_connect(button_pasien_riwayat_medis, "clicked", G_CALLBACK(on_button_pasien_riwayat_medis_clicked), NULL);
	g_signal_connect(button_riwayat_medis, "clicked", G_CALLBACK(on_button_riwayat_medis_clicked), NULL);
	g_signal_connect(button_pasien_kontrol, "clicked", G_CALLBACK(on_button_pasien_kontrol_clicked), NULL);
	g_signal_connect(button_pasien_penyakit, "clicked", G_CALLBACK(on_button_pasien_penyakit_clicked), NULL);
	g_signal_connect(button_pendapatan, "clicked", G_CALLBACK(on_button_pendapatan_clicked), NULL);
	g_signal_connect(pasien_kontrol_submit, "clicked", G_CALLBACK(on_pasien_kontrol_submit_clicked), NULL);
	g_signal_connect(pendapatan_submit, "clicked", G_CALLBACK(on_pendapatan_submit_clicked), NULL);
	g_signal_connect(ID_Pasien_diagnosis_element_radio, "toggled", G_CALLBACK(on_ID_Pasien_diagnosis_element_radio_toggled), NULL);
	g_signal_connect(Tanggal_Kunjungan_diagnosis_element_radio, "toggled", G_CALLBACK(on_Tanggal_Kunjungan_diagnosis_element_radio_toggled), NULL);
	g_signal_connect(diagnosis_search_submit, "clicked", G_CALLBACK(on_diagnosis_search_submit_clicked), NULL);
	g_signal_connect(ID_Pasien_pasien_element_radio, "toggled", G_CALLBACK(on_ID_Pasien_pasien_element_radio_toggled), NULL);
	g_signal_connect(Nama_Lengkap_pasien_element_radio, "toggled", G_CALLBACK(on_Nama_Lengkap_pasien_element_radio_toggled), NULL);
	g_signal_connect(pasien_search_submit, "clicked", G_CALLBACK(on_pasien_search_submit_clicked), NULL);
	g_signal_connect(pasien_penyakit_mode1, "toggled", G_CALLBACK(on_pasien_penyakit_mode1_toggled), NULL);
	g_signal_connect(pasien_penyakit_mode2, "toggled", G_CALLBACK(on_pasien_penyakit_mode2_toggled), NULL);
	g_signal_connect(pasien_penyakit_mode3, "toggled", G_CALLBACK(on_pasien_penyakit_mode3_toggled), NULL);
	g_signal_connect(pasien_penyakit_submit, "clicked", G_CALLBACK(on_pasien_penyakit_submit_clicked), NULL);
	g_signal_connect(pasien_riwayat_medis_submit, "clicked", G_CALLBACK(on_pasien_riwayat_medis_submit_clicked), NULL);
	g_signal_connect(file_chooser_px, "file-set", G_CALLBACK(on_file_chooser_px_file_set), NULL);
	g_signal_connect(file_chooser_dx, "file-set", G_CALLBACK(on_file_chooser_dx_file_set), NULL);
	g_signal_connect(file_chooser_biaya, "file-set", G_CALLBACK(on_file_chooser_biaya_file_set), NULL);
	g_signal_connect(button_save, "clicked", G_CALLBACK(on_button_save_clicked), NULL);
	g_signal_connect(button_clear_list, "clicked", G_CALLBACK(on_button_clear_list_clicked), NULL);
	g_signal_connect(next_penyakit, "clicked", G_CALLBACK(on_next_penyakit_clicked), NULL);

	// Entries
	nama_lengkap_entry = GTK_ENTRY(gtk_builder_get_object(builder, "nama_lengkap_entry"));
	alamat_entry = GTK_ENTRY(gtk_builder_get_object(builder, "alamat_entry"));
	kota_entry = GTK_ENTRY(gtk_builder_get_object(builder, "kota_entry"));
	tempat_lahir_entry = GTK_ENTRY(gtk_builder_get_object(builder, "tempat_lahir_entry"));
	tanggal_lahir_entry = GTK_ENTRY(gtk_builder_get_object(builder, "tanggal_lahir_entry"));
	umur_entry = GTK_ENTRY(gtk_builder_get_object(builder, "umur_entry"));
	bpjs_entry = GTK_ENTRY(gtk_builder_get_object(builder, "bpjs_entry"));
	tanggal_kunjungan_entry = GTK_ENTRY(gtk_builder_get_object(builder, "tanggal_kunjungan_entry"));
	ID_Pasien_entry = GTK_ENTRY(gtk_builder_get_object(builder, "ID_Pasien_entry"));
	diagnosis_entry = GTK_ENTRY(gtk_builder_get_object(builder, "diagnosis_entry"));
	tindakan_entry = GTK_ENTRY(gtk_builder_get_object(builder, "tindakan_entry"));
	value_diagnosis_entry = GTK_ENTRY(gtk_builder_get_object(builder, "value_diagnosis_entry"));
	value_pasien_entry = GTK_ENTRY(gtk_builder_get_object(builder, "value_pasien_entry"));
	num_diagnosis_entry = GTK_ENTRY(gtk_builder_get_object(builder, "num_diagnosis_entry"));
	num_pasien_entry = GTK_ENTRY(gtk_builder_get_object(builder, "num_pasien_entry"));
	pasien_kontrol_entry = GTK_ENTRY(gtk_builder_get_object(builder, "pasien_kontrol_entry"));
	bulan_pendapatan_entry = GTK_ENTRY(gtk_builder_get_object(builder, "bulan_pendapatan_entry"));
	tahun_pendapatan_entry = GTK_ENTRY(gtk_builder_get_object(builder, "tahun_pendapatan_entry"));
	value_search_diagnosis_entry = GTK_ENTRY(gtk_builder_get_object(builder, "value_search_diagnosis_entry"));
	value_search_pasien_entry = GTK_ENTRY(gtk_builder_get_object(builder, "value_search_pasien_entry"));
	pasien_penyakit_mode_bulan_tahun_entry = GTK_ENTRY(gtk_builder_get_object(builder, "pasien_penyakit_mode_bulan_tahun_entry"));
	pasien_penyakit_mode3_entry = GTK_ENTRY(gtk_builder_get_object(builder, "pasien_penyakit_mode3_entry"));
	pasien_riwayat_medis_entry = GTK_ENTRY(gtk_builder_get_object(builder, "pasien_riwayat_medis_entry"));
	g_signal_connect(GTK_ENTRY(nama_lengkap_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(alamat_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(kota_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(tempat_lahir_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(tanggal_lahir_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(umur_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(bpjs_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(tanggal_kunjungan_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(ID_Pasien_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(diagnosis_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(tindakan_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(value_diagnosis_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(value_pasien_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(num_diagnosis_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(num_pasien_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(pasien_kontrol_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(bulan_pendapatan_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(tahun_pendapatan_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(value_search_diagnosis_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(value_search_pasien_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(pasien_penyakit_mode_bulan_tahun_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(pasien_penyakit_mode3_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	g_signal_connect(GTK_ENTRY(pasien_riwayat_medis_entry), "changed", G_CALLBACK(on_entry_changed), NULL);
	
	// Labels
	choose_diagnosis_label = GTK_LABEL(gtk_builder_get_object(builder, "choose_diagnosis_label"));
	choose_pasien_label = GTK_LABEL(gtk_builder_get_object(builder, "choose_pasien_label"));
	enter_value_search_diagnosis_label = GTK_LABEL(gtk_builder_get_object(builder, "enter_value_search_diagnosis_label"));
	enter_value_search_pasien_label = GTK_LABEL(gtk_builder_get_object(builder, "enter_value_search_pasien_label"));
	pasien_penyakit_mode_bulan_tahun_label = GTK_LABEL(gtk_builder_get_object(builder, "pasien_penyakit_mode_bulan_tahun_label"));
	pasien_penyakit_mode3_label = GTK_LABEL(gtk_builder_get_object(builder, "pasien_penyakit_mode3_label"));

	// Images and import images
	delete_icon_1 = GTK_IMAGE(gtk_builder_get_object(builder, "delete_icon_1"));
	edit_icon_1 = GTK_IMAGE(gtk_builder_get_object(builder, "edit_icon_1"));
	search_icon_1 = GTK_IMAGE(gtk_builder_get_object(builder, "search_icon_1"));
	create_icon_1 = GTK_IMAGE(gtk_builder_get_object(builder, "create_icon_1"));
	delete_icon_2 = GTK_IMAGE(gtk_builder_get_object(builder, "delete_icon_2"));
	edit_icon_2 = GTK_IMAGE(gtk_builder_get_object(builder, "edit_icon_2"));
	search_icon_2 = GTK_IMAGE(gtk_builder_get_object(builder, "search_icon_2"));
	create_icon_2 = GTK_IMAGE(gtk_builder_get_object(builder, "create_icon_2"));
	data_pasien_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_pasien_icon"));
	data_diagnosis_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_diagnosis_icon"));
	data_pasien_riwayat_medis_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_pasien_riwayat_medis_icon"));
	data_pasien_kontrol_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_pasien_kontrol_icon"));
	data_pasien_penyakit_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_pasien_penyakit_icon"));
	data_pendapatan_icon = GTK_IMAGE(gtk_builder_get_object(builder, "data_pendapatan_icon"));
	pasien_riwayat_medis_icon = GTK_IMAGE(gtk_builder_get_object(builder, "pasien_riwayat_medis_icon"));
	pasien_kontrol_icon = GTK_IMAGE(gtk_builder_get_object(builder, "pasien_kontrol_icon"));
	pasien_penyakit_icon = GTK_IMAGE(gtk_builder_get_object(builder, "pasien_penyakit_icon"));
	pendapatan_icon = GTK_IMAGE(gtk_builder_get_object(builder, "pendapatan_icon"));

	// List Stores
	// Build lists
	diagnosis_list = GTK_LIST_STORE(gtk_builder_get_object(builder, "diagnosis_list"));
	pasien_list = GTK_LIST_STORE(gtk_builder_get_object(builder, "pasien_list"));
	filter_px_list = GTK_LIST_STORE(gtk_builder_get_object(builder, "filter_px_list"));
	filter_dx_list = GTK_LIST_STORE(gtk_builder_get_object(builder, "filter_dx_list"));
	list_penyakit_tahun = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_penyakit_tahun"));
	list_penyakit_bulan = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_penyakit_bulan"));
	list_penyakit_spes = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_penyakit_spes"));

	// Treeview and textview
	filtered_pasien_riwayat = GTK_TREE_VIEW(gtk_builder_get_object(builder, "filtered_pasien_riwayat"));
	table_search_diagnosis = GTK_TREE_VIEW(gtk_builder_get_object(builder, "table_search_diagnosis"));
	table_search_pasien = GTK_TREE_VIEW(gtk_builder_get_object(builder, "table_search_pasien"));
	pasien_table = GTK_TREE_VIEW(gtk_builder_get_object(builder, "pasien_table"));
	diagnosis_table = GTK_TREE_VIEW(gtk_builder_get_object(builder, "diagnosis_table"));
	filtered_pasien_data = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "filtered_pasien_data"));
	filtered_diagnosis_list = GTK_TREE_VIEW(gtk_builder_get_object(builder, "filtered_diagnosis_list"));
	textview_pasien_penyakit = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "textview_pasien_penyakit"));
	textview_pendapatan = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "textview_pendapatan"));
	treeview_pasien_penyakit = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview_pasien_penyakit"));

	// Set treeviews to corresponding model
	gtk_tree_view_set_model(GTK_TREE_VIEW(table_search_pasien), GTK_TREE_MODEL(filter_px_list));
	gtk_tree_view_set_model(GTK_TREE_VIEW(pasien_table), GTK_TREE_MODEL(pasien_list));
	gtk_tree_view_set_model(GTK_TREE_VIEW(table_search_diagnosis), GTK_TREE_MODEL(filter_dx_list));
	gtk_tree_view_set_model(GTK_TREE_VIEW(diagnosis_table), GTK_TREE_MODEL(diagnosis_list));
	gtk_tree_view_set_model(GTK_TREE_VIEW(filtered_diagnosis_list), GTK_TREE_MODEL(filter_dx_list));
	gtk_tree_view_set_model(GTK_TREE_VIEW(filtered_pasien_riwayat), GTK_TREE_MODEL(filter_dx_list));
	create_cols_px(GTK_TREE_VIEW(pasien_table));
	create_cols_px(GTK_TREE_VIEW(table_search_pasien));
	create_cols_dx(GTK_TREE_VIEW(table_search_diagnosis));
	create_cols_dx(GTK_TREE_VIEW(diagnosis_table));
	create_cols_dx(GTK_TREE_VIEW(filtered_diagnosis_list));
	create_cols_dx(GTK_TREE_VIEW(filtered_pasien_riwayat));
	
	// Show main window
	gtk_widget_show_all(GTK_WIDGET(main_window));
	gtk_widget_hide(GTK_WIDGET(next_penyakit));

	// Main loop
	gtk_main();

	free(edit_search_delete_pasien_check);
	free(edit_search_delete_diagnosis_check);
    free(passing_string);
    free(penyakit_form_check);

    return 0;
}