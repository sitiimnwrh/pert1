#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputData() {
    vector<int> data;
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Masukkan data ke-" << i+1 << ": ";
        cin >> value;
        data.push_back(value);
    }
    sort(data.begin(), data.end()); // Mengurutkan array
    return data;
}

void sequentialSearchAndUpdate(vector<int> &data, int target, int newValue) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            data[i] = newValue;
            cout << "Nilai " << target << " ditemukan dan diganti dengan " << newValue << endl;
            return; // Jika target ditemukan, keluar dari fungsi
        }
    }
    cout << "Nilai " << target << " tidak ditemukan dalam array." << endl;
}

void binarySearchAndUpdate(vector<int> &data, int target, int newValue) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            data[mid] = newValue;
            cout << "Nilai " << target << " ditemukan dan diganti dengan " << newValue << endl;
            return;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Nilai " << target << " tidak ditemukan dalam array." << endl;
}

int main() {
    vector<int> data_array = inputData();
    cout << "Data yang dimasukkan:" << endl;
    for (int i = 0; i < data_array.size(); ++i) {
        cout << data_array[i] << " ";
    }
    cout << endl;

    int choice;
    int targetValue, newValue;
    cout << "Pilih metode pencarian (1. Sequential search, 2. Binary search): ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Masukkan nilai yang ingin dicari dan diganti: ";
            cin >> targetValue;
            cout << "Diganti menjadi: ";
            cin >> newValue;
            sequentialSearchAndUpdate(data_array, targetValue, newValue);
            break;
        case 2:
            cout << "Masukkan nilai yang ingin dicari dan diganti: ";
            cin >> targetValue;
            cout << "Diganti menjadi: ";
            cin >> newValue;
            binarySearchAndUpdate(data_array, targetValue, newValue);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    cout << "Data setelah perubahan:" << endl;
    for (int i = 0; i < data_array.size(); ++i) {
        cout << data_array[i] << " ";
    }
    cout << endl;

    return 0;
}