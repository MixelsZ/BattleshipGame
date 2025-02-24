#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include<locale.h>
#include<time.h>

using namespace std;

string tablica_gracza2[12][12];
string tablica_gracza[12][12];
string tablica_gracza2_z[12][12];
string tablica_gracza_z[12][12];


string nick;
string nick2;


void wyswietl_tablice_gracza()
{

	cout << "tablica "<<nick << endl;
	cout << "x->1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i = 1; i<11; i++)//wyswietlenie tablicy
	{
        if(i==10){
          cout<<i;
        }
        else{
            cout<<i<<" ";
        }

		for(int c = 1; c<11; c++)
		{

			cout << tablica_gracza[c][i];
		}
		cout << endl;
	}
}
void wyswietl_tablice_gracza_z()
{
	cout << "plansza trafien "<<nick<<" w statki "<<nick2 << endl;
	cout << "x->1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i = 1; i<11; i++)//wyswietlenie tablicy
	{
        if(i==10){
          cout<<i;
        }
        else{
            cout<<i<<" ";
        }

		for(int c = 1; c<11; c++)
		{

			cout << tablica_gracza_z[c][i];
		}
		cout << endl;
	}
}
void wyswietl_tablice_gracza2_z()
{
	cout << "plansza trafień "<<nick2<<" w statki " << nick << endl;
	cout << "x->1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i = 1; i<11; i++)//wyswietlenie tablicy
	{
        if(i==10){
          cout<<i;
        }
        else{
            cout<<i<<" ";
        }

		for(int c = 1; c<11; c++)
		{

			cout << tablica_gracza2_z[c][i];
		}
		cout << endl;
	}
}
void wczytywanie_jednomasztowcow()
{

    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
	for(int i = 0; i<4; i++)
	{


		cout << "Wprowadź wspołrzędne jednomasztowca: " << endl;
		cout<<"podaj x: ";
		int x;
		cin >> x;
        cout << "podaj y: ";
		int y;
		cin >> y;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
        cout << "Nie wpisałeś liczby spróbuj ponownie "<<endl;
        SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;
}
		system( "cls" );//czyszczenie ekranu

		if( tablica_gracza[x][y]   == " #" ||
            tablica_gracza[x+1][y] == " #" ||
            tablica_gracza[x-1][y] == " #" ||
            tablica_gracza[x][y+1] == " #" ||
            tablica_gracza[x][y-1] == " #" ){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Tam nie możesz ustawić statku!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }

            else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
		else {
            tablica_gracza[x][y] = " #";

		}
        wyswietl_tablice_gracza();
		}

	}
