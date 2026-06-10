#include <iostream>
using namespace std;

class BTreeNode {
    int *Kunci;
    int t;
    int n;
    bool leaf;
    BTreeNode **C;

public:
    BTreeNode(int tt, bool _leaf);

    void SisipPdkPenuh(int k);
    void splitAnak(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);

    friend class BTree;
};

class BTree {
    int t;
    BTreeNode *root;

public:
    BTree(int tt) {
        root = NULL;
        t = tt;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void Sisip(int k);
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    Kunci = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];

    n = 0;
}

void BTreeNode::traverse() {
    int i;

    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();

        cout << " " << Kunci[i];
    }

    if (leaf == false)
        C[i]->traverse();
}

BTreeNode *BTreeNode::search(int k) {
    int i = 0;

    while (i < n && k > Kunci[i])
        i++;

    if (i < n && Kunci[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

void BTree::Sisip(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->Kunci[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {

            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;
            s->splitAnak(0, root);

            int i = 0;

            if (s->Kunci[0] < k)
                i++;

            s->C[i]->SisipPdkPenuh(k);

            root = s;
        }
        else {
            root->SisipPdkPenuh(k);
        }
    }
}
void BTreeNode::SisipPdkPenuh(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && Kunci[i] > k) {
            Kunci[i + 1] = Kunci[i];
            i--;
        }

        Kunci[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && Kunci[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitAnak(i + 1, C[i + 1]);

            if (Kunci[i + 1] < k)
                i++;
        }

        C[i + 1]->SisipPdkPenuh(k);
    }
}
void BTreeNode::splitAnak(int i, BTreeNode *y) {

    BTreeNode *z = new BTreeNode(y->t, y->leaf);

    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->Kunci[j] = y->Kunci[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        Kunci[j + 1] = Kunci[j];

    Kunci[i] = y->Kunci[t - 1];

    n = n + 1;
}
int main() {

    BTree t(5);

    t.Sisip(10);
    t.Sisip(40);
    t.Sisip(20);
    t.Sisip(30);
    t.Sisip(25);

    cout << " Pohon dengan menggunakan B-TREE" << endl;
    cout << "--------------- m = 4 ----------------" << endl;
    cout << "======================================" << endl;

    t.traverse();

    cout << endl << endl;

    int k = 25;

    (t.search(k) != NULL)
        ? cout << "Kunci yang dicari " << k << " = Ditemukan"
        : cout << "Kunci yang dicari " << k << " = Tidak Ditemukan";

    cout << endl << endl;

    /*k = 15;

    (t.search(k) != NULL)
        ? cout << "Kunci yang dicari " << k << " = Ditemukan"
        : cout << "Kunci yang dicari " << k << " = Tidak Ditemukan";

    cout << endl; */

    return 0;
}