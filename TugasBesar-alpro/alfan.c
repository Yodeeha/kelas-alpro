#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Admin {
    char userr[50];
    char pass[50];
};

struct User {
    char user[50];
    char pas[50];
    char nama[50];
    char email[50];
    char no_telepon[50];
    char alamat[100];
};

struct layananjasa {
    char username[50];
    char nama[100];
    int harga;
};

struct Pemesanan {
    char username[50];
    char nama[50];
    char alamat[100];
    int telp;
    int harga;
    char status_pemesanan[50];
};

struct KategoriKendaraan {
    char jenis_kendaraan[50];
    char kendaraan[50];
    char jenis_service[50];
    int harga;
};

void user();
void registrasi_user();
void login();
void layanan();
void helpdesk();
void lihat_jasa_service();
void pemesanan();
void bayar_layanan();
void lihat_progress_cucian();
void admin();
void login_admin();
void daftarmenuadmin();
void lihat_data_user();
void tambah_kategori_kendaraan();
void tambah_harga_jenis_layanan();
void lihat_dan_ubah_progress_cucian();
void logout();

int bharga(const void *a, const void *b) {
    return ((struct layananjasa *)a)->harga - ((struct layananjasa *)b)->harga;
}

struct Admin buatadmin(const char userr[], const char pass[]) {
    struct Admin admin;
    strncpy(admin.userr, userr, sizeof(admin.userr) - 1);
    strncpy(admin.pass, pass, sizeof(admin.pass) - 1);
    return admin;
}

int check_login(const struct Admin *admin, const char *username, const char *password) {
    return strcmp(admin->userr, username) == 0 && strcmp(admin->pass, password) == 0;
}

int main() {
    int menu_main;
    printf("+_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+\n");
    printf("|     SELAMAT DATANG DI DASKOM WASH         |\n");
    printf("+_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+\n\n");
    printf("\n+============================================+\n");
    printf("|                MENU UTAMA                 |\n");
    printf("|===========================================|\n");
    printf("| 1. User                                   |\n");
    printf("| 2. Admin                                  |\n");
    printf("| 3. Exit                                   |\n");
    printf("+_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+\n\n");
    printf("\n Pilih Menu\t: ");
    scanf("%d", &menu_main);

    switch (menu_main) {
        case 1:
            user();
            break;
        case 2:
            login_admin();
            break;
        case 3:
            exit(0);
        default:
            printf("\nMenu yang anda pilih tidak tersedia\n");
            break;
    }

    return 0;
}

void user() {
    int n;
    system("cls");
    fflush(stdin);
    printf("\n+============================================+\n");
    printf("|                 MENU User                  |\n");
    printf("|===========================================|\n");
    printf("| 1. Registrasi                             |\n");
    printf("| 2. Login                                  |\n");
    printf("| 3. Menu Utama                             |\n");
    printf("| 4. Exit                                   |\n");
    printf("+===========================================+\n\n");
    printf("\n Pilih Menu\t: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            registrasi_user();
            break;
        case 2:
            login();
            break;
        case 3:
            main();
            break;
        case 4:
            exit(0);
        default:
            printf("\nMenu yang anda pilih tidak tersedia");
            getchar();
            system("pause");
            system("cls");
            user();
            break;
    }
}

void registrasi_user() {
    system("cls");
    fflush(stdin);
    printf("              REGISTRASI\n\n");

    struct User cs; 

    FILE *reg = fopen("reg user.dat", "ab");
    if (!reg) {
        printf("file gagal dibuka\n");
        return;
    }

    printf(" 1. Nama              : ");
    gets(cs.nama);
    printf("\n 2. Email           : ");
    gets(cs.email);
    printf("\n 3. NO Telepon      : ");
    gets(cs.no_telepon);
    printf("\n 4. Alamat          : ");
    gets(cs.alamat);
    printf("\n 5. Username        : ");
    gets(cs.user);
    printf("\n 6. Password        : ");
    gets(cs.pas);

    fwrite(&cs, sizeof(cs), 1, reg);
    fclose(reg);

    system("pause");
    user();
}

