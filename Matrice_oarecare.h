class Matrice_oarecare : public Matrice{
public:
    Matrice_oarecare();

    Matrice_oarecare(int lin, int col);

    ~Matrice_oarecare() {
        cout<<"distrus matrice oarecare"<<'\n';
    }
};

Matrice_oarecare::Matrice_oarecare() : Matrice() {}

Matrice_oarecare::Matrice_oarecare(int lin, int col) : Matrice(lin, col) {}



