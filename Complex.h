class Complex
{
    float re, im;

    friend class Matrice;
public:

    Complex();

    Complex(float re, float im);

    friend istream& operator >>(istream &in, Complex &c);

    friend ostream& operator <<(ostream &out, const Complex &c);

    Complex(const Complex &c);

    Complex& operator=(const Complex &c);

    Complex operator+(const Complex &c);

    Complex operator-(const Complex &c);

    Complex operator*(const Complex &c);

    Complex operator*(const double nr);

    Complex operator/(const Complex &c);

    bool operator == (const Complex &c);

    ~Complex() {}
};

Complex::Complex() : re(0), im(0) {}

Complex::Complex(float re, float im) : re(re), im(im) {}

istream& operator >>(istream &in, Complex &c){
    in>>c.re>>c.im;
    return in;
}

ostream& operator <<(ostream &out, const Complex &c){
    out<<c.re<<"+"<<c.im<<"i ";
    return out;
}

Complex::Complex(const Complex &c) {
    re = c.re;
    im = c.im;
}

Complex& Complex::operator=(const Complex &c){
    if(this == &c)
        return *this;
    this->re = c.re;
    this->im = c.im;
    return *this;
}

Complex Complex::operator+(const Complex &c){
    Complex rez;
    rez.re = re + c.re;
    rez.im = im + c.im;
    return rez;
}

Complex Complex::operator-(const Complex &c){
    Complex rez;
    rez.re = re - c.re;
    rez.im = im - c.im;
    return rez;
}

Complex Complex::operator*(const Complex &c){
    Complex rez;
    rez.re = re * c.re - im * c.im;
    rez.im = re * c.im + c.re * im;
    return rez;
}

Complex Complex::operator*(const double nr){
    Complex rez;
    rez.re = nr * re;
    rez.im = nr * im;
    return rez;
}

Complex Complex::operator/(const Complex &c){
    Complex rez;
    if(c.re == 0 && c.im == 0){
        cout<<"NU e posibila impartirea la 0"<< '\n';
        return rez;
    }

    rez.re = (((re)*(c.re))+((im)*(c.im)))/(pow(c.re,2)+pow(c.im,2));
    rez.im = (((c.re)*(im))-((re)*(c.im)))/(pow(c.re,2)+pow(c.im,2));
    return rez;
}

bool Complex::operator ==(const Complex &c){
    if(re == c.re && im == c.im)
        return true;
    return false;
}
