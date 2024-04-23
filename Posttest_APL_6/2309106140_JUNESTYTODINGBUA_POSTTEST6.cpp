#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

struct Flower {
    string name;
    int price;
};

vector<Flower> flowers;
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
    cout << "5. Cari Bunga\n"; 
    cout << "6. Keluar\n";
    cout << "Pilih menu: ";
}

void addFlower() {
    if (flowers.size() < 10) {
        Flower newFlower;
        cout << "Masukkan Nama Bunga: ";
        cin >> newFlower.name;
        cout << "Masukkan Harga Bunga: ";
        cin >> newFlower.price;
        flowers.push_back(newFlower);
        cout << "Bunga Berhasil Ditambahkan!\n";
    } else {
        cout << "Maaf, tidak bisa menambahkan bunga. Sudah mencapai batas maksimum.\n";
    }
}

void deleteFlower() {
    if (flowers.empty()) {
        cout << "Tidak ada bunga untuk dihapus.\n";
        return;
    }

    int index;
    cout << "Masukkan Indeks Bunga Yang Ingin dihapus (0 - " << flowers.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= flowers.size()) {
        cout << "Indeks tidak valid!\n";
        return;
    }

    flowers.erase(flowers.begin() + index);
    cout << "Bunga Berhasil dihapus!\n";
}

void updateFlower() {
    if (flowers.empty()) {
        cout << "Tidak ada bunga untuk diubah.\n";
        return;
    }

    int index;
    cout << "Masukkan Indeks Bunga Yang Ingin diubah (0 - " << flowers.size() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= flowers.size()) {
        cout << "Indeks tidak valid!\n";
        return;
    }

    cout << "Masukkan Nama Bunga Baru: ";
    cin >> flowers[index].name;
    cout << "Masukkan Harga Bunga Baru: ";
    cin >> flowers[index].price;
    cout << "Bunga Berhasil Diubah!\n";
}

void displayFlowers() {
    if (flowers.empty()) {
        cout << "Tidak ada bunga yang tersedia.\n";
        return;
    }

    cout << "Daftar Bunga:\n";
    for (int i = 0; i < flowers.size(); i++) {
        cout << "Indeks: " << i << endl;
        cout << "Nama Bunga: " << flowers[i].name << "\n";
        cout << "Harga Bunga: " << flowers[i].price << "\n";
    }
}

void recursiveLogin() {
    if (!loginProcess()) {
        recursiveLogin();
    }
}

void bubbleSort(vector<Flower>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearchAscending(const string& key) {
    int low = 0;
    int high = flowers.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (flowers[mid].name == key) {
            return mid;
        } else if (flowers[mid].name < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchDescending(const string& key) {
    int low = 0;
    int high = flowers.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (flowers[mid].name == key) {
            return mid;
        } else if (flowers[mid].name > key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
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
                bubbleSort(flowers);
                cout << "\nDaftar Bunga (Nama diurutkan secara ascending):\n";
                displayFlowers();
                reverse(flowers.begin(), flowers.end());
                cout << "\nDaftar Bunga (Nama diurutkan secara descending):\n";
                displayFlowers();
                break;

            case 5: {
                string searchKey;
                cout << "Masukkan nama bunga yang ingin dicari: ";
                cin >> searchKey;

                int ascIndex = binarySearchAscending(searchKey);
                if (ascIndex != -1) {
                    cout << "Bunga dengan nama \"" << searchKey << "\" ditemukan pada indeks " << ascIndex << " (Ascending)\n";
                } else {
                    cout << "Bunga dengan nama \"" << searchKey << "\" tidak ditemukan (Ascending)\n";
                }

                int descIndex = binarySearchDescending(searchKey);
                if (descIndex != -1) {
                    cout << "Bunga dengan nama \"" << searchKey << "\" ditemukan pada indeks " << descIndex << " (Descending)\n";
                } else {
                    cout << "Bunga dengan nama \"" << searchKey << "\" tidak ditemukan (Descending)\n";
                }
                break;
            }

            case 6:
                cout << "Sampai Jumpa!\n";
                return 0;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }

    return 0;
}
