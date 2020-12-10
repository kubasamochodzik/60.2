#include <iostream>

#include <fstream>

using namespace std;

int main()

{

    fstream plik, wynik;

    plik.open("liczby.txt", ios::in);

    wynik.open("wyniki.txt", ios::out | ios::trunc);

    wynik << "60.1" << endl;

    wynik << "Ilosc liczb mniejszych od 1000: ";

    int x[200], licz = 0;

    for (int i = 0; i < 200; i++)

    {

        plik >> x[i];

        if (x[i] < 1000)
            licz++;
    }

    wynik << licz << endl;

    wynik << "Dwie ostatnie liczby w pliku: ";

    wynik << x[199] << " ";

    int nr_tab = 198;

    while (x[nr_tab] == x[199])

    {

        nr_tab--;

        if (nr_tab < 0)
            break;
    }

    if (nr_tab > 0)
        wynik << x[nr_tab] << endl;

    wynik << 60.2 << endl;

    wynik << "Liczby majace dokladnie 18 dzielnikow naturalnych:" << endl;

    int dziel[18];

    for (int i = 0; i < 200; i++)

    {

        licz = 0;

        for (int j = 1; j <= x[i]; j++)

        {

            if (x[i] % j == 0)

            {

                dziel[licz] = j;

                licz++;

                if (licz > 18)
                    break;
            }
        }

        if (licz == 18)

        {

            wynik << x[i] << " (dzielniki: ";

            for (int k = 0; k < 18; k++)

            {

                if (k == 17)
                    wynik << dziel[k];

                else
                    wynik << dziel[k] << " ";
            }

            wynik << ")" << endl;
        }
    }

    wynik.close();

    plik.close();
}
