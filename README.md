Topik 4. Sistem Kompresi Data Sederhana
Konteks industri: penyimpanan & transmisi data
Kasus ini menggambarkan kebutuhan perusahaan dalam mengelola penyimpanan dan
transmisi data teks yang volumenya terus meningkat, seperti log aktivitas sistem, data transaksi,
atau pesan komunikasi internal. Pada tahap awal, ukuran data masih relatif kecil sehingga
penyimpanan dan pengiriman data dapat dilakukan tanpa optimasi khusus. Namun, seiring
pertumbuhan data, kebutuhan ruang penyimpanan meningkat dan waktu transmisi menjadi
lebih lama. Oleh karena itu, diperlukan sistem kompresi data sederhana yang efisien dan
mudah dikelola, dengan fokus pada pemilihan struktur data yang tepat. Pada topik ini, kompresi
data dipahami sebagai proses pengkodean data agar ukurannya lebih kecil. Mahasiswa tidak
diwajibkan mengimplementasikan algoritma kompresi kompleks atau standar industri (misalnya
ZIP, LZW, atau Huffman penuh). Fokus utama adalah bagaimana struktur data digunakan untuk
menyimpan, mengakses, dan mengelola informasi frekuensi atau kode karakter secara efisien.
Permasalahan di lapangan
● Ukuran data teks terus bertambah sehingga membutuhkan ruang penyimpanan lebih
besar.
● Transmisi data menjadi lebih lambat karena ukuran file yang besar.
● Pengelolaan data tanpa kompresi sederhana tidak lagi efisien.
● Pemilihan struktur data yang kurang tepat menyebabkan proses kompresi/dekompresi
lambat.
Tujuan proyek
Membangun sistem kompresi data teks sederhana dan menganalisis struktur data yang paling
efisien untuk proses pengkodean dan pengelolaan data kompresi.
Domain data (minimal)
Data teks (string)
Karakter
Frekuensi kemunculan karakter
Kode hasil kompresi
Ukuran data sebelum dan sesudah kompresi
Aktivitas sistem wajib
Insert / input data teks
Analisis frekuensi karakter
Generate kode kompresi sederhana
Search kode karakter
Dekompresi data teks
Fokus analisis
Analisis perbandingan struktur data terhadap:
● Kecepatan analisis frekuensi karakter
● Kecepatan proses encoding dan decoding
● Efisiensi penggunaan memori
● Dampak pertumbuhan ukuran data terhadap performa sistem
Target Minggu ke-7 (Progress)
● Spesifikasi sistem & skenario penggunaan data teks
● Implementasi minimal 1 struktur data
● Dataset awal (teks dummy / simulasi)
● Pengujian awal analisis frekuensi & encoding sederhana
Target Minggu ke-14 (Final)
● Implementasi lengkap ≥ 2 struktur data
● Grafik perbandingan waktu eksekusi & penggunaan memori
● Demo aplikasi kompresi dan dekompresi data sederhana
● Laporan analisis performa & rekomendasi struktur data
Catatan:
Mahasiswa tidak diwajibkan mengimplementasikan algoritma kompresi optimal, cukup yang
sederhana saja. Penilaian difokuskan pada penggunaan dan analisis struktur data dalam sistem
kompresi data sederhana.