void login() {
    system("cls");
    fflush(stdin);
    struct User cs; 

    FILE *reg = fopen("reg user.dat", "rb");
    if (!reg) {
        printf("file gagal dibuka\n");
        return;
    }

    printf("              LOGIN\n\n");
    printf("\nUsername : ");
    gets(cs.user);
    printf("Password : ");
    gets(cs.pas);

    while (fread(&cs, sizeof(cs), 1, reg) == 1) {
        if (strcmp(cs.user, cs.user) == 0 && strcmp(cs.pas, cs.pas) == 0) {
            printf("\n\tLogin Berhasil\n\n");
            system("pause");
            system("cls");
            layanan();
        }
    }

    printf("\n\tLogin Gagal");
    fclose(reg);
    system("pause");
    user();
}


void layanan() {
    int a;
    printf("\n+========================================+\n");
    printf("|            Menu Layanan                 |\n");
    printf("| 1. Helpdesk(Petunjuk aplikasi)          |\n");
    printf("| 2. Lihat Jasa Service                   |\n");
    printf("| 3. Pemesanan                            |\n");
    printf("| 4. Bayar Layanan                        |\n");
    printf("| 5. Lihat progres cucian                 |\n");
    printf("| 6. Menu utama                           |\n");
    printf("| 7. Exit                                 |\n");
    printf("+========================================+\n\n");
    printf("\n Pilih menu\t: ");
    scanf("%d", &a);

    switch (a) {
        case 1:
            helpdesk();
            break;
        case 2:
            lihat_jasa_service();
            break;
        case 3:
            pemesanan();
            break;
        case 4:
            bayar_layanan();
            break;
        case 5:
            lihat_progress_cucian();
            break;
        case 6:
            main();
            break;
        case 7:
            exit(0);
        default:
            printf("\nMenu yang anda pilih tidak tersedia");
            getchar();
            system("pause");
            system("cls");
            layanan();
            break;
    }
}

void helpdesk(){
    printf("===== Panduan Aplikasi =====\n\n");
    printf(" 1. Masukkan data registrasi untuk login \n\n");
    printf(" 2. Masukkan keyword untuk akses lupa password \n\n");
    printf(" 3. Lihat data jasa layanan berdasarkan harga termurah \n\n");
    printf(" 4. Masukkan pesanan pada menu pemesanan \n\n");
    printf(" 5. Lihat progres cucian pada menu lihat progres cucian \n\n");
    printf(" 6. Bayar layanan ketika layanan selesai \n\n");
}

void lihat_jasa_service() {
    struct layananjasa *jsArray;
    int count = 0;
	int i = 0;
	
    FILE *f = fopen("jasa_service.dat", "rb");
    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    count = ftell(f) / sizeof(struct layananjasa);
    rewind(f);

    jsArray = (struct layananjasa *)malloc(count * sizeof(struct layananjasa));
    if (!jsArray) {
        printf("alokasi memory error\n");
        fclose(f);
        return;
    }

    
    fread(jsArray, sizeof(struct layananjasa), count, f);

    fclose(f);

    qsort(jsArray, count, sizeof(struct layananjasa), bharga);

    printf("\nJasa Service  :\n");
	while (i < count) {
    printf("Username		: %s", jsArray[i].username);
    printf("Nama			: %s", jsArray[i].nama);
    printf("Harga			: %d\n", jsArray[i].harga);
    i++;
}

    free(jsArray);
}

void pemesanan() {
    struct Pemesanan p;
    
    lihat_jasa_service();

    printf("\nMasukkan Username anda\t: ");
    scanf("%s", p.username); 

    printf("\nMasukkan Nama\t: ");
    getchar();
    fgets(p.nama, sizeof(p.nama), stdin);

    printf("\nMasukkan Alamat\t: ");
    getchar();
    fgets(p.alamat, sizeof(p.alamat), stdin);

    printf("\nMasukkan No Telp\t: ");
    scanf("%d", &p.telp);

    FILE *f = fopen("pemesanan.dat", "ab");
    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);

    printf("\nPemesanan berhasil!\n");
}

