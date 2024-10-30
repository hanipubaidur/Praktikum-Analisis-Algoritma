// Data mahasiswa
const mahasiswa = [
    { nim: '23106050100', nama: 'Aldo Prasetyo', prodi: 'Informatika' },
    { nim: '23106050211', nama: 'Siti Aisyah', prodi: 'Sistem Informasi' },
    { nim: '23106050322', nama: 'Rudi Hartono', prodi: 'Teknik Komputer' },
    { nim: '23106050433', nama: 'Dewi Lestari', prodi: 'Ilmu Komunikasi' },
    { nim: '23106050544', nama: 'Andi Saputra', prodi: 'Teknik Sipil' },
    { nim: '23106050655', nama: 'Budi Pramono', prodi: 'Manajemen' },
    { nim: '23106050766', nama: 'Cynthia Anggraini', prodi: 'Psikologi' },
    { nim: '23106050877', nama: 'Fajar Nugroho', prodi: 'Akuntansi' },
    { nim: '23106050988', nama: 'Nina Sari', prodi: 'Hukum' },
    { nim: '23106051099', nama: 'Rina Oktaviani', prodi: 'Desain Komunikasi Visual' },
];

// Fungsi untuk mencari mahasiswa
function cariMahasiswa(parameter) {
    const hasil = mahasiswa.filter(mhs => 
        mhs.nim.includes(parameter) || 
        mhs.nama.toLowerCase().includes(parameter.toLowerCase()) || 
        mhs.prodi.toLowerCase().includes(parameter.toLowerCase())
    );

    if (hasil.length > 0) {
        return hasil;
    } else {
        return 'Mahasiswa tidak ditemukan.';
    }
}

// Fungsi untuk mengurutkan mahasiswa
function sortMahasiswa(kriteria) {
    return mahasiswa.slice().sort((a, b) => {
        if (kriteria === 'nim') {
            return a.nim.localeCompare(b.nim);
        } else if (kriteria === 'nama') {
            return a.nama.localeCompare(b.nama);
        } else if (kriteria === 'prodi') {
            return a.prodi.localeCompare(b.prodi);
        }
        return 0;
    });
}

// Loop untuk mencari mahasiswa atau mengurutkan
let lagi = true;

while (lagi) {
    const pilihan = prompt("Apakah Anda ingin mencari mahasiswa (1) atau mengurutkan mahasiswa (2)? Pilih (1/2) : ");

    if (pilihan === '1') {
        const input = prompt("Masukkan NIM, Nama, atau Prodi Mahasiswa Yang Ingin Dicari : ");
        const hasilPencarian = cariMahasiswa(input);

        if (typeof hasilPencarian === 'string') {
            console.log(hasilPencarian);
        } else {
            console.log("Hasil Pencarian:");
            hasilPencarian.forEach(mhs => {
                console.log(`NIM: ${mhs.nim}, Nama: ${mhs.nama}, Prodi: ${mhs.prodi}`);
            });
        }
    } else if (pilihan === '2') {
        const kriteria = prompt("Pilih Kriteria Pengurutan (nim/nama/prodi) : ").toLowerCase();
        const hasilSorting = sortMahasiswa(kriteria);

        console.log("Data Mahasiswa yang Terurut:");
        hasilSorting.forEach(mhs => {
            console.log(`NIM: ${mhs.nim}, Nama: ${mhs.nama}, Prodi: ${mhs.prodi}`);
        });
    } else {
        console.log("Pilihan Tidak Valid. Silakan Masukkan 1 Atau 2.");
    }

    // Tanya pengguna apakah ingin mencari atau mengurutkan lagi
    const tanyaLagi = prompt("Apakah Anda Ingin Mencari Atau Mengurutkan Lagi? (y/n)").toLowerCase();
    lagi = (tanyaLagi === 'y');
}

console.log("Terima Kasih Telah Menggunakan Program Pencarian Dan Pengurutan Mahasiswa!");