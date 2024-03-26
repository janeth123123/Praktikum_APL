#include <iostream>
#include <string>
using namespace std;

struct Flower {
    string name;
    int price;
};

Flower flowers[10]; 
int flowerCount = 0; 
int login = 0;

bool loginProcess() {
    cout << " (Masukkan Nama): ";
    string nama_user;
    cin >> nama_user;
    cout << "(Masukkan Nim): ";
    int nim_user;
    cin >> nim_user;

    if (nama_user == "Junesty" && nim_user == 140) {
        cout << "Login berhasil!\n";
        return true;
    } else {
        cout << "Login gagal. Silakan coba lagi.\n";
        login++;
        if (login >= 3) {
            cout << "Anda telah mencapai batas maksimum percobaan login. Program berhenti.\n";
            return false;
        }
        return false;
    }
}

void displayMenu() {
    cout << "\nSelamat Datang di Toko Bunga!\n";
    cout << "1. Tambah Bunga\n";
    cout << "2. Hapus Bunga\n";
    cout << "3. Ubah Bunga\n";
    cout << "4. Lihat Jenis Bunga yang Tersedia\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

void addFlower() {
    if (flowerCount < 10) {
        cout << "Masukkan Nama Bunga: ";
        cin >> flowers[flowerCount].name;
        cout << "Masukkan Harga Bunga: ";
        cin >> flowers[flowerCount].price;
        cout << "Bunga Berhasil Ditambahkan!\n";
        flowerCount++;
    } else {
        cout << "Maaf, tidak bisa menambahkan bunga. Sudah mencapai batas maksimum.\n";
    }
}

void deleteFlower() {
    if (flowerCount > 0) {
        cout << "Masukkan Indeks Bunga Yang Ingin dihapus (0 - " << flowerCount - 1 << "): ";
        int index;
        cin >> index;
        if (index >= 0 && index < flowerCount) {
           
            for (int i = index; i < flowerCount - 1; i++) {
                flowers[i] = flowers[i + 1];
            }
            flowerCount--;
            cout << "Bunga Berhasil dihapus!\n";
        } else {
            cout << "Indeks tidak valid!\n";
        }
    } else {
        cout << "Tidak ada bunga untuk dihapus.\n";
    }
}

void updateFlower() {
    if (flowerCount > 0) {
        cout << "Masukkan Indeks Bunga Yang Ingin diubah (0 - " << flowerCount - 1 << "): ";
        int index;
        cin >> index;
        if (index >= 0 && index < flowerCount) {
            cout << "Masukkan Nama Bunga Baru: ";
            cin >> flowers[index].name;
            cout << "Masukkan Harga Bunga Baru: ";
            cin >> flowers[index].price;
            cout << "Bunga Berhasil Diubah!\n";
        } else {
            cout << "Indeks tidak valid!\n";
        }
    } else {
        cout << "Tidak ada bunga untuk diubah.\n";
    }
}

void displayFlowers() {
    if (flowerCount > 0) {
        cout << "Daftar Bunga:\n";
        for (int i = 0; i < flowerCount; i++) {
            cout << "Indeks: " << i << endl;
            cout << "Nama Bunga: " << flowers[i].name << "\n";
            cout << "Harga Bunga: " << flowers[i].price << "\n";
        }
    } else {
        cout << "Tidak ada bunga yang tersedia.\n";
    }
}

void recursiveLogin() {
    if (!loginProcess()) {
        recursiveLogin();
    }
}

int main() {
    recursiveLogin();

    int pilihan;
    while (true) {
        displayMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                addFlower();
                break;

            case 2:
                deleteFlower();
                break;

            case 3:
                updateFlower();
                break;

            case 4:
                displayFlowers();
                break;

            case 5:
                cout << "Sampai Jumpa!\n";
                return 0;
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }

    return 0;
}