void bayar_layanan() {
    struct Pemesanan p;

    printf("\nMasukkan Username Pemesan\t: ");
    scanf("%s", p.username); 

    FILE *f = fopen("pemesanan.dat", "rb");
    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        struct layananjasa js;
        FILE *f2 = fopen("jasa_service.dat", "rb");
        if (!f2) {
            printf("file gagal dibuka\n");
            fclose(f);
            return;
        }

        while (fread(&js, sizeof(js), 1, f2) == 1) {
            if (strcmp(js.username, p.username) == 0) {  
                FILE *f3 = fopen("pembayaran.dat", "ab");
                if (!f3) {
                    printf("file gagal dibuka\n");
                    fclose(f2);
                    fclose(f);
                    return;
                }

                fwrite(&p, sizeof(p), 1, f3);
                fwrite(&js, sizeof(js), 1, f3);

                fclose(f3);
  
                FILE *temp = fopen("temp.dat", "wb");
                rewind(f);

                while (fread(&p, sizeof(p), 1, f) == 1) {
                    if (strcmp(p.username, p.username) != 0) {
                        fwrite(&p, sizeof(p), 1, temp);
                    }
                }

                fclose(f);
                fclose(temp);

                remove("pemesanan.dat");
                rename("temp.dat", "pemesanan.dat");

                printf("\nPembayaran layanan berhasil!\n");
                fclose(f2);
                return;
            }
        }

        fclose(f2);
    }

    fclose(f);
    printf("\nPemesanan dengan Username %s tidak ditemukan\n", p.username);
}


void lihat_progress_cucian() {
    struct Pemesanan p;
    struct layananjasa js;
    char username[50]; 

    printf("\nMasukkan Username Pemesanan\t: ");
    scanf("%s", username);

    FILE *f = fopen("pemesanan.dat", "rb");
    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        if (strcmp(p.username, username) == 0) {  
            FILE *f2 = fopen("jasa_service.dat", "rb");
            if (!f2) {
                printf("file gagal dibuka\n");
                fclose(f);
                return;
            }

            while (fread(&js, sizeof(js), 1, f2) == 1) {
                if (js.username == p.username) {
                    printf("\nProgres Cucian untuk Pemesanan dengan Username %s\n", username);  
                    printf("Nama			: %s", p.nama);
                    printf("Alamat			: %s", p.alamat);
                    printf("No Telp			: %d\n", p.telp);
                    printf("Harga			: %d\n", p.harga);
                    printf("Progres Cucian	: %s\n", p.status_pemesanan);
                    fclose(f2);
                    fclose(f);
                    return;
                }
            }

            fclose(f2);
        }
    }

    fclose(f);
    printf("\nPemesanan dengan Username %s tidak ditemukan\n", username);  
}


void login_admin() {
    struct Admin admin = buatadmin("admin", "password");

    int upaya = 3;  

    while (upaya > 0) {
        char username[50];
        char password[50];

        printf("\nMASUKKAN USERNAME ANDA: ");
        scanf("%s", username);
        printf("MASUKKAN PASSWORD ANDA: ");
        scanf("%s", password);

        if (check_login(&admin, username, password)) {
            printf("\nLogin berhasil.\n");
            daftarmenuadmin();
            return;
        } else {
            printf("\nUSERNAME DAN PASSWORD SALAH. Sisa percobaan: %d\n", upaya - 1);
            upaya--;
        }
    }

    printf("\nAnda telah melebihi batas percobaan login. Aplikasi akan keluar.\n");
    exit(0);
}

void daftarmenuadmin() {
    int pilihan;
    do {
    	printf("\n");
        printf("_________________________________________\n");
        printf("|           ADMIN MENU                   |\n");
        printf("|1. Lihat Data user                      |\n");
        printf("|2. Tambah kategori kendaraan            |\n");
        printf("|3. Tambah harga dan jenis layanan       |\n");
        printf("|4. Lihat dan ubah progres               |\n");
        printf("|5. Kembali ke menu Utama                |\n");
        printf("|6. Logout                               |\n");
        printf("|________________________________________|\n");
        printf("\n Pilih menu\t: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihat_data_user();
                break;
            case 2:
                tambah_kategori_kendaraan();
                break;
            case 3:
                tambah_harga_jenis_layanan();
                break;
            case 4:
                lihat_dan_ubah_progress_cucian();
                break;
            case 5:
                main(); 
                break;
            case 6:
                logout();
                break;
            default:
                printf("\nMenu yang anda pilih tidak tersedia");
                break;
        }
    } while (pilihan != 5);  
}



