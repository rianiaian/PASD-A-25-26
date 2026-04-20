#include <iostream>
#include <string>
using namespace std;

int main() {
	struct MATAKULIAH {
		string nama;
		int sks;
		char nHuruf;
		float nAngka;
	};
	MATAKULIAH Data_MK;
	
	Data_MK.nama = "Algoritma dan Pemrograman 2";
	Data_MK.sks = 3;
	Data_MK.nHuruf =  'A';
	Data_MK.nAngka = 4.00;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Mata Kuliah    = "<<Data_MK.nama<<endl;
	cout<<"Jumlah SKS     = "<<Data_MK.sks<<endl;
	cout<<"Nilai          = "<<Data_MK.nHuruf<<endl;
	cout<<"Indeks         = "<<Data_MK.nAngka<<endl;
	cin.get();
}