#include <iostream>
#include <cmath>
using namespace std;

class Cercle {
private:
    double rayon;
    double x, y; // coordonnées du centre

public:
    // Constructeur
    Cercle(double r = 1.0, double cx = 0.0, double cy = 0.0) {
        rayon = r;
        x = cx;
        y = cy;
    }

    // Obtenir le rayon
    double getRayon() const {
        return rayon;
    }

    // Changer le rayon
    void setRayon(double r) {
        if (r > 0) {
            rayon = r;
        }
    }

    // Obtenir le centre
    void getCentre(double &cx, double &cy) const {
        cx = x;
        cy = y;
    }

    // Translation du centre
    void translater(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Calcul de la surface
    double surface() const {
        return M_PI * rayon * rayon;
    }

    // Calcul du périmètre
    double perimetre() const {
        return 2 * M_PI * rayon;
    }

    // Vérification si un point appartient au cercle
    bool contient(double px, double py) const {
        double distance = sqrt((px - x) * (px - x) + (py - y) * (py - y));
        return distance <= rayon;
    }

    // Test d'égalité avec un autre cercle
    bool estEgal(const Cercle &autre) const {
        return (rayon == autre.rayon && x == autre.x && y == autre.y);
    }

    // Affichage
    void affiche() const {
        cout << "Cercle : rayon = " << rayon << ", centre = (" << x << ", " << y << ")" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Cercle c1(1.0, 10.0, 10.0);
    c1.affiche();

    // Affichage périmètre et surface
    cout << "Périmètre : " << c1.perimetre() << endl;
    cout << "Surface : " << c1.surface() << endl;

    // Doublement du rayon
    c1.setRayon(c1.getRayon() * 2);
    cout << "\nAprès doublement du rayon : " << endl;
    cout << "Nouveau périmètre : " << c1.perimetre() << endl;
    cout << "Nouvelle surface : " << c1.surface() << endl;

    // Déplacement du cercle à l’origine
    c1.translater(-10.0, -10.0); // ramène le centre à (0,0)
    c1.affiche();

    // Vérification des points
    cout << "(1,1) est dans le cercle ? " << (c1.contient(1, 1) ? "Oui" : "Non") << endl;
    cout << "(3,3) est dans le cercle ? " << (c1.contient(3, 3) ? "Oui" : "Non") << endl;

    // Test d'égalité avec un autre cercle
    Cercle c2(2.0, 0.0, 0.0);
    cout << "Cercle c1 == c2 ? " << (c1.estEgal(c2) ? "Oui" : "Non") << endl;
    return 0;
}
