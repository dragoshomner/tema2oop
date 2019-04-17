class Matrice_patratica : public Matrice{
public:
    Matrice_patratica() : Matrice() {}

    Matrice_patratica(int lin) : Matrice(lin, lin) {}

    Complex determinant(const Matrice_patratica &m, int n);

    bool verificaDiagonala();

    ~Matrice_patratica(){
        cout<<"distrus matrice patratica"<<'\n';
    }
};

Complex Matrice_patratica::determinant(const Matrice_patratica &m, int n) {

    Complex det;
    Matrice_patratica submatrix(n);
    if (n == 2)
        return ((m.matrix[0][0] * m.matrix[1][1]) - (m.matrix[1][0] * m.matrix[0][1]));
    else {
      for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
               int subj = 0;
               for (int j = 0; j < n; j++) {
                  if (j == x)
                  continue;
                  submatrix.matrix[subi][subj] = m.matrix[i][j];
                  subj++;
               }
               subi++;
            }
            det = det + ( m.matrix[0][x] * determinant( submatrix , n - 1 ) * pow(-1, x));
      }
    }
    return det;
}

bool Matrice_patratica::verificaDiagonala(){
    Complex zero;
    for(int i = 0 ; i < lin ; i++){
        for(int j = 0 ; j < lin ; j++){
            if(i != j &&  matrix[i][j] == zero)
                return false;
        }
    }
    return true;
}
