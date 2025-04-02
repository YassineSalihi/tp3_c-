#include <iostream>
using namespace std;

const int TAILLE_FIX = 100;

class Entier {
private:
    int ensemblesEntiers[TAILLE_FIX];
    int taille;

public:
    Entier() : taille(0) {}

    void empty() {
        taille = 0;
    }

    bool is_member(int element) const {
        for (int i = 0; i < taille; i++) {
            if (ensemblesEntiers[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool add(int element) {
        if (taille >= TAILLE_FIX || is_member(element)) {
            return false;
        }
        ensemblesEntiers[taille++] = element;
        return true;
    }

    void remove(int x) {
        for (int i = 0; i < taille; i++) {
            if (ensemblesEntiers[i] == x) {
                ensemblesEntiers[i] = ensemblesEntiers[taille - 1];
                taille--;
                return;
            }
        }
    }

    void copy(const Entier &autre) {
        taille = autre.taille;
        for (int i = 0; i < taille; i++) {
            ensemblesEntiers[i] = autre.ensemblesEntiers[i];
        }
    }

    bool is_equal(const Entier &autre) const {
        if (taille != autre.taille) return false;
        for (int i = 0; i < taille; i++) {
            if (!autre.is_member(ensemblesEntiers[i])) return false;
        }
        return true;
    }

    void print() const {
        cout << "{ ";
        for (int i = 0; i < taille; i++) {
            cout << ensemblesEntiers[i] << " ";
        }
        cout << "}" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Entier A, B;

    A.add(1);
    A.add(2);
    A.add(3);
    A.print();

    A.remove(2);
    A.print();

    B.copy(A);
    cout << "B : ";
    B.print();

    cout << "A == B ? " << A.is_equal(B) << endl;

    return 0;
}