void wczytywanie_dwumasztowcow()
{

	for (int i = 0; i<3; i++)
	{
	    HANDLE kolor; //kolory
        kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
		cout << "Wprowadź wspołrzędne dwumasztowca: " << endl << "podaj x: ";
		int x;
		cin >> x;

		cout << "podaj y: ";
		int y;
		cin >> y;

		cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
		string kierunek;
		cin >> kierunek;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisałeś liczby spróbuj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;

        cout << "podaj y: ";
		cin >> y;
		}

		system( "cls" );//czyszczenie ekranu
		if( tablica_gracza[x][y]   == " #" ||
            tablica_gracza[x+1][y] == " #" ||
            tablica_gracza[x-1][y] == " #" ||
            tablica_gracza[x][y+1] == " #" ||
            tablica_gracza[x][y-1] == " #" ){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony

            cout<<"Tam nie możesz ustawić statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		    else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }






        else if (kierunek == "g")
		{
		    if(tablica_gracza[x-1][y-1] == " #" ||
            tablica_gracza[x+1][y-1] == " #" ||
            tablica_gracza[x][y-2] == " #" )
            {
            i--;

            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie możesz ustawić statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
            else if(y-1 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie możesz ustawić statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
            else{

            tablica_gracza[x][y] = " #";
			tablica_gracza[x][y-1] = " #";


            }
		}
		else if (kierunek == "d")
		{
		    if(tablica_gracza[x-1][y+1] == " #" ||
            tablica_gracza[x+1][y+1] == " #" ||
            tablica_gracza[x][y+2] == " #" )
            {
            i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie możesz ustawić statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy


		}
		else if(y+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza[x][y] = " #";
			tablica_gracza[x][y+1] = " #";

		}
		}
		else if (kierunek == "p")
		{
		    if(tablica_gracza[x+2][y] == " #" ||
            tablica_gracza[x+1][y-1] == " #" ||
            tablica_gracza[x+1][y+1] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }

            else{

            tablica_gracza[x][y] = " #";
			tablica_gracza[x+1][y] = " #";

		}
		}
		else if (kierunek == "l")
		{ if(tablica_gracza[x-1][y-1] == " #" ||
            tablica_gracza[x-1][y+1] == " #" ||
            tablica_gracza[x-2][y] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-1 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza[x][y] = " #";
			tablica_gracza[x-1][y] = " #";


		}

		}

		else{
            cout<<"Nie wpisales zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
		}


		wyswietl_tablice_gracza();
	}
}
void wczytywanie_trzymasztowcow()
{

    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
	for (int i = 0;i<2;i++)
	{
		cout << "Wprowadz wspolrzedne trzymasztowca: " << endl << "podaj x: ";
		int x;
		cin >> x;

		cout << "podaj y: ";
		int y;
		cin >> y;

		cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
		string kierunek;
		cin >> kierunek;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales liczby sprobuj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;

        cout << "podaj y: ";
		cin >> y;}
		system( "cls" );//czyszczenie ekranu
		if( tablica_gracza[x][y]   == " #" ||
            tablica_gracza[x+1][y] == " #" ||
            tablica_gracza[x-1][y] == " #" ||
            tablica_gracza[x][y+1] == " #" ||
            tablica_gracza[x][y-1] == " #" ){
             SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		    else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }

		else if (kierunek == "g")
		{
		    if(tablica_gracza[x-1][y-1] == " #" ||
            tablica_gracza[x-1][y-2] == " #" ||
            tablica_gracza[x][y-2] == " #" ||
            tablica_gracza[x][y-3] == " #" ||
            tablica_gracza[x+1][y-2] == " #" ||
            tablica_gracza[x+1][y-1] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y-2 < 0 || y-1 < 0){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{
            tablica_gracza[x][y] = " #";
			tablica_gracza[x][y-1] = " #";
			tablica_gracza[x][y-2] = " #";

		}
		}


		else if (kierunek == "d")
		{
			if(tablica_gracza[x-1][y+1] == " #" ||
            tablica_gracza[x-1][y+2] == " #" ||
            tablica_gracza[x][y+2] == " #" ||
            tablica_gracza[x][y+3] == " #" ||
            tablica_gracza[x+1][y+2] == " #" ||
            tablica_gracza[x+1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y+2 > 10 || y+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{
            tablica_gracza[x][y] = " #";
			tablica_gracza[x][y+1] = " #";
			tablica_gracza[x][y+2] = " #";

		}
		}
		else if (kierunek == "p")
		{
			if(tablica_gracza[x+3][y] == " #" ||
                tablica_gracza[x+2][y] == " #" ||
                tablica_gracza[x+2][y-1] == " #" ||
                tablica_gracza[x+2][y+1] == " #" ||
                tablica_gracza[x+1][y-1] == " #" ||
                tablica_gracza[x+1][y+1] == " #" )
            {
			 i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+2 > 10 || x+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza[x][y] = " #";
			tablica_gracza[x+1][y] = " #";
			tablica_gracza[x+2][y] = " #";

		}
		}
		else if (kierunek == "l")
		{
		    if(tablica_gracza[x-3][y] == " #" ||
                tablica_gracza[x-2][y] == " #" ||
                tablica_gracza[x-2][y-1] == " #" ||
                tablica_gracza[x-2][y+1] == " #" ||
                tablica_gracza[x-1][y-1] == " #" ||
                tablica_gracza[x-1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-2 < 1 || x-1 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }

			else{
            tablica_gracza[x][y] = " #";
			tablica_gracza[x-1][y] = " #";
			tablica_gracza[x-2][y] = " #";

		}
		}

	else{
            cout<<"Nie wpisales zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
		}
		wyswietl_tablice_gracza();
	}
}
void wczytaj_czteromasztowca()
{
    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
    wyswietl_tablice_gracza();
    for(int i = 0; i<1; i++){
	cout << "Wprowadz wspolrzedne czteromasztowca: " << endl << "podaj x: ";
	int x;
	cin >> x;

	cout << "podaj y: ";
	int y;
	cin >> y;

	cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
	string kierunek;
	cin >> kierunek;
	while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do tysiąca znaków chyba, że napotka koniec
        cout << "Nie wpisales liczby sprobuj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
	system( "cls" );//czyszczenie ekranu

	if( tablica_gracza[x][y]   == " #" ||
            tablica_gracza[x+1][y] == " #" ||
            tablica_gracza[x-1][y] == " #" ||
            tablica_gracza[x][y+1] == " #" ||
            tablica_gracza[x][y-1] == " #" ){
             SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		   else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }

    else if (kierunek == "g")
	{

		    if(tablica_gracza[x-1][y-1] == " #" ||
            tablica_gracza[x-1][y-2] == " #" ||
            tablica_gracza[x-1][y-3] == " #" ||
            tablica_gracza[x][y-2] == " #" ||
            tablica_gracza[x][y-3] == " #" ||
            tablica_gracza[x][y-4] == " #" ||
            tablica_gracza[x+1][y-1] == " #" ||
            tablica_gracza[x+1][y-2] == " #" ||
            tablica_gracza[x+1][y-3] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y-3 < 1){
            i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else{
        tablica_gracza[x][y] = " #";
		tablica_gracza[x][y-1] = " #";
		tablica_gracza[x][y-2] = " #";
		tablica_gracza[x][y-3] = " #";
		}

	}
	else if (kierunek == "d")
	{
	    if(tablica_gracza[x-1][y+1] == " #" ||
            tablica_gracza[x-1][y+2] == " #" ||
            tablica_gracza[x-1][y+3] == " #" ||
            tablica_gracza[x][y+2] == " #" ||
            tablica_gracza[x][y+3] == " #" ||
            tablica_gracza[x][y+4] == " #" ||
            tablica_gracza[x+1][y+1] == " #" ||
            tablica_gracza[x+1][y+2] == " #" ||
            tablica_gracza[x+1][y+3] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y+3 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
            else{
		tablica_gracza[x][y] = " #";
		tablica_gracza[x][y+1] = " #";
		tablica_gracza[x][y+2] = " #";
		tablica_gracza[x][y+3] = " #";
	}
	}
	else if (kierunek == "p")
	{
	    if(tablica_gracza[x+2][y] == " #" ||
                tablica_gracza[x+3][y] == " #" ||
                tablica_gracza[x+4][y] == " #" ||
                tablica_gracza[x+3][y-1] == " #" ||
                tablica_gracza[x+3][y+1] == " #" ||
                tablica_gracza[x+2][y-1] == " #" ||
                tablica_gracza[x+2][y+1] == " #" ||
                tablica_gracza[x+1][y-1] == " #" ||
                tablica_gracza[x+1][y+1] == " #" )
            {
			 i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+2 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
            else{
          tablica_gracza[x][y] = " #";
		tablica_gracza[x+1][y] = " #";
		tablica_gracza[x+2][y] = " #";
		tablica_gracza[x+3][y] = " #";
	}
	}
	else if (kierunek == "l")
	{
	    if(     tablica_gracza[x-4][y] == " #" ||
                tablica_gracza[x-3][y] == " #" ||
                tablica_gracza[x-2][y] == " #" ||
                tablica_gracza[x-3][y-1] == " #" ||
                tablica_gracza[x-3][y+1] == " #" ||
                tablica_gracza[x-2][y-1] == " #" ||
                tablica_gracza[x-2][y+1] == " #" ||
                tablica_gracza[x-1][y-1] == " #" ||
                tablica_gracza[x-1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-3 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
        else{
		tablica_gracza[x][y] = " #";
		tablica_gracza[x-1][y] = " #";
		tablica_gracza[x-2][y] = " #";
		tablica_gracza[x-3][y] = " #";
	}
		}

    else{
            cout<<"Nie wpisales/as zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
    }

	wyswietl_tablice_gracza();

}
}
void wyswietl_tablice_gracza2()
{
    setlocale(LC_CTYPE, "Polish");
	cout <<"tablica "<<nick2 << endl;
	cout << "x->1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i = 1; i<11; i++)//wyswietlenie tablicy
	{
        if(i==10){
          cout<<i;
        }
        else{
            cout<<i<<" ";
        }

		for(int c = 1; c<11; c++)
		{

			cout << tablica_gracza2[c][i];
		}
		cout << endl;
	}
}
void wczytywanie_jednomasztowcow2()
{
    setlocale(LC_CTYPE, "Polish");
    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory

	for(int i = 0; i<4; i++)
	{
		cout << "Wprowadz wspolrzedne jednomasztowca: " << endl << "podaj x: ";
		int x;
		cin >> x;
		cout << "podaj y: ";
		int y;
		cin >> y;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza2();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales/as liczby sproboj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
		system( "cls" );//czyszczenie ekranu

		if( tablica_gracza2[x][y]   == " #" ||
            tablica_gracza2[x+1][y] == " #" ||
            tablica_gracza2[x-1][y] == " #" ||
            tablica_gracza2[x][y+1] == " #" ||
            tablica_gracza2[x][y-1] == " #" ){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
            else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
		else {
            tablica_gracza2[x][y] = " #";

		}
        wyswietl_tablice_gracza2();
		}

	}
void wczytywanie_dwumasztowcow2()
{
    setlocale(LC_CTYPE, "Polish");
	for (int i = 0; i<3; i++)
	{
	    HANDLE kolor; //kolory
        kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
		cout << "Wprowadz wspolrzedne dwumasztowca: " << endl << "podaj x: ";
		int x;
		cin >> x;
		cout << "podaj y: ";
		int y;
		cin >> y;
		cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
		string kierunek;
		cin >> kierunek;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza2();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales/as liczby sproboj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
		system( "cls" );//czyszczenie ekranu
		if( tablica_gracza2[x][y]   == " #" ||
            tablica_gracza2[x+1][y] == " #" ||
            tablica_gracza2[x-1][y] == " #" ||
            tablica_gracza2[x][y+1] == " #" ||
            tablica_gracza2[x][y-1] == " #" ){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony

            cout<<"Tam nie mozesz ustawic statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		    else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }





		else if( kierunek == "g" || kierunek == "p" || kierunek == "l" || kierunek == "d") {
            if (kierunek == "g")
		{
		    if(tablica_gracza2[x-1][y-1] == " #" ||
            tablica_gracza2[x+1][y-1] == " #" ||
            tablica_gracza2[x][y-2] == " #" )
            {
            i--;

            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
            else if(y-1 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
            else{

            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x][y-1] = " #";


            }
		}
		else if (kierunek == "d")
		{
		    if(tablica_gracza2[x-1][y+1] == " #" ||
            tablica_gracza2[x+1][y+1] == " #" ||
            tablica_gracza2[x][y+2] == " #" )
            {
            i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy


		}
		else if(y+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x][y+1] = " #";

		}
		}
		else if (kierunek == "p")
		{
		    if(tablica_gracza2[x+2][y] == " #" ||
            tablica_gracza2[x+1][y-1] == " #" ||
            tablica_gracza2[x+1][y-1] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+1 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }

            else{

            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x+1][y] = " #";

		}
		}
		else if (kierunek == "l")
		{ if(tablica_gracza2[x-1][y-1] == " #" ||
            tablica_gracza2[x-1][y+1] == " #" ||
            tablica_gracza2[x-2][y] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-1 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x-1][y] = " #";


		}
		}
		}
        else{
            cout<<"Nie wpisales/as zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
		}
		wyswietl_tablice_gracza2();
	}
}
void wczytywanie_trzymasztowcow2()
{
    setlocale(LC_CTYPE, "Polish");
    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
	for (int i = 0;i<2;i++)
	{
		cout << "Wprowadz wspolrzedne trzymasztowca: " << endl << "podaj x: ";
		int x;
		cin >> x;
		cout << "podaj y: ";
		int y;
		cin >> y;
		cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
		string kierunek;
		cin >> kierunek;
		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza2();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales/as liczby sproboj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
		system( "cls" );//czyszczenie ekranu
		if( tablica_gracza2[x][y]   == " #" ||
            tablica_gracza2[x+1][y] == " #" ||
            tablica_gracza2[x-1][y] == " #" ||
            tablica_gracza2[x][y+1] == " #" ||
            tablica_gracza2[x][y-1] == " #" ){
             SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		    else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
		else if( kierunek == "g" || kierunek == "p" || kierunek == "l" || kierunek == "d") {
		if (kierunek == "g")
		{
		    if(tablica_gracza2[x-1][y-1] == " #" ||
            tablica_gracza2[x-1][y-2] == " #" ||
            tablica_gracza2[x][y-2] == " #" ||
            tablica_gracza2[x][y-3] == " #" ||
            tablica_gracza2[x+1][y-2] == " #" ||
            tablica_gracza2[x+1][y-1] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y-2 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{
            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x][y-1] = " #";
			tablica_gracza2[x][y-2] = " #";

		}
		}


		else if (kierunek == "d")
		{
			if(tablica_gracza2[x-1][y+1] == " #" ||
            tablica_gracza2[x-1][y+2] == " #" ||
            tablica_gracza2[x][y+2] == " #" ||
            tablica_gracza2[x][y+3] == " #" ||
            tablica_gracza2[x+1][y+2] == " #" ||
            tablica_gracza2[x+1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y+2 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{
            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x][y+1] = " #";
			tablica_gracza2[x][y+2] = " #";

		}
		}
		else if (kierunek == "p")
		{
			if(tablica_gracza2[x+3][y] == " #" ||
                tablica_gracza2[x+2][y] == " #" ||
                tablica_gracza2[x+2][y-1] == " #" ||
                tablica_gracza2[x+2][y+1] == " #" ||
                tablica_gracza2[x+1][y-1] == " #" ||
                tablica_gracza2[x+1][y+1] == " #" )
            {
			 i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+2 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
		else{

            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x+1][y] = " #";
			tablica_gracza2[x+2][y] = " #";

		}
		}
		else if (kierunek == "l")
		{
		    if(tablica_gracza2[x-3][y] == " #" ||
                tablica_gracza2[x-2][y] == " #" ||
                tablica_gracza2[x-2][y-1] == " #" ||
                tablica_gracza2[x-2][y+1] == " #" ||
                tablica_gracza2[x-1][y-1] == " #" ||
                tablica_gracza2[x-1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-2 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }

			else{
            tablica_gracza2[x][y] = " #";
			tablica_gracza2[x-1][y] = " #";
			tablica_gracza2[x-2][y] = " #";

		}
		}
	}
	else{
            cout<<"Nie wpisales/as zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
		}
		wyswietl_tablice_gracza2();
	}
}
void wczytaj_czteromasztowca2()
{
    setlocale(LC_CTYPE, "Polish");
    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
    wyswietl_tablice_gracza2();
    for(int i = 0; i<1; i++){
	cout << "Wprowadz wspolrzedne czteromasztowca: " << endl << "podaj x: ";
	int x;
	cin >> x;
	cout << "podaj y: ";
	int y;
	cin >> y;
	cout << "Podaj kierunek gora/dol/prawo/lewo (g/d/p/l): ";
	string kierunek;
	cin >> kierunek;
	while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza2();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales/as liczby sproboj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
	system( "cls" );//czyszczenie ekranu

	if( tablica_gracza2[x][y]   == " #" ||
            tablica_gracza2[x+1][y] == " #" ||
            tablica_gracza2[x-1][y] == " #" ||
            tablica_gracza2[x][y+1] == " #" ||
            tablica_gracza2[x][y-1] == " #" ){
             SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;
             i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		   else if(x < 1 || y < 1 || x > 10 || y > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }
		else if( kierunek == "g" || kierunek == "p" || kierunek == "l" || kierunek == "d") {
    if (kierunek == "g")
	{

		    if(tablica_gracza2[x-1][y-1] == " #" ||
            tablica_gracza2[x-1][y-2] == " #" ||
            tablica_gracza2[x-1][y-3] == " #" ||
            tablica_gracza2[x][y-2] == " #" ||
            tablica_gracza2[x][y-3] == " #" ||
            tablica_gracza2[x][y-4] == " #" ||
            tablica_gracza2[x+1][y-1] == " #" ||
            tablica_gracza2[x+1][y-2] == " #" ||
            tablica_gracza2[x+1][y-3] == " #" )
            {
			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mo¿esz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y-3 < 1){
            i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawiæ statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else{
        tablica_gracza2[x][y] = " #";
		tablica_gracza2[x][y-1] = " #";
		tablica_gracza2[x][y-2] = " #";
		tablica_gracza2[x][y-3] = " #";
		}

	}
	else if (kierunek == "d")
	{
	    if(tablica_gracza2[x-1][y+1] == " #" ||
            tablica_gracza2[x-1][y+2] == " #" ||
            tablica_gracza2[x-1][y+3] == " #" ||
            tablica_gracza2[x][y+2] == " #" ||
            tablica_gracza2[x][y+3] == " #" ||
            tablica_gracza2[x][y+4] == " #" ||
            tablica_gracza2[x+1][y+1] == " #" ||
            tablica_gracza2[x+1][y+2] == " #" ||
            tablica_gracza2[x+1][y+3] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(y+3 > 10){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
        else{
		tablica_gracza2[x][y] = " #";
		tablica_gracza2[x][y+1] = " #";
		tablica_gracza2[x][y+2] = " #";
		tablica_gracza2[x][y+3] = " #";
	}
	}
	else if (kierunek == "p")
	{
	    if(tablica_gracza2[x+2][y] == " #" ||
                tablica_gracza2[x+3][y] == " #" ||
                tablica_gracza2[x+4][y] == " #" ||
                tablica_gracza2[x+3][y-1] == " #" ||
                tablica_gracza2[x+3][y+1] == " #" ||
                tablica_gracza2[x+2][y-1] == " #" ||
                tablica_gracza2[x+2][y+1] == " #" ||
                tablica_gracza2[x+1][y-1] == " #" ||
                tablica_gracza2[x+1][y+1] == " #" )
            {
			 i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x+2 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
            else{
          tablica_gracza2[x][y] = " #";
		tablica_gracza2[x+1][y] = " #";
		tablica_gracza2[x+2][y] = " #";
		tablica_gracza2[x+3][y] = " #";
	}
	}
	else if (kierunek == "l")
	{
	    if(     tablica_gracza2[x-4][y] == " #" ||
                tablica_gracza2[x-3][y] == " #" ||
                tablica_gracza2[x-2][y] == " #" ||
                tablica_gracza2[x-3][y-1] == " #" ||
                tablica_gracza2[x-3][y+1] == " #" ||
                tablica_gracza2[x-2][y-1] == " #" ||
                tablica_gracza2[x-2][y+1] == " #" ||
                tablica_gracza2[x-1][y-1] == " #" ||
                tablica_gracza2[x-1][y+1] == " #" )
            {

			i--;
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
		}
		else if(x-3 < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
             cout<<"Tam nie mozesz ustawic statku!!!"<<endl;

            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            i--;
            }
        else{
		tablica_gracza2[x][y] = " #";
		tablica_gracza2[x-1][y] = " #";
		tablica_gracza2[x-2][y] = " #";
		tablica_gracza2[x-3][y] = " #";
	}
		}
		}
		else{
            cout<<"Nie wpisales/as zgodnie z instrukcja sprobuj ponownie"<<endl;
            i--;
		}

	wyswietl_tablice_gracza2();
    }

}
int main(){
    setlocale(LC_CTYPE, "Polish");//ustawienie znaków na polski
    HANDLE kolor; //kolory
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );//kolory
    int m = 0;
    int n = 0;
    setlocale(LC_CTYPE, "Polish");
    cout<<"Nick pierwszego gracza:"<<endl;
    cin>>nick;
    cout<<"Nick drugiego gracza:"<<endl;
    cin>>nick2;

	for(int i = 1; i<11; i++)//zakropkowanie tablicy
	{

		for(int c = 1; c<11; c++)
		{

			tablica_gracza[c][i] = " .";
		}
	}
	for(int i = 1; i<11; i++)//zakropkowanie tablicy
	{

		for(int c = 1; c<11; c++)
		{

			tablica_gracza2[c][i] = " .";
		}
	}
	for(int i = 0; i<11; i++)//zakropkowanie tablicy
	{

		for(int c = 0; c<11; c++)
		{

			tablica_gracza_z[c][i] = " .";
		}
	}
	for(int i = 0; i<11; i++)//zakropkowanie tablicy
	{

		for(int c = 0; c<11; c++)
		{

			tablica_gracza2_z[c][i] = " .";
		}
	}
	cout << "Przykladowa tablica gracza: " << endl;
	cout << "x->1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i = 1; i<11; i++)//wyswietlenie tablicy
	{
        if(i==10){
          cout<<i;
        }
        else{
            cout<<i<<" ";
        }

		for(int c = 1; c<11; c++)
		{

			cout << tablica_gracza[c][i];
		}
		cout << endl;
	}
	cout<<nick2<<" odwroc sie od ekranu, poniewaz "<<nick<<" bedzie wybieral statki"<<endl;
	Sleep(3500);
	system( "cls" );//czyszczenie ekranu
    wczytaj_czteromasztowca();
	wczytywanie_trzymasztowcow();
	wczytywanie_dwumasztowcow();
	wczytywanie_jednomasztowcow();
	system( "cls" );//czyszczenie ekranu
	cout<<nick<<" odwroc sie od ekranu, poniewaz "<<nick2<<" bedzie wybieral statki"<<endl;
	Sleep(3500);
	system( "cls" );//czyszczenie ekranu
	wczytaj_czteromasztowca2();
	wczytywanie_trzymasztowcow2();
	wczytywanie_dwumasztowcow2();
	wczytywanie_jednomasztowcow2();
    system( "cls" );//czyszczenie ekranu
    wyswietl_tablice_gracza_z();
    wyswietl_tablice_gracza2_z();
	while(m < 20 || n < 20){
        for(int i = 0; i<1;i++){
        cout <<nick<< " wpisz wspolrzedne gdzie chcesz strzelac" << endl << "podaj x: ";
		int x;
		cin >> x;

		cout << "podaj y: ";
		int y;
		cin >> y;

		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza_z();
        wyswietl_tablice_gracza2_z();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales liczby sproboj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;}
		system("cls"); //czyszczenie ekranu}
		if(x > 10 || x < 1 || y > 10 || y < 1){
            SetConsoleTextAttribute(kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }


		else if(tablica_gracza_z[x][y] == " o" || tablica_gracza_z[x][y] == " x"){
            cout<<"Tam juz strzelales"<<endl;
            i--;
		}
		else if(tablica_gracza2[x][y] == " ."){
            tablica_gracza_z[x][y] = " o";

		}
		else if(tablica_gracza2[x][y] == " #"){
            tablica_gracza_z[x][y] = " x";
            m++;
		}
        system( "cls" );//czyszczenie ekranu
		wyswietl_tablice_gracza_z();
		wyswietl_tablice_gracza2_z();
        }
        for(int i = 0; i<1;i++){
        cout <<nick2<< " wpisz wspolrzedne gdzie chcesz strzelac" << endl << "podaj x: ";
		int x;
		cin >> x;
		cout << "podaj y: ";
		int y;
		cin >> y;

		while (cin.fail() ) { //cała pętla while służy do tego, aby można wpisywać tylko liczby // cin.fail sprawdza czy zmienna jest błędnie zapisana
        system( "cls" );//czyszczenie ekranu
        wyswietl_tablice_gracza_z();
        wyswietl_tablice_gracza2_z();
        cin.clear();//czyści błędy z obiektów, któe są błędnie zapisane
        cin.ignore(1000, '\n');//ignoruje do stu znaków chyba, że napotka koniec
        cout << "Nie wpisales/as liczby sprobuj ponownie "<<endl;
        cout<<"podaj x: ";
		cin >> x;
        cout << "podaj y: ";
		cin >> y;
		system("cls"); //czyszczenie ekranu}
        }
		if(x > 10 || x < 1 || y > 10 || y < 1){
            SetConsoleTextAttribute( kolor, 4 );//zmiana koloru na czerwony
            cout<<"Nie ma takiego pola!!!"<<endl;
            i--;
            SetConsoleTextAttribute( kolor, 7 );//zmiana koloru na standardowy
            }


		}
		else if(tablica_gracza2_z[x][y] == " o" || tablica_gracza2_z[x][y] == " x") {
            cout<<"Tam juz strzelales"<<endl;
            i--;
		}
		else if(tablica_gracza[x][y] == " ."){
            tablica_gracza2_z[x][y] = " o";

		}
		else if(tablica_gracza[x][y] == " #"){
            tablica_gracza2_z[x][y] = " x";
            n++;}
            system( "cls" );//czyszczenie ekranu
            wyswietl_tablice_gracza_z();
            wyswietl_tablice_gracza2_z();

            }

	}
	if(m == 20){
        cout<<"Gratulacje " <<nick<< " wygral!!!";
	}
	else if(n == 20){
        cout<<"Gratulacje " <<nick2<< " wygral!!!";

	}
	else if(m == 20 || n == 20){
            cout<<"Gratulacje remisu obu zawodnikom!!!";
	}

            return 0;

	}





