#include <iostream>
using namespace std;

// deklarasi array untuk papan permainan
char papan[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

// fungsi untuk menampilkan papan permainan
void papanTampilan()
{
    cout << "  1 | 2 | 3 \n";
    cout << "-------------\n";
    cout << "  4 | 5 | 6 \n";
    cout << "-------------\n";
    cout << "  7 | 8 | 9 \n";
    cout << "-------------\n";
    cout << endl;
    cout << endl;
    cout << "-------------\n";
    cout << "  " << papan[0][0] << " | " << papan[0][1] << " | " << papan[0][2] << " \n";
    cout << "-------------\n";
    cout << "  " << papan[1][0] << " | " << papan[1][1] << " | " << papan[1][2] << " \n";
    cout << "-------------\n";
    cout << "  " << papan[2][0] << " | " << papan[2][1] << " | " << papan[2][2] << " \n";
}

// fungsi untuk memeriksa pemenang atau seri
char periksaPemenang()
{
    // cek baris horizontal
    for (int i = 0; i < 3; i++)
    {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][0] != ' ')
        {
            return papan[i][0];
        }
    }

    // cek kolom vertikal
    for (int j = 0; j < 3; j++)
    {
        if (papan[0][j] == papan[1][j] && papan[1][j] == papan[2][j] && papan[0][j] != ' ')
        {
            return papan[0][j];
        }
    }

    // cek diagonal utama
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[0][0] != ' ')
    {
        return papan[0][0];
    }

    // cek diagonal sekunder
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0] && papan[0][2] != ' ')
    {
        return papan[0][2];
    }

    // cek seri
    bool penuh = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (papan[i][j] == ' ')
            {
                penuh = false;
                break;
            }
        }
    }
    if (penuh)
    {
        return 'D';
    }

    // cek belum ada pemenang atau seri
    return ' ';
}

// fungsi untuk mengambil input dari pemain
int inputPemain()
{
    int pil;
    cout << "Masukkan nomor kotak yang ingin ditandai: ";
    cin >> pil;

    // validasi input
    while (pil < 1 || pil > 9 || papan[(pil-1)/3][(pil-1)%3] != ' ')
    {
        cout << "Input tidak valid. Masukkan nomor kotak yang kosong antara 1 sampai 9: ";
        cin >> pil;
    }

    return pil;
}

// fungsi untuk mengganti isi array dengan simbol pemain
void papanTanda(int pil, char simbol)
{
    papan[(pil-1)/3][(pil-1)%3] = simbol;
}

// fungsi utama untuk menjalankan permainan
int main()
{
    bool putaranX = true; // variabel untuk menentukan giliran pemain
    bool permainanBerakhir = false; // variabel untuk menentukan status permainan
    char pemenang; // variabel untuk menyimpan simbol pemenang
    char mainLagi; // variabel untuk menyimpan pilihan bermain lagi

    do
    {
        papanTampilan(); // menampilkan papan permainan
        int pil = inputPemain(); // mengambil input dari pemain
        if (putaranX) // jika giliran pemain X
        {
            papanTanda(pil, 'X'); // menandai papan dengan simbol X
            putaranX = false; // mengganti giliran ke pemain O
        }
        else // jika giliran pemain O
        {
            papanTanda(pil, 'O'); // menandai papan dengan simbol O
            putaranX = true; // mengganti giliran ke pemain X
        }
        pemenang = periksaPemenang(); // memeriksa pemenang atau seri
        if (pemenang != ' ') // jika ada pemenang atau seri
        {
            permainanBerakhir = true; // mengakhiri permainan
            papanTampilan(); // menampilkan papan permainan terakhir
            if (pemenang == 'D') // jika seri
            {
                cout << "Permainan berakhir seri!\n";
            }
            else // jika ada pemenang
            {
                cout << "Pemenangnya adalah " << pemenang << "!\n";
            }
            cout << "Apakah Anda ingin bermain lagi? (Y/N): "; // menanyakan pilihan bermain lagi
            cin >> mainLagi;
            if (mainLagi == 'Y' || mainLagi == 'y') // jika ingin bermain lagi
            {
                permainanBerakhir = false; // melanjutkan permainan
                putaranX = true; // mengembalikan giliran ke pemain X
                // mengosongkan papan permainan
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        papan[i][j] = ' ';
                    }
                }
            }
        }
    } while (!permainanBerakhir); // mengulang permainan sampai ada pemenang atau seri

    return 0;
}

