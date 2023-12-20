#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure Declarations
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

struct Pengaduan {
    int id;
    char nama[30];
    char email[30];
    char subjek[30];
    char pesan[100];
};

struct JasaService {
    int id;
    char nama[100];
    int harga;
};

struct Pemesanan {
    int id;
    char nama[50];
    char alamat[100];
    int telp;
    char tanggal_masuk[20];
    char tanggal_keluar[20];
    int id_jasa_service;
    int harga;
    char status_pemesanan[50];
};

struct KategoriKendaraan {
    char jenis_kendaraan[50];
    int harga;
    char jenis_service[50];
};

// Function Prototypes
void user();
void registrasi_user();
void login();
void layanan();
void tambahPengaduan();
void lihatPengaduan();
void lihat_jasa_service();
void pemesanan();
void bayar_layanan();
void lihat_progress_cucian();
void admin();
void login_admin();
void displayAdminMenu();
void lihat_data_user();
void tambah_kategori_kendaraan();
void tambah_harga_dan_jenis_service();
void lihat_dan_ubah_progress_cucian();
void logoutA();

// Function to create an admin
struct Admin create_admin(const char userr[], const char pass[]) {
    struct Admin admin;
    strncpy(admin.userr, userr, sizeof(admin.userr) - 1);
    strncpy(admin.pass, pass, sizeof(admin.pass) - 1);
    return admin;
}


int main() {
    int menu_main;
    printf("+_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+\n");
    printf("|     SELAMAT DATANG DI DASKOM WASH        |\n");
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

    struct User cs;  // Use correct structure name

    FILE *reg = fopen("reg user.dat", "ab");
    if (!reg) {
        printf("Error opening file\n");
        return;
    }

    printf("Nama            : ");
    gets(cs.nama);
    printf("\nEmail           : ");
    gets(cs.email);
    printf("\nNO Telepon      : ");
    gets(cs.no_telepon);
    printf("\nAlamat          : ");
    gets(cs.alamat);
    printf("\nUsername        : ");
    gets(cs.user);
    printf("\nPassword        : ");
    gets(cs.pas);

    fwrite(&cs, sizeof(cs), 1, reg);
    fclose(reg);

    system("pause");
    user();
}

void login() {
    system("cls");
    fflush(stdin);
    struct User cs;  // Use correct structure name

    FILE *reg = fopen("reg user.dat", "rb");
    if (!reg) {
        printf("Error opening file\n");
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
    printf("|            Menu Layanan                |\n");
    printf("| 1. Helpdesk(Pengaduan)                 |\n");
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
            tambahPengaduan();
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

void tambahPengaduan() {
    struct Pengaduan p;
    FILE *f;

    f = fopen("pengaduan.dat", "ab");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    printf("Masukkan ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Masukkan Nama: ");
    fgets(p.nama, sizeof(p.nama), stdin);
    printf("Masukkan Email: ");
    fgets(p.email, sizeof(p.email), stdin);
    printf("Masukkan Subjek: ");
    fgets(p.subjek, sizeof(p.subjek), stdin);
    printf("Masukkan Pesan: ");
    fgets(p.pesan, sizeof(p.pesan), stdin);

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);
}

void lihatPengaduan() {
    struct Pengaduan p;
    FILE *f;

    f = fopen("pengaduan.dat", "rb");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        printf("\nID: %d\n", p.id);
        printf("Nama: %s", p.nama);
        printf("Email: %s", p.email);
        printf("Subjek: %s", p.subjek);
        printf("Pesan: %s", p.pesan);
    }

    fclose(f);
}

void lihat_jasa_service() {
    struct JasaService js;
    FILE *f;

    f = fopen("jasa_service.dat", "rb");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&js, sizeof(js), 1, f) == 1) {
        printf("\nID: %d\n", js.id);
        printf("Nama: %s", js.nama);
        printf("Harga: %d\n", js.harga);
    }

    fclose(f);
}

