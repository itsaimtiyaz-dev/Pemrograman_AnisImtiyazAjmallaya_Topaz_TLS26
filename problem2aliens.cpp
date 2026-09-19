#include <iostream>

using namespace std;

int main() {
    char pesan[1000];
    
    cout << "Masukkan pesan: ";
    // Mengambil input teks beserta spasi menggunakan cin.getline()
    cin.getline(pesan, 1000);
    
    // 1. Menghitung panjang string secara manual (karena dilarang pakai <string>)
    int length = 0;
    while (pesan[length] != '\0') {
        length++;
    }
    
    char pesan_hasil[1000];
    
    // Karakter pertama (indeks 0) tidak digeser, langsung disalin
    pesan_hasil[0] = pesan[0];
    
    // 2. Memproses karakter dari indeks 1 sampai akhir
    for (int i = 1; i < length; i++) {
        char saat_ini = pesan[i];
        char sebelumnya = pesan[i - 1];
        
        // Cek apakah karakter saat ini DAN karakter sebelumnya merupakan huruf
        bool is_saat_ini_alpha = (saat_ini >= 'A' && saat_ini <= 'Z') || (saat_ini >= 'a' && saat_ini <= 'z');
        bool is_sebelumnya_alpha = (sebelumnya >= 'A' && sebelumnya <= 'Z') || (sebelumnya >= 'a' && sebelumnya <= 'z');
        
        if (is_saat_ini_alpha && is_sebelumnya_alpha) {
            // Hitung nilai shift berdasarkan posisi huruf karakter sebelumnya (A/a = 1, B/b = 2, dst)
            int shift = 0;
            if (sebelumnya >= 'A' && sebelumnya <= 'Z') {
                shift = sebelumnya - 'A' + 1;
            } else if (sebelumnya >= 'a' && sebelumnya <= 'z') {
                shift = sebelumnya - 'a' + 1;
            }
            
            // Pergeseran untuk Huruf Besar (A-Z)
            if (saat_ini >= 'A' && saat_ini <= 'Z') {
                pesan_hasil[i] = 'A' + (saat_ini - 'A' + shift) % 26;
            } 
            // Pergeseran untuk Huruf Kecil (a-z)
            else if (saat_ini >= 'a' && saat_ini <= 'z') {
                pesan_hasil[i] = 'a' + (saat_ini - 'a' + shift) % 26;
            }
        } else {
            // Jika bukan pasangan huruf, karakter tidak diubah (seperti spasi/simbol)
            pesan_hasil[i] = saat_ini;
        }
    }
    
    // Beri penanda akhir string pada pesan hasil
    pesan_hasil[length] = '\0';
    
    // Tampilkan hasil enkripsi
    cout << "Pesan Hasil: " << pesan_hasil << endl;
    
    return 0;
}