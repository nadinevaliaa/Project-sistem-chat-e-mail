#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

// Struktur untuk menyimpan satu email
struct Email {
    string pengirim;
    string penerima;
    string subjek;
    string isi;
};

// Unordered map untuk menyimpan akun email dan riwayat inbox dan sent items
unordered_map<string, pair<vector<Email>, vector<Email>>> akun;

// Fungsi untuk membuat akun email baru
void buatAkun() {
    string email;
    cout << "Masukkan email: ";
    getline(cin, email);
    if (akun.find(email) == akun.end()) {
        akun[email] = make_pair(vector<Email>(), vector<Email>()); // Buat inbox dan sent items baru
        cout << "Akun email berhasil dibuat.\n";
    } else {
        cout << "Akun email sudah ada.\n";
    }
}

// Fungsi untuk login
bool login(string& email) {
    cout << "Masukkan email: ";
    getline(cin, email);
    if (akun.find(email) == akun.end()) {
        cout << "Akun email tidak ditemukan.\n";
        return false;
    } else {
        cout << "Login berhasil.\n";
        return true;
    }
}

// Fungsi untuk membuat dan mengirim email
void buatDanKirimEmail(const string& pengirim) {
    string penerima, subjek, isi;
    cout << "Masukkan email penerima: ";
    getline(cin, penerima);
    if (akun.find(penerima) == akun.end()) {
        cout << "Akun email penerima tidak ditemukan.\n";
        return;
    }
    cout << "Masukkan subjek: ";
    getline(cin, subjek);
    cout << "Masukkan isi: ";
    getline(cin, isi);
    
    Email email = {pengirim, penerima, subjek, isi};
    akun[pengirim].second.push_back(email); // Tambahkan email ke sent items pengirim
    akun[penerima].first.push_back(email); // Tambahkan email ke inbox penerima
    cout << "Email berhasil dikirim.\n";
}

// Fungsi untuk menampilkan inbox
void lihatInbox(const string& email) {
    if (akun[email].first.empty()) {
        cout << "Inbox Anda kosong.\n";
        return;
    }
    cout << "Inbox Anda:\n";
    int index = 1;
    for (const auto& email : akun[email].first) {
        cout << index << ". Dari: " << email.pengirim << ", Subjek: " << email.subjek << endl;
        index++;
    }
}

// Fungsi untuk menampilkan sent items
void lihatSentItems(const string& email) {
    if (akun[email].second.empty()) {
        cout << "Sent items Anda kosong.\n";
        return;
    }
    cout << "Sent items Anda:\n";
    int index = 1;
    for (const auto& email : akun[email].second) {
        cout << index << ". Ke: " << email.penerima << ", Subjek: " << email.subjek << endl;
        index++;
    }
}

// Fungsi untuk membaca email di inbox
void bacaEmailDiInbox(const string& email, int indeks) {
    if (indeks < 1 || indeks > akun[email].first.size()) {
        cout << "Indeks tidak valid.\n";
        return;
    }
    cout << "Email dari: " << akun[email].first[indeks - 1].pengirim << "\n";
    cout << "Subjek: " << akun[email].first[indeks - 1].subjek << "\n";
    cout << "Isi:\n" << akun[email].first[indeks - 1].isi << "\n";
}

// Fungsi untuk membaca email di sent items
void bacaEmailDiSentItems(const string& email, int indeks) {
    if (indeks < 1 || indeks > akun[email].second.size()) {
        cout << "Indeks tidak valid.\n";
        return;
    }
    cout << "Email ke: " << akun[email].second[indeks - 1].penerima << "\n";
    cout << "Subjek: " << akun[email].second[indeks - 1].subjek << "\n";
    cout << "Isi:\n" << akun[email].second[indeks - 1].isi << "\n";
}

// Fungsi untuk menghapus email dari inbox
void hapusEmailDariInbox(const string& email, int indeks) {
    if (indeks < 1 || indeks > akun[email].first.size()) {
        cout << "Indeks tidak valid.\n";
        return;
    }
    akun[email].first.erase(akun[email].first.begin() + (indeks - 1));
    cout << "Email berhasil dihapus dari inbox.\n";
}

// Fungsi untuk menghapus email dari sent items
void hapusEmailDariSentItems(const string& email, int indeks) {
    if (indeks < 1 || indeks > akun[email].second.size()) {
        cout << "Indeks tidak valid.\n";
        return;
    }
    akun[email].second.erase(akun[email].second.begin() + (indeks - 1));
    cout << "Email berhasil dihapus dari sent items.\n";
}

int main() {
    string email;
    int pilihanMenu;
    do {
        cout << "\nMenu:\n";
        cout << "1. Membuat akun email\n";
        cout << "2. Login\n";
        cout << "3. Membuat dan mengirim email\n";
        cout << "4. Lihat inbox\n";
        cout << "5. Lihat sent items\n";
        cout << "6. Baca email di inbox\n";
        cout << "7. Baca email di sent items\n";
        cout << "8. Hapus email dari inbox\n";
        cout << "9. Hapus email dari sent items\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihanMenu;
        cin.ignore(); // Membersihkan buffer input

        switch (pilihanMenu) {

            case 1:
            system ("cls");
                buatAkun();
                system ("pause");
                break;
            case 2:
            system ("cls");
                if (login(email)) {
                    // Lanjutkan ke menu lainnya
                } else {
                    cout << "Login gagal.\n";
                }
                system ("pause");
                break;
            case 3:
            system ("cls");
                if (!email.empty()) {
                    buatDanKirimEmail(email);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 4:
            system ("cls");
                if (!email.empty()) {
                    lihatInbox(email);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 5:
            system ("cls");
                if (!email.empty()) {
                    lihatSentItems(email);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 6:
            system ("cls");
                if (!email.empty()) {
                    int indeks;
                    cout << "Masukkan indeks email di inbox: ";
                    cin >> indeks;
                    cin.ignore(); // Membersihkan buffer input
                    bacaEmailDiInbox(email, indeks);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 7:
            system ("cls");
                if (!email.empty()) {
                    int indeks;
                    cout << "Masukkan indeks email di sent items: ";
                    cin >> indeks;
                    cin.ignore(); // Membersihkan buffer input
                    bacaEmailDiSentItems(email, indeks);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 8:
            system ("cls");
                if (!email.empty()) {
                    int indeks;
                    cout << "Masukkan indeks email di inbox yang ingin dihapus: ";
                    cin >> indeks;
                    cin.ignore(); // Membersihkan buffer input
                    hapusEmailDariInbox(email, indeks);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 9:
            system ("cls");
                if (!email.empty()) {
                    int indeks;
                    cout << "Masukkan indeks email di sent items yang ingin dihapus: ";
                    cin >> indeks;
                    cin.ignore(); // Membersihkan buffer input
                    hapusEmailDariSentItems(email, indeks);
                } else {
                    cout << "Anda belum login.\n";
                }
                system ("pause");
                break;
            case 10:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihanMenu != 0);
    
    return 0;
}