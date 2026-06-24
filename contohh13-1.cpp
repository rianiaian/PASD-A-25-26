#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int HASHSIZE = 100;
struct HashData {
	char Kode[50];
	char Nama[100];
};
HashData* HashTable[HASHSIZE];

int CharacterAmount(char array[]){
	int jumlah = 0;
	for(int i = 0; array[i] != '\0'; i++){
		jumlah++;
	}
	return jumlah;
}

bool isIndexEmpty(int rec){
	if(HashTable[rec] == NULL){
		return true;
	}else{
		return false;
	}
}

int HashFunction(HashData *array){
	int value = 0, rec, n;
	n = CharacterAmount(array->Kode);
	
	for(int i = 0; i <= n; i++){
		value += array->Kode[i];
	}
	rec = value % HASHSIZE;
	
	return rec;
}

void Insert(HashData *array){
	int rec;
	
	rec = HashFunction(array);
	HashTable[rec] = array;
	
	cout<<"Input successfully!"<<endl;
	cout<<"Data disimpan pada record index = "<<rec<<endl;
	cin.get();
}

int SearchingProcess(HashData *Cari, int rec){
	int m, n, j = 0;
	bool equel = true;
	if(isIndexEmpty(rec) == false){
		n = CharacterAmount(Cari->Kode);
		m = CharacterAmount(HashTable[rec]->Kode);
		if(n == m){
			while((equel == true) && (Cari->Kode[j] != '\0')){
				if(tolower(Cari->Kode[j]) != tolower(HashTable[rec]->Kode[j]))
					equel = false;
				j++;
			}
			if(equel == true)
				return rec;
			else 
				return -1;
		}
		else 
			return -1;
	}
	else{
		return -1;
		cin.get();
	}
}

void Searching(HashData *Cari){
    int rec;
    
    rec = HashFunction(Cari); 
    
    rec = SearchingProcess(Cari, rec);
    if(rec >= 0){
        cout<<"Data ditemukan pada record indeks "<<rec<<endl;
        cout<<"Isi data : "<<endl;
        cout<<"=> KodeMK      : "<<HashTable[rec]->Kode<<endl;
        cout<<"=> Matakuliah  : "<<HashTable[rec]->Nama<<endl;
    }
    else {
        cout<<"Maaf! Data tidak ditemukan."<<endl;
        cin.get();
    }
}

void Deleting(HashData *Hapus){
    int rec;

    rec = HashFunction(Hapus); 
    
    rec = SearchingProcess(Hapus, rec);
    if(rec >= 0){
        cout<<"Data :"<<endl;
        cout<<"  => KodeMK      : "<<HashTable[rec]->Kode<<endl;
        cout<<"  => MataKuliah  : "<<HashTable[rec]->Nama<<endl;
        cout<<"terhapus!"<<endl;
        
        HashTable[rec] = NULL; 
    }
    else {
        cout<<"Maaf! Data tidak ditemukan!"<<endl;
        cin.get();
    }
}

void DisplayTable(){
    cout<<"\n";
    cout<<"|===================================================|"<<endl;
    cout<<"| Indeks |    KODEMK    |       Nama Mata Kuliah    |"<<endl;
    cout<<"|===================================================|"<<endl;
    for(int i = 0; i < HASHSIZE; i++)
    {
        if(isIndexEmpty(i) == false)
            cout<<setw(6)<<i<<"      "<<HashTable[i]->Kode<<"\t     "<<HashTable[i]->Nama<<endl;
    }
    cin.get();
}

void Clear(){
    for(int i = 0; i < HASHSIZE; i++)
        HashTable[i] = NULL;
}

int main(){
    char ulang = 'Y', menu;
    do{
        system("cls");
        
        puts("        PROSES HASH TABLE        ");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout<<"Menu pilihan Anda : "; cin>>menu;
        
        switch(menu){
            case '1' :
                HashData *array;
                array = new HashData;
                puts("");
                cout<<"KodeMK        : "; cin>>array->Kode;
                cout<<"Matakuliah    : "; cin>>array->Nama;
                cout<<endl;
                Insert(array); break;
            case '2' :
                HashData *hapus;
                hapus = new HashData;
                cout<<"Hapus Matakuliah(KodeMK) : "; cin>>hapus->Kode;
                Deleting(hapus); 
                cout << endl;
                system("pause"); 
				break;
            case '3' :
                HashData *cari;
                cari = new HashData;
                cout<<"Cari MataKuliah (KodeMK) : "; cin>>cari->Kode;
                Searching(cari); 
                cout << endl;
                system("pause"); 
				break;
            case '4' :
                DisplayTable(); break;
            case '5' :
                Clear();
                puts("Tabel hash telah dikosongkan."); 
                cout << endl;
                system("pause"); 
				break;
            case 'x' :
            case 'X' :
                ulang = 'T'; break;
            default :
                puts("Pilihan diluar Menu yang tersedia!"); break;
        }
        cin.get();
    }
    while(toupper(ulang) == 'Y');
    
    return 0;
}