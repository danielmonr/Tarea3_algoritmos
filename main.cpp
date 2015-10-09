/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Ejercicio1: Un camionero tiene un tanque de gasolina que le permite recorrer n
 *    		    kilometros. Algoritmo que te permite trasar la ruta recorriendo el
 *    		    menor numero de gasolineras.
 *    		    Ejercicio2:
 *
 *        Version:  1.0
 *        Created:  05/10/15 09:32:22
 *       Revision:  none
 *       Compiler:  g++ -std=c++11
 *
 *         Author:  Daniel Monzalvo
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

#define Arriba 'U'
#define Izq 'I'
#define Diagonal 'D'

using namespace std;
// Variable ej1
int maxKilometraje;
vector<int> posicion;
// Variables ej2
int L, b = 0;
// Variables ejercicio 3
char origen[100][100];
int LongS[100][100];
const int numPer = 4;
// Variables ejercicio 4
int H[numPer][numPer] = {{3,1,2,0},{3,2,0,1},{1,3,0,2},{2,1,3,0}};
int M[numPer][numPer] = {{1,3,2,0},{0,2,3,1},{1,3,2,0},{2,1,3,0}};
int ordenM[numPer][numPer] = {{3,1,2,0},{2,3,1,0},{2,0,3,1},{3,1,0,2}};
int ordenH[numPer][numPer] = {{3,0,2,1},{0,3,1,2},{3,0,2,1},{3,1,0,2}};
int parejasH[numPer];
int parejasM[numPer];
bool disp[numPer];
bool succ;

// funciones
vector<int> ejercicio1();
int ejercicio2();
vector<string> obtenerPalabras();
int ejercicio2();
void initEjercicio3();
void ejercicio3(const char*, const char*);
void ejercicio4();
void imprimirMaxSecCom(const char*,int, int);
bool estable(int, int, int);
void juntar(int, bool);

int main(){
	cout << "Daniel Monzalvo-A01021514\nTarea 3\nEjercicio 1" << endl;
	// Ejercicio 1

	vector<int> sol = ejercicio1();
    cout << "Solucion: " << endl;
	for (auto item:sol)
		cout << item << ", ";
	cout << endl;
	cout << "Complejidad O(n), Metodo de diseno de algoritmo: avido" << endl;


	// Ejercicio 2
	cout << endl << "-------------------------------------------------" << endl;
	cout << "Ejercicio 2" << endl;
	cout << "Costo Total:" << ejercicio2() << endl;
	cout << "Complejidad O(n), Metodo de diseno de algoritmo: avido" << endl;
	//ejercicio2();

	cout << endl << "-------------------------------------------------" << endl;
	cout << "Ejercicio 3" << endl;

	 initEjercicio3();

	cout << "Complejidad O(n*n), Metodo de diseno de algoritmo: programacion dinamica" << endl;

	cout << endl << "-------------------------------------------------" << endl;
	cout << "Ejercicio 4" << endl;
	ejercicio4();

	cout << "Complejidad O(n^n), Metodo de diseno de algoritmo: backtracking" << endl;


	return 0;
}

vector<int> ejercicio1(){

    posicion.push_back(10);
    posicion.push_back(15);
    posicion.push_back(23);
    posicion.push_back(25);
    posicion.push_back(33);
    posicion.push_back(49);
    posicion.push_back(54);
    posicion.push_back(60);
    posicion.push_back(70);
    posicion.push_back(75);

    cout << "Posicion de las gasolineras: " << endl;
    for (auto item:posicion)
        cout << item << ", ";
    cout << endl;

    cout << "Cual es el kilometraje maximo del tanque de gasolina: " << endl;
    cin >> maxKilometraje;

	vector<int> solucion;
	int pos = 0;
	int distancia = 0;
	int temp;
	for (auto item:posicion){
		distancia = item - pos;
		if (distancia <= maxKilometraje){
			temp = item;
			if (item == posicion.back())
				solucion.push_back(item);
		}
		else{
			pos = temp;
			solucion.push_back(pos);
			if (item - pos <= maxKilometraje)
				temp = item;
			else{
				solucion.clear();
				break;
			}
		}
	}
	return solucion;
}

