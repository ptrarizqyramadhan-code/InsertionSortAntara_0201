#include <iostream>
using namespace std;

int arr[20]; // membuat array dengan panjang data 20
int n;       // membuat variabel n untuk input panjang array

void input() // membuat prosedur input
{
    while (true)
    {
        cout << "Masukkan Jumlah Data Pada Array : ";
        cin >> n;

        if (n <= 20)
        {
            break;
        }
        else
        {
            cout << "\nPanjang Data Maksimal 20" << endl;
        }
    }

    cout << endl;
    cout << "======================" << endl;
    cout << "Masukkan Element Array" << endl;
    cout << "======================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data ke " << i + 1 << " : ";
        cin >> arr[i];
    }
}

void insertionSort() // membuat prosedur insertion sort
{
    int temp, i, j;

    for (i = 1; i <= n - 1; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;

        cout << "\nPass " << i << " : ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
    }
}

