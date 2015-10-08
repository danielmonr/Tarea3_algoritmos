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
#include <vector>

using namespace std;
// Variable ej1
int maxKilometraje;
vector<int> posicion;
// Variables ej2
int L, b = 0;
// funciones
vector<int> ejercicio1();
int ejercicio2();
vector<string> obtenerPalabras();
int ejercicio2();

int main(){
	cout << "Daniel Monzalvo-A01021514\nTarea 3\nEjercicio 1" << endl;
	// Ejercicio 1
	/*
	vector<int> sol = ejercicio1();
    cout << "Solucion: " << endl;
	for (auto item:sol)
		cout << item << ", ";
	cout << endl;
	*/

	// Ejercicio 2
	cout << endl << "-------------------------------------------------" << endl;
	cout << "Ejercicio 2" << endl;
	//cout << "Costo:" << ejercicio2();
	ejercicio2();
//	obtenerPalabras();

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


	for(auto item:s){
		if(((l+item.length()*tChar) + b) < L){
				l = l + (item.length()*tChar) + b;
				++espacios;
				linea = linea + " " + item;
				cout << linea << endl;
		}
		else {
				if (item != s.back()){
					costo = (L-l)/espacios;
				}
				else{
						costo = 0;
				}
				if (espacios != 0)
					bs = ((L - l) / espacios) + b;
				++n;
				cout << "Linea " << n << " -->" << linea << "<-- " << "costo: " << costo << " b' = " << bs << endl;
				T += costo;

				bs = b;
				linea = "";
				l = 0;
				espacios = 0;
				costo = 0;
		}
	}
	return T;
}

void ejercicio3(){
		int n, m;
		char* X;
		char* Y;
		char** L;

		for (int i = 0; i < n; ++i)
				L[i][0] = 0;
		for (int i = 0; i < m;++i)
				L[0][i] = 0;


}

void ejercicio4(){
		// Numero de Hombres y de Mujeres
		int n = 3;
		// Matriz de Hombres
		int H[n][n];
		// Matriz de Mujeres
		int M[n][n];
		// Parejas siendo i el hombre y el valor de i la mujer
		int p[n];
		// Disponibilidad de la Mujer
		bool disp[n];

		for (int i = 0; i < n; ++i){
				
		}
}

vector<string> obtenerPalabras(){
		//int tam = 0;
	cout << "Supongamos que b = 1mm\nUna letra tiene una longitud igualmente de 1mm" << endl;
	vector<string> s;
	string frase, temp;
	cout << "Inserte la frase: " << endl;
	getline(cin, frase);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