void pemesanan() {
    struct Pemesanan p;
    int id_jasa_service;

    lihat_jasa_service();

    printf("\nMasukkan ID Jasa Service\t: ");
    scanf("%d", &id_jasa_service);

    p.id_jasa_service = id_jasa_service;

    printf("\nMasukkan Nama\t: ");
    getchar();
    fgets(p.nama, sizeof(p.nama), stdin);

    printf("\nMasukkan Alamat\t: ");
    getchar();
    fgets(p.alamat, sizeof(p.alamat), stdin);

    printf("\nMasukkan No Telp\t: ");
    scanf("%d", &p.telp);

    printf("\nMasukkan Tanggal Masuk\t: ");
    getchar();
    fgets(p.tanggal_masuk, sizeof(p.tanggal_masuk), stdin);

    printf("\nMasukkan Tanggal Keluar\t: ");
    getchar();
    fgets(p.tanggal_keluar, sizeof(p.tanggal_keluar), stdin);

    FILE *f = fopen("pemesanan.dat", "ab");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);

    printf("\nPemesanan berhasil!\n");
}
void bayar_layanan() {
    struct Pemesanan p;
    int id_pemesanan;

    printf("\nMasukkan ID Pemesanan\t: ");
    scanf("%d", &id_pemesanan);

    FILE *f = fopen("pemesanan.dat", "rb");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        if (p.id == id_pemesanan) {  // Corrected the variable name
            struct JasaService js;
            FILE *f2 = fopen("jasa_service.dat", "rb");
            if (!f2) {
                printf("Error opening file\n");
                fclose(f);
                return;
            }

            while (fread(&js, sizeof(js), 1, f2) == 1) {
                if (js.id == p.id_jasa_service) {  // Corrected the variable name
                    FILE *f3 = fopen("pembayaran.dat", "ab");
                    if (!f3) {
                        printf("Error opening file\n");
                        fclose(f2);
                        fclose(f);
                        return;
                    }

                    // Assuming you want to write the Pemesanan and JasaService data to the pembayaran file
                    fwrite(&p, sizeof(p), 1, f3);
                    fwrite(&js, sizeof(js), 1, f3);

                    fclose(f3);

                    // You may want to remove the paid Pemesanan from the pemesanan.dat file
                    // This is just an example, and you may need to adjust this logic based on your actual requirements
                    FILE *temp = fopen("temp.dat", "wb");
                    rewind(f);

                    while (fread(&p, sizeof(p), 1, f) == 1) {
                        if (p.id != id_pemesanan) {
                            fwrite(&p, sizeof(p), 1, temp);
                        }
                    }

                    fclose(f);
                    fclose(temp);

                    // Remove the original file and rename the temporary file
                    remove("pemesanan.dat");
                    rename("temp.dat", "pemesanan.dat");

                    printf("\nPembayaran layanan berhasil!\n");
                    fclose(f2);
                    return;
                }
            }

            fclose(f2);
        }
    }

    fclose(f);
    printf("\nPemesanan dengan ID %d tidak ditemukan\n", id_pemesanan);
}


void lihat_progress_cucian() {
    struct Pemesanan p;
    struct JasaService js;
    int id_pemesanan;

    printf("\nMasukkan ID Pemesanan\t: ");
    scanf("%d", &id_pemesanan);

    FILE *f = fopen("pemesanan.dat", "rb");
    if (!f) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        if (p.id == id_pemesanan) {  // Corrected the variable name
            FILE *f2 = fopen("jasa_service.dat", "rb");
            if (!f2) {
                printf("Error opening file\n");
                fclose(f);
                return;
            }

            while (fread(&js, sizeof(js), 1, f2) == 1) {
                if (js.id == p.id_jasa_service) {  // Corrected the variable name
                    printf("\nProgres Cucian untuk Pemesanan dengan ID %d\n", id_pemesanan);
                    printf("Nama: %s", p.nama);
                    printf("Alamat: %s", p.alamat);
                    printf("No Telp: %d\n", p.telp);
                    printf("Tanggal Masuk: %s", p.tanggal_masuk);
                    printf("Tanggal Keluar: %s", p.tanggal_keluar);
                    printf("ID Jasa Service: %d\n", p.id_jasa_service);
                    printf("Harga: %d\n", p.harga);
                    printf("Progres Cucian: %s\n", p.status_pemesanan);
                    fclose(f2);
                    fclose(f);
                    return;
                }
            }

            fclose(f2);
        }
    }

    fclose(f);
    printf("\nPemesanan dengan ID %d tidak ditemukan\n", id_pemesanan);
}

void login_admin() {
    struct Admin admin = create_admin("admin", "password");

    int attempts = 3;  // Maximum number of login attempts

    while (attempts > 0) {
        char username[50];
        char password[50];

        printf("\nMASUKKAN USERNAME ANDA: ");
        scanf("%s", username);
        printf("MASUKKAN PASSWORD ANDA: ");
        scanf("%s", password);

        if (check_login(&admin, username, password)) {
            printf("\nLogin berhasil.\n");
            // Call the relevant admin function or display menu here
            displayAdminMenu();
            return;
        } else {
            printf("\nUSERNAME DAN PASSWORD SALAH. Sisa percobaan: %d\n", attempts - 1);
            attempts--;
        }
    }

    printf("\nAnda telah melebihi batas percobaan login. Aplikasi akan keluar.\n");
    exit(0);
}