void lihat_data_user() {
    struct User userr;
    FILE *f = fopen("reg user.dat", "rb");

    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    while (fread(&userr, sizeof(userr), 1, f) == 1) {
        printf("\n 1. Nama\t\t: %s", userr.nama);
        printf("\n 2. Alamat\t\t: %s", userr.alamat);
        printf("\n 3. No HP\t\t: %s", userr.no_telepon);
        printf("\n 4. Username\t: %s", userr.user);
        printf("\n 5. Password\t: %s", userr.pas);
    }

    fclose(f);
}


void tambah_kategori_kendaraan() {
    struct KategoriKendaraan kk;
    FILE *f = fopen("kategori_kendaraan.dat", "ab");

    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    printf("Masukkan Jenis Kendaraan: ");
    getchar(); 
    fgets(kk.jenis_kendaraan, sizeof(kk.jenis_kendaraan), stdin);

  	printf("Masukkan Jenis Layanan cuci: ");
    getchar(); 
    fgets(kk.jenis_service, sizeof(kk.jenis_service), stdin);
    
    printf("Masukkan nama kendaraan: ");
    getchar(); 
    fgets(kk.kendaraan, sizeof(kk.kendaraan), stdin);
    
    printf("Masukkan Harga: ");
    scanf("%d", &kk.harga);


    fwrite(&kk, sizeof(kk), 1, f);
    fclose(f);

    printf("Kategori Kendaraan berhasil ditambahkan.\n");
}


void tambah_harga_jenis_layanan() {
    struct layananjasa js;
    FILE *f = fopen("jasa_service.dat", "ab");

    if (!f) {
        printf("file gagal dibuka\n");
        return;
    }

    printf("Masukkan Nama Jenis Service: ");
    getchar(); // Consume newline character
    fgets(js.nama, sizeof(js.nama), stdin);

    printf("Masukkan Harga Jenis Service: ");
    scanf("%d", &js.harga);

    fwrite(&js, sizeof(js), 1, f);
    fclose(f);

    printf("Jenis Service dan Harga berhasil ditambahkan.\n");
}


void lihat_dan_ubah_progress_cucian() {
    char username[50];

    printf("\nMasukkan Username Pemesanan: ");
    scanf("%s", username);

    FILE *file = fopen("pemesanan.dat", "r+b");
    if (!file) {
        printf("file gagal dibuka\n");
        return;
    }

    struct Pemesanan p;

    while (fread(&p, sizeof(p), 1, file) == 1) {
        if (strcmp(p.username, username) == 0) { 
            
            printf("\nUsername Pemesanan: %s\n", p.username);
            printf("Nama: %s\n", p.nama);
            printf("Alamat: %s\n", p.alamat);
            printf("No Telp: %d\n", p.telp);
            printf("Harga: %d\n", p.harga);
            printf("Progres Cucian: %s\n", p.status_pemesanan);

            
            printf("\nUbah Progres Cucian (max 49 karakter): ");
            scanf(" %49[^\n]", p.status_pemesanan);

            
            fseek(file, -sizeof(p), SEEK_CUR);

            
            fwrite(&p, sizeof(p), 1, file);

            printf("\nProgres Cucian berhasil diubah!\n");

            
            fclose(file);
            return;
        }
    }

    
    printf("\nPemesanan dengan username %s tidak ditemukan\n", username);

    
    fclose(file);
}

void logout() {
	int upaya;
    char pilihan;
    
    if (upaya > 0) {
        printf("\nAnda telah melebihi batas percobaan login. Apakah Anda ingin keluar? (y/n): ");
        scanf(" %c", &pilihan);

        if (pilihan == 'y' || pilihan == 'Y') {
            printf("Logout berhasil.\n");
        } else if (pilihan == 'n' || pilihan == 'N') {
            logout(upaya);
        } else {
            printf("Pilihan tidak valid. Coba lagi.\n");
            logout(upaya);
        }
    } else {
        printf("\nAnda telah melebihi batas percobaan login. Aplikasi akan keluar.\n");
    }
}