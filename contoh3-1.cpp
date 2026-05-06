#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} NilaiMK;

typedef struct elm *alamatelml;
typedef struct elm {
	NilaiMK Kontainer;
	alamatelml next;
} elemen;

typedef struct{
	elemen* top;
} stack;

void buatSTkosong(stack *S){
	(*S).top = NULL;
}

int isKosong(stack S){
	bool hasil = false;
	if(S.top == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlElemen(stack S){
	int hasil = 0;
	if(S.top != NULL){
		elemen *bantu;
		bantu = S.top;
		
		while(bantu != NULL){
			hasil = hasil + 1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *S){
	elemen *info;
	info = new elemen;
	info -> Kontainer.npm = npm;
	info -> Kontainer.nama_mhs = nama_mhs;
	info -> Kontainer.nilai = nilai;
	
	if((*S).top == NULL){
		cout<<"Stack Penuh"<<endl;
		info -> next = NULL;
	} else {
		info -> next = (*S).top;
	}
	(*S).top = info;
	info = NULL;
}

void pop(stack *S){
	if((*S).top != NULL){
		elemen *hapus = (*S).top;
		
		if(jmlElemen(*S) == 1){
			(*S).top = NULL;
		}else {
			(*S).top = (*S).top -> next;
		}
		hapus -> next = NULL;
		delete hapus;
	}else {
		cout<<"Stack Kosong"<<endl;
	}
}

void CetakStack(stack S){
	if(S.top != NULL){
		cout<<" MENAMPILKAN STACK "<<endl;
		elemen *bantu = S.top;
		int i = 1;
		while(bantu != NULL){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke                    : "<< i <<endl;
			cout<<"Nomor Pokok Mahasiswa        : "<<bantu -> Kontainer.npm<<endl;
			cout<<"Nama Mahasiswa               : "<<bantu -> Kontainer.nama_mhs<<endl;
			cout<<"Nilai Mahasiswa              : "<<bantu -> Kontainer.nilai<<endl;
			bantu = bantu -> next;
			i = i + 1;
		}
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}else {
		cout<<"Stack Kosong"<<endl;
	}
}

int main(){
	stack S;
	
	buatSTkosong(&S);
	CetakStack(S);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	push("4525210001", "Adit", 90.65, &S);
	push("4525210002", "Adrian", 90.65, &S);
	push("45252100034", "Daffa", 90.65, &S);
	push("45252100054", "Addam", 90.65, &S);
	push("45252100065", "Karel", 90.65, &S);
	push("45252100076", "Kevin", 90.65, &S);
	push("45252100087", "Dominukus", 90.65, &S);
	CetakStack(S);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<endl;
	cout<<endl;
	pop(&S);
	CetakStack(S);
	cout<<endl;
	cout<<endl;
	pop(&S);
	CetakStack(S);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	return 0;
}