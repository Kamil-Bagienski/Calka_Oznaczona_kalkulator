#include <iostream>
#include <string>

using namespace std;
void dane(float &a,float &b, float &c, int &poczatek, int &koniec, int &przedzial);
void pola_czastkowe(float a,float b, float c,float *tablica, int poczatek, int koniec);
float metoda_numeryczna(float a,float b, float c,float *tablica, int poczatek, int koniec);
float metoda_dokladna(float a,float b, float c, int poczatek, int koniec);
void blad(float a,float b, float c,float *tablica, int poczatek, int koniec);

int main()
{
    float a,b,c;
    int poczatek,koniec,przedzial;
    
    dane(a,b,c,poczatek,koniec,przedzial);
    float *F=new float[koniec];
    cout<<"METODA NUMERYCZNA"<<endl;
    cout<<"Calka z przedzialu od "<<poczatek<<" do "<< koniec<< " z funkcja f(x)="<<a<<"x^2+"<<b<<"x+"<<c<<" dx wynosi w przyblizeniu:"<< metoda_numeryczna(a,b,c,F,poczatek,koniec)<<endl;
    cout<<"METODA DOKLADNA"<<endl;
    cout<<"Calka z przedzialu od "<<poczatek<<" do "<< koniec<< " z funkcja f(x)="<<a<<"x^2+"<<b<<"x+"<<c<<" dx wynosi w przyblizeniu:"<< metoda_dokladna(a,b,c,poczatek,koniec)<<endl;
    blad(a,b,c,F,poczatek,koniec);

    return 0;
}

void dane(float &a,float &b, float &c, int &poczatek, int &koniec, int &przedzial)
{
    cout<<"Obliczanie calki oznaczonej ze wzoru funkcji f(x)=ax^2+bx+c"<<endl;
    cout<<"Podaj a:";
    cin>>a;
    cout<<"Podaj b:";
    cin>>b;
    cout<<"Podaj c:";
    cin>>c;
    cout<<"Podaj poczatek przedzialu calkowania:";
    cin>>poczatek;
    cout<<"Podaj koniec przedzialu calkowania:";
    cin>>koniec;
    przedzial=koniec-poczatek;
}

void pola_czastkowe(float a,float b, float c,float *tablica, int poczatek, int koniec)
{
    for(int i=poczatek; i<=koniec;i++)
    {
        tablica[i]=(a*(i*i))+(b*i)+c;
    }
}

float metoda_numeryczna(float a,float b, float c,float *tablica, int poczatek, int koniec)
{
    float suma=0.0;
    pola_czastkowe(a,b,c,tablica,poczatek,koniec);

    for(int i=poczatek; i<koniec;i++)
    {
        suma+=(tablica[i]+tablica[i+1])/2;
    }
    return suma;
}

float metoda_dokladna(float a,float b, float c, int poczatek, int koniec)
{
    return (((a*(koniec*koniec*koniec))/3)+((b*(koniec*koniec))/2)+c*4)-(((a*(poczatek*poczatek*poczatek))/3)+((b*(poczatek*poczatek))/2)+c*poczatek);
}

void blad(float a,float b, float c,float *tablica, int poczatek, int koniec)
{
    float blad_bezwgledny=0.0;
    cout<<endl;
    if(metoda_numeryczna(a,b,c,tablica,poczatek,koniec)>metoda_dokladna(a,b,c,poczatek,koniec))
    {
        blad_bezwgledny=metoda_numeryczna(a,b,c,tablica,poczatek,koniec)-metoda_dokladna(a,b,c,poczatek,koniec);
    }
    else
    {
        blad_bezwgledny=metoda_dokladna(a,b,c,poczatek,koniec)-metoda_numeryczna(a,b,c,tablica,poczatek,koniec);
    }
    cout<< "Blad bezwgledny wynosi w przyblizeniu: "<< blad_bezwgledny<<endl;

    cout<< "Blad wzgledny wynosi w przyblizeniu: "<< (blad_bezwgledny/metoda_dokladna(a,b,c,poczatek,koniec))*100<<"%"<<endl;
}