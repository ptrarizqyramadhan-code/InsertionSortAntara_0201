#include <iostream>
#include <cstdlib>
using namespace std;

int n;        // Menyimpan jumlah elemen aktif yang diinput user
int arr[20];  // Array statis langsung dipesan dengan kapasitas maksimal 20 elemen

void inputData(int arr[], int &n)
{
    cout << " ***********************************************" << endl;
    cout << " *         PENERAPAN ALGORITMA SHELL SORT      *" << endl;
    cout << " *                 UMY 165                     *" << endl;
    cout << " ***********************************************" << endl;
    cout << endl;

    cout << " Masukkan panjang array: ";
    cin >> n;

    if (n > 20)
    {
        cout << " element tidak boleh melebihi 20" << endl;
        exit(0);
    }

    cout << " Masukkan " << n << " Data yang akan diurutkan :\n";
    for (int i = 0; i < n; i++)
    {
        cout << " Data ke-" << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << endl;
}

void outputdata(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << "[" << arr[i] << "]";
    }
    cout << endl;
}

void shellSort(int arr[], int n)
{
    // membuat fungsi shellSort dengan parameter array arr dan ukuran n
    int t; // membuat variabel t untuk menyimpan data sementara saat proses pertukaran (swap)

    for (int i = n / 2; i > 0; i = i / 2)
    {
        // 1. looping luar untuk menentukan jarak gap, dimulai dari n/2 lalu dibagi 2 disetiap langkahnya hingga gap = 0

        for (int j = i; j < n; j++)
        {
            // 2. looping untuk menyisir elemen array dimulai dari indeks gap (i) hingga akhir array (n-1)

            for (int k = j - i; k >= 0; k -= i)
            {
                // 3. looping dalam untuk membandingkan elemen yang berjarak sejauh gap (i) ke arah kiri

                if (arr[k + i] >= arr[k])
                {
                    // 4. pengecekan jika elemen kanan (arr[k+i]) sudah lebih besar atau sama dengan elemen kiri (arr[k])

                    break;
                    // 4a. jika benar sudah berurutan, hentikan looping (break)
                }
                else
                {
                    // 5. jika elemen kanan lebih kecil, maka lakukan penukaran posisi (swap)

                    t = arr[k];          // 5a. simpan elemen kiri ke variabel penampung sementara t
                    arr[k] = arr[k + i]; // 5b. pindahkan nilai elemen kanan ke posisi elemen kiri
                    arr[k + i] = t;      // 5c. pindahkan nilai sementara t ke posisi elemen kanan
                }
            }
        }

        cout << " Perulangan Shell Sort (Gap " << i << ") : ";
        // untuk menampilkan informasi langkah pengulangan berdasarkan nilai gap aktif (i)

        outputdata(arr, n);
        // memanggil prosedur outputdata untuk menampilkan hasil susunan angka pada gap ke-i
    }
}

