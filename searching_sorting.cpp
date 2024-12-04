#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk transform
#include <iomanip>   // Untuk set width pada output

using namespace std;

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    string prodi;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const vector<Mahasiswa>& data) {
    cout << left << setw(15) << "NIM" << setw(25) << "Nama" << setw(30) << "Prodi" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        cout << left << setw(15) << data[i].nim << setw(25) << data[i].nama << setw(30) << data[i].prodi << endl;
    }
    cout << endl;
}

// Fungsi untuk mengubah string menjadi huruf kecil
string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM, Nama, atau Prodi (partial matching)
void cariMahasiswa(const vector<Mahasiswa>& data, int kriteria, const string& query) {
    bool ditemukan = false;
    string queryLower = toLowerCase(query); // Konversi query ke huruf kecil
    for (size_t i = 0; i < data.size(); ++i) {
        bool cocok = false;
        string nimLower = toLowerCase(data[i].nim);
        string namaLower = toLowerCase(data[i].nama);
        string prodiLower = toLowerCase(data[i].prodi);

        // Partial matching dengan find() untuk setiap kriteria
        if (kriteria == 1 && nimLower.find(queryLower) != string::npos) {
            cocok = true;
        } else if (kriteria == 2 && namaLower.find(queryLower) != string::npos) {
            cocok = true;
        } else if (kriteria == 3 && prodiLower.find(queryLower) != string::npos) {
            cocok = true;
        }

        if (cocok) {
            if (!ditemukan) {
                cout << "\nHasil Pencarian:" << endl;
                cout << left << setw(15) << "NIM" << setw(25) << "Nama" << setw(30) << "Prodi" << endl;
                cout << "---------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << data[i].nim << setw(25) << data[i].nama << setw(30) << data[i].prodi << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan kriteria '" << query << "' tidak ditemukan." << endl;
    }
    cout << endl;
}

// Fungsi untuk mengurutkan data berdasarkan pilihan
void urutkanData(vector<Mahasiswa>& data, int metode) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            bool kondisi = false;
            if (metode == 1) { // Urutkan berdasarkan nama
                kondisi = data[j].nama > data[j + 1].nama;
            } else if (metode == 2) { // Urutkan berdasarkan NIM
                kondisi = data[j].nim > data[j + 1].nim;
            } else if (metode == 3) { // Urutkan berdasarkan prodi
                kondisi = data[j].prodi > data[j + 1].prodi;
            }
            if (kondisi) {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Data mahasiswa
    vector<Mahasiswa> data;
    data.push_back((Mahasiswa){"23106050100", "Aldo Prasetyo", "Informatika"});
    data.push_back((Mahasiswa){"23106050211", "Siti Aisyah", "Sistem Informasi"});
    data.push_back((Mahasiswa){"23106050322", "Rudi Hartono", "Teknik Komputer"});
    data.push_back((Mahasiswa){"23106050433", "Dewi Lestari", "Ilmu Komunikasi"});
    data.push_back((Mahasiswa){"23106050544", "Andi Saputra", "Teknik Sipil"});
    data.push_back((Mahasiswa){"23106050655", "Budi Pramono", "Manajemen"});
    data.push_back((Mahasiswa){"23106050766", "Cynthia Anggraini", "Psikologi"});
    data.push_back((Mahasiswa){"23106050877", "Fajar Nugroho", "Akuntansi"});
    data.push_back((Mahasiswa){"23106050988", "Nina Sari", "Hukum"});
    data.push_back((Mahasiswa){"23106051099", "Rina Oktaviani", "Desain Komunikasi Visual"});

    bool dataDitampilkan = false; // Data tidak ditampilkan di awal

    while (true) {
        // Menampilkan menu pilihan
        cout << "==============================" << endl;
        cout << "Pilihan Menu:" << endl;
        cout << "1. Tampilkan Daftar Mahasiswa" << endl;
        cout << "2. Cari Data Mahasiswa" << endl;
        cout << "3. Urutkan Data Mahasiswa" << endl;
        cout << "4. Keluar" << endl;
        cout << "==============================" << endl;
        cout << "Pilih menu (1/2/3/4): ";
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        if (pilihan == 1) {
            // Menampilkan daftar mahasiswa
            cout << "\nMenampilkan Daftar Mahasiswa:" << endl;
            tampilkanData(data);
            dataDitampilkan = true; // Setelah menampilkan, set kembali dataDitampilkan menjadi true

        } else if (pilihan == 2) {
            // Pencarian data
            cout << "Pilih kriteria pencarian:" << endl;
            cout << "1. Berdasarkan NIM" << endl;
            cout << "2. Berdasarkan Nama" << endl;
            cout << "3. Berdasarkan Prodi" << endl;
            cout << "Pilih kriteria (1/2/3): ";
            int kriteria;
            cin >> kriteria;
            cin.ignore();  // Untuk mengabaikan karakter newline

            cout << "Masukkan data yang ingin dicari (partial match diperbolehkan): ";
            string query;
            getline(cin, query);

            cariMahasiswa(data, kriteria, query);

        } else if (pilihan == 3) {
            // Pengurutan data
            cout << "Metode pengurutan:" << endl;
            cout << "1. Berdasarkan Nama" << endl;
            cout << "2. Berdasarkan NIM" << endl;
            cout << "3. Berdasarkan Prodi" << endl;
            cout << "Pilih metode (1/2/3): ";
            int metode;
            cin >> metode;

            if (metode >= 1 && metode <= 3) {
                urutkanData(data, metode);
                cout << "\nData Mahasiswa Setelah Diurutkan:" << endl;
                tampilkanData(data);
            } else {
                cout << "Metode pengurutan tidak valid." << endl;
            }

        } else if (pilihan == 4) {
            // Keluar dari program
            cout << "Keluar dari program. Terima kasih!" << endl;
            break;

        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }

    return 0;
}

