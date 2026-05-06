#include <iostream>
using namespace std;

//ian => Panggilan dari Adrian

typedef struct {
    string ianNPM;
    string ianNama_mhs;
    double ianNilai;
} ianNilaiMK;

typedef struct {
    int ianFirst;
    int ianLast;
    ianNilaiMK Dat[10];
} ianQueue; 

void ianQUKosong(ianQueue *Q) {
    (*Q).ianFirst = -1;
    (*Q).ianLast = -1;
}

bool ianIsKosong(ianQueue Q) {
    bool ianHasil = false;
    if(Q.ianFirst == -1) {
        ianHasil = true;
    }
    return ianHasil;
}

bool ianIsPenuh(ianQueue Q) {
    bool ianHasil = false;
    if(Q.ianLast == 9) {
        ianHasil = true;
    }
    return ianHasil;
}

void ianADD(string ianNPM, string ianNama_mhs, double ianNilai, ianQueue *Q) {
    if(ianIsKosong(*Q) == 1) {
        (*Q).ianFirst = 0;
        (*Q).ianLast = 0;
        (*Q).Dat[0].ianNPM = ianNPM;
        (*Q).Dat[0].ianNama_mhs = ianNama_mhs;
        (*Q).Dat[0].ianNilai = ianNilai;
    }
    else {
        if(ianIsPenuh(*Q) != 1) {
            (*Q).ianLast = (*Q).ianLast + 1;
            (*Q).Dat[(*Q).ianLast].ianNPM = ianNPM;
            (*Q).Dat[(*Q).ianLast].ianNama_mhs = ianNama_mhs;
            (*Q).Dat[(*Q).ianLast].ianNilai = ianNilai;
        }
        else {
            cout << "Queue PENUH" << endl;
        }
    }
}

void ianDEL(ianQueue *Q) {
    if((*Q).ianLast == 0) {
        (*Q).ianFirst = -1;
        (*Q).ianLast = -1;
    }
    else {
        int i;
        for(i=((*Q).ianFirst + 1); i <= (*Q).ianLast; i++) {
            (*Q).Dat[i-1].ianNPM = (*Q).Dat[i].ianNPM;
            (*Q).Dat[i-1].ianNama_mhs = (*Q).Dat[i].ianNama_mhs;
            (*Q).Dat[i-1].ianNilai = (*Q).Dat[i].ianNilai;
        }
        (*Q).ianLast = (*Q).ianLast - 1;
    }
}

void ianCetakQueue(ianQueue Q)
{
    if(Q.ianFirst != -1)
    {
        cout << " MENAMPILKAN QUEUE " << endl;
        cout << " ~~~~~~~~~~~~~~~~ " << endl;
        int i;
        for(i=Q.ianLast; i>=Q.ianFirst; i--)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke             : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << Q.Dat[i].ianNPM << endl;
            cout << "Nama Mahasiswa        : " << Q.Dat[i].ianNama_mhs << endl;
            cout << "Nilai Mahasiswa       : " << Q.Dat[i].ianNilai << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else
    {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    ianQueue Q; 
    ianQUKosong(&Q);
    ianCetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    ianADD("4523210666", "Domi", 88.75, &Q);
    ianADD("4523210777", "Juki", 78.85, &Q);
    ianADD("4523210888", "Bagas", 98.65, &Q);
    ianADD("4523210999", "Adam", 68.55, &Q);
    ianADD("4523210555", "LuwakMAN", 78.85, &Q);
    ianADD("4523210444", "Gradagralik", 98.65, &Q);
    ianADD("4523210222", "Ganendrotoz", 68.55, &Q);
    ianCetakQueue(Q);
    cout << "======================" << endl;
    cout << endl;
    cout << endl;
    ianDEL(&Q);
    ianCetakQueue(Q);
    cout << endl;
    cout << endl;
    ianDEL(&Q);
    ianCetakQueue(Q);
    cout << "======================" << endl;
    return 0;
}