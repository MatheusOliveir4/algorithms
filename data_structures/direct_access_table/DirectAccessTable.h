#ifndef DIRECT_ACCESS_TABLE_H
#define DIRECT_ACCESS_TABLE_H

class DirectAccessTable {
private:
    int* table;
    int size;

public:
    DirectAccessTable(int n);    
    ~DirectAccessTable();         

    void insert(int k, int x);    
    int search(int k);          
    void remove(int k);      
    void print();                
};

#endif