void displayAdminMenu() {
    int choice;
    do {
        printf("_________________________________________\n");
        printf("|           ADMIN MENU                   |\n");
        printf("|1. Lihat Data user                      |\n");
        printf("|2. Tambah kategori kendaraan            |\n");
        printf("|3. Tambah harga dan jenis service       |\n");
        printf("|4. Lihat dan ubah progres               |\n");
        printf("|5. Kembali ke menu Utama                |\n");
        printf("|6. Logout                               |\n");
        printf("|_______________________________________|\n");
        printf("\n Pilih menu\t: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lihat_data_user();
                break;
            case 2:
                tambah_kategori_kendaraan();
                break;
            case 3:
                tambah_harga_dan_jenis_service();
                break;
            case 4:
                lihat_dan_ubah_progress_cucian();
                break;
            case 5:
                main(); // Assuming you want to go back to the main menu
                break;
            case 6:
                logoutA();
                break;
            default:
                printf("\nMenu yang anda pilih tidak tersedia");
                break;
        }
    } while (choice != 5);  // Adjust the exit condition based on your requirements
}



void lihat_data_user() {
    struct User userr;
    FILE *f = fopen("reg user.dat", "rb");

    if (!f) {
        printf("Error opening file\n");
        return;
    }

    while (fread(&userr, sizeof(userr), 1, f) == 1) {
        printf("\nNama\t\t: %s", userr.nama);
        printf("\nAlamat\t\t: %s", userr.alamat);
        printf("\nNo HP\t\t: %s", userr.no_telepon);
        printf("\nUsername\t: %s", userr.user);
        printf("\nPassword\t: %s", userr.pas);
    }

    fclose(f);
}


void tambah_kategori_kendaraan() {
    struct KategoriKendaraan kk;
    FILE *f = fopen("kategori_kendaraan.dat", "ab");

    if (!f) {
        printf("Error opening file\n");
        return;
    }

    printf("Masukkan Jenis Kendaraan: ");
    getchar(); // Consume newline character
    fgets(kk.jenis_kendaraan, sizeof(kk.jenis_kendaraan), stdin);

    printf("Masukkan Harga Kendaraan: ");
    scanf("%d", &kk.harga);

    printf("Masukkan Jenis Service: ");
    getchar(); // Consume newline character
    fgets(kk.jenis_service, sizeof(kk.jenis_service), stdin);

    fwrite(&kk, sizeof(kk), 1, f);
    fclose(f);

    printf("Kategori Kendaraan berhasil ditambahkan.\n");
}


void tambah_harga_dan_jenis_service() {
    struct JasaService js;
    FILE *f = fopen("jasa_service.dat", "ab");

    if (!f) {
        printf("Error opening file\n");
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
    int id_pemesanan;

    // Prompt user for the Pemesanan ID
    printf("\nMasukkan ID Pemesanan: ");
    scanf("%d", &id_pemesanan);

    // Open the Pemesanan file for reading and writing
    FILE *file = fopen("pemesanan.dat", "r+b");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    struct Pemesanan p;

    // Search for the requested Pemesanan ID
    while (fread(&p, sizeof(p), 1, file) == 1) {
        if (p.id == id_pemesanan) {
            // Display current progress
            printf("\nID Pemesanan: %d\n", p.id);
            printf("Nama: %s\n", p.nama);
            printf("Alamat: %s\n", p.alamat);
            printf("No Telp: %d\n", p.telp);
            printf("Tanggal Masuk: %s", p.tanggal_masuk);
            printf("Tanggal Keluar: %s", p.tanggal_keluar);
            printf("ID Jasa Service: %d\n", p.id_jasa_service);
            printf("Harga: %d\n", p.harga);
            printf("Progres Cucian: %s\n", p.status_pemesanan);

            // Prompt for updating progress
            printf("\nUbah Progres Cucian (max 49 karakter): ");
            scanf(" %49[^\n]", p.status_pemesanan);

            // Move the file pointer back to the beginning of the record
            fseek(file, sizeof(p), SEEK_CUR);

            // Write the updated record back to the file
            fwrite(&p, sizeof(p), 1, file);

            printf("\nProgres Cucian berhasil diubah!\n");

            // Close the file and return
            fclose(file);
            return;
        }
    }

    // If the Pemesanan ID is not found
    printf("\nPemesanan dengan ID %d tidak ditemukan\n", id_pemesanan);

    // Close the file
    fclose(file);
}

void logoutA() {
    printf("Logout berhasil.\n");
}