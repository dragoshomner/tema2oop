class Matrice{
protected:
    Complex **matrix;
    int lin, col;
public:

    Matrice();

    Matrice(int lin, int col);

    friend istream& operator >>(istream &in, Matrice &m);

    friend ostream& operator <<(ostream &out, const Matrice &m);

    Matrice& operator=(const Matrice &m);

    Matrice operator+(const Matrice &m);

    Matrice operator-(const Matrice &m);

    Matrice operator*(const Matrice &m);

    Complex determinant(const Matrice &m, int n);

    int getLin() {return this->lin;}

    ~Matrice() {
        cout<<"distrus matrice"<<'\n';
    }

};

Matrice::Matrice() : lin(lin), col(col){
    matrix = new Complex*[0];
}

Matrice::Matrice(int lin, int col) : lin(lin), col(col){
    matrix = new Complex*[lin];
    for(int i = 0 ; i < lin ; i++){
        matrix[i] = new Complex[col];
        for(int j = 0 ; j < col ; j++){
            Complex zero;
            matrix[i][j] = zero;
        }
    }
}

istream& operator >>(istream &in, Matrice &m){
    in>>m.lin>>m.col;

    m.matrix = new Complex*[m.lin];
    for(int i = 0 ; i < m.lin ; i++){
        m.matrix[i] = new Complex[m.col];
    }

    for(int i = 0 ; i < m.lin ; i++)
        for(int j = 0 ; j < m.col ; j++){
            in>>m.matrix[i][j];
        }
    return in;
}

ostream& operator <<(ostream &out, const Matrice &m){
    for(int i = 0 ; i < m.lin ; i++){
        for(int j = 0 ; j < m.col ; j++)
            out<<m.matrix[i][j]<<" ";
        out<<'\n';
    }
    return out;
}

Matrice& Matrice::operator=(const Matrice& m){
    if(this == &m)
        return *this;

    this->lin = m.lin;
    this->col = m.col;

    matrix = new Complex*[lin];
    for(int i = 0 ; i < lin ; i++)
        matrix[i] = new Complex[col];

    for(int i = 0 ; i < this->lin ; i++){
        for(int j = 0 ; j < this->col ; j++){
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
    return *this;
}

Matrice Matrice::operator+(const Matrice &m){
    Matrice rez(lin, col);
    for(int i = 0 ; i < lin ; i++)
        for(int j = 0 ; j < col ; j++){
            rez.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    return rez;
}

Matrice Matrice::operator-(const Matrice &m){
    Matrice rez(m.lin, m.col);
    for(int i = 0 ; i < m.lin ; i++)
        for(int j = 0 ; j < m.col ; j++)
            rez.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
    return rez;
}

Matrice Matrice::operator*(const Matrice &m){
    Matrice rez(lin, m.col);
    for(int i = 0; i < lin; ++i)
    {
        for(int j = 0; j < m.col; ++j)
        {
            for(int k = 0; k < m.col; ++k)
            {
                rez.matrix[i][j] = rez.matrix[i][j] + matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return rez;
}