int ejercicio2(){
		vector<string> s = obtenerPalabras();
		// Tamano espacios
		b = 1;
		// Tamano de espacios en la linea actual
		int bs = b;
		// tamano de los caracteres
		int tChar = 1;
		// longitud en milimetros de la linea actual
		int l = 0;
		// Linea actual
		string linea = "";
		// numero de espacios en la linea actual
		int espacios = 0;
		// Costo de la linea actual
		int costo = 0;
		// Costo global
		int T = 0;
		// Numero de linea
		int n = 0;

		bool aux = false;
		bool nueva= true;

	for(auto item:s){
		if(((l+item.length()*tChar)) > L){
			// cout << "tamano: " << l;
				cout << item << endl;
				costo = (L-l)/espacios;
				if (espacios != 0)
					bs = ((L - l) / espacios) + b;
				++n;
				cout << "Linea " << n << " -->" << linea << "<-- " << "costo: " << costo << " b' = " << bs << endl;
				T += costo;

				bs = b;
				linea = "";
				l = item.length()*tChar;
				espacios = 0;
				costo = 0;
				nueva = true;

		}

			l = l + (item.length()*tChar);
			if (item != s.back()){
				l += b;
				++espacios;
			}
			if (!nueva)
			linea = linea + " ";
			linea += item;
			nueva = false;
			// cout << linea << endl;
	}

	if(linea != ""){
		costo = 0;
		if (espacios != 0)
			bs = ((L-l)/ espacios) +b;
			++n;
			cout << "Linea " << n << " -->" << linea << "<-- " << "costo: " << costo << "b = " << bs << endl;
			T+= costo;
	}

	return T;
}

void ejercicio3(const char X[], const char Y[]){
		int n, m;
		n = (int)strlen(X);
		m = (int)strlen(Y);

		for (int i = 0; i < n; ++i)
				LongS[i][0] = 0;
		for (int i = 0; i < m;++i)
				LongS[0][i] = 0;

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if (X[i] == Y[j]){
					LongS[i][j] = LongS[i-1][j-1] +1;
					origen[i][j] = Diagonal;
				}
				else if (LongS[i-1][j] >= LongS[i][j-1]){
					LongS[i][j] = LongS[i-1][j];
					origen[i][j] = Arriba;
				}
				else{
					LongS[i][j] = LongS[i][j-1];
					origen[i][j] = Izq;
				}
			}
		}
		cout << "Solucion: ";
		imprimirMaxSecCom(X,n,m);
		cout << endl;
}

void ejercicio4(){
		for(int i = 0; i < numPer; ++i)
				disp[i] = true;

				juntar(0, succ);

		for (int i = 0; i < numPer; i++){
			cout << "Solucion: " << endl;
			cout << "Hombre " << i << "con Mujer " << parejasM[i] << endl;
		}

}

void juntar(int iterador, bool success){
	int prefiere = 0;
	int preferencia = 0;

	while(!success){
		for (int i = 0; i < numPer; ++i){
			preferencia = M[iterador][i];

			if (disp[preferencia] && estable(iterador, preferencia, i)){
				parejasH[iterador] = preferencia;
				parejasM[preferencia] = iterador;
				disp[preferencia] = 0;
				if (iterador < numPer){
					juntar(iterador+1, success);
				}
				if(!success){
					disp[preferencia] = 1;
				}
			}
			else{
				success = true;
			}
		}
	}
}

bool estable(int it, int pref, int muj){
	bool s = 1;
	int mejorMujer, mejorHombre, limite;
	int i = 0;

	while (i < muj && s)
	{
		mejorMujer = M[it][i];
		i++;

		if (!disp[mejorMujer])
			s = ordenM[mejorMujer, it] > ordenM[mejorMujer, parejasH[mejorMujer]];
	}

	i = 0;
	limite = H[pref][it];

	while (i < limite && s)
	{
		mejorHombre = H[pref][i];
		i++;

		if (mejorHombre < it)
			s = ordenH[mejorHombre][pref] > ordenH[mejorHombre][parejasM[mejorHombre]];
	}
	return s;
}

vector<string> obtenerPalabras(){
		//int tam = 0;
	cout << "Supongamos que b = 1mm\nUna letra tiene una longitud igualmente de 1mm" << endl;
	vector<string> s;
	string frase, temp;
	cout << "Inserte la frase: " << endl;
	getline(cin, frase);
	cout << "Inserte el tamano de la linea" << endl;
	cin >> L;

	//L = tam;

	//cout << "Tam: " << tam << endl;
	//cout << "frase: " << frase << endl;

	for (int i = 0; i < frase.length(); ++i){
		if (frase[i] == ' '){
			s.push_back(temp);
			temp = "";
		}
		else{
			temp += frase[i];
		}
	}
	if (temp.length() != 0)
		s.push_back(temp);

	//for (auto item:s)cout << item <<endl;

	return s;
}

void imprimirMaxSecCom(const char* X, int i, int j){
	if (i == 0 | j == 0){
		return;
	}
	if (origen[i][j] == Diagonal){
		imprimirMaxSecCom(X, i-1, j-1);
		cout << X[i];
	}
	else{
		if (origen[i][j] == Arriba){
			imprimirMaxSecCom(X, i-1,j);
		}
		else{
			imprimirMaxSecCom(X,i,j-1);
		}
	}
}

void initEjercicio3(){
	string p1, p2;
	cout << "Introduzca una palabra (no se aceptan espacios): " << endl;
	cin >>p1;
	cout << "Introduzca otra palabra: " << endl;
	cin >> p2;
	const char* X = p1.c_str();
	const char* Y = p2.c_str();
	ejercicio3(X,Y);
}
