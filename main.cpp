#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;
    ifstream f("data.in");
    ofstream g("data.out");

#include "Complex.h"
#include "Matrice.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"

int main()
{
    Matrice_patratica m1, m2, m3;

    f>>m1;

    cout<<m1.verificaDiagonala();

    return 0;
}
