#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

void Q_Sort(int[], int, int);

int main(){
	int NumList[9] = {65,2,44,26,19,22,5,3,12};
	cout<<"Data SEBELUM diururtkan"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int d=0; d<9; d++){
		cout<<setw(3)<<NumList[d];
	}
	cout<<endl<<endl;
	Q_Sort(NumList,0,9);
	cout<<"Data SETELAH diurutkan"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int ii=0; ii<9; ii++){
		cout<<setw(3)<<NumList[ii];
	}
	cin.get();
}

void Q_Sort(int Angka[], int Kiri, int Kanan){
	int pivot, KiriHold, KananHold;
	KiriHold = Kiri;
	KananHold = Kanan;
	pivot = Angka[Kiri];
	while(Kiri < Kanan){
		while((Angka[Kanan] >= pivot) && (Kiri<Kanan)){
		Kanan--;
		}
		if(Kiri != Kanan){
			Angka[Kiri] = Angka[Kanan];
			Kiri++;
		}
		while((Angka[Kiri] <= pivot) && (Kiri<Kanan)){
			Kiri++;
		}
		if(Kiri != Kanan){
			Angka[Kanan] = Angka[Kiri];
			Kanan--;
		}
	}
	Angka[Kiri] = pivot;
	pivot = Kiri;
	Kiri = KiriHold;
	Kanan = KananHold;
	if(Kiri < pivot){
		Q_Sort(Angka, Kiri, pivot-1);
		if(Kanan > pivot){
			Q_Sort(Angka, pivot+1, Kanan);
		}
	}
}