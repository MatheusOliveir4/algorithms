#include "DirectAccessTable.h"
#include <bits/stdc++.h>
using namespace std;

DirectAccessTable::DirectAccessTable(int n) {
    size = n;
    table = new int[size];

    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
}

DirectAccessTable::~DirectAccessTable() {
    delete[] table;
}

void DirectAccessTable::insert(int k, int x) {
    if (k < 0 || k >= size) {
        cerr << "Erro: índice fora do intervalo.\n";
        return;
    }

    table[k] = x;
}

int DirectAccessTable::search(int k) {
    if (k < 0 || k >= size) {
        cerr << "Erro: índice fora do intervalo.\n";
        return -1;
    }

    return table[k];
}

void DirectAccessTable::remove(int k) {
    if (k < 0 || k >= size) {
        cerr << "Erro: índice fora do intervalo.\n";
        return;
    }
    
    table[k] = -1;
}

void DirectAccessTable::print() {
    for (int i = 0; i < size; i++) {
        cout << table[i] << endl;
    }
}

int DirectAccessTable::maxElement() {
    int max = table[0];
    
    for (int i = 0; i < size; i++)
    {
        if (table[i] > max) {
            max = table[i];
        }
    }
    
    return max;
}

int main() {
    int n = 5;
    
    int k = 2;
    int x = 1000;

    DirectAccessTable T(n);

    T.insert(k, x);

    T.print();    
    cout << T.maxElement() << endl;

    return 0;
}