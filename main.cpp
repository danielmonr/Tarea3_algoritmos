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
int L, b, T = 0;
// funciones
vector<int> ejercicio1();
int ejercicio2();
vector<string> obtenerPalabras();

main(){
	cout << "Daniel Monzalvo-A01021514\nTarea 3\nEjercicio 1" << endl;
	// Ejercicio 1
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

	vector<int> sol = ejercicio1();

	cout << "Resultado ejercicio 1:" << endl;
	for (auto item:sol)
		cout << item << ", ";
	cout << endl;

	// Ejercicio 2
	cout << endl << "-------------------------------------------------" << endl;
	cout << "Ejercicio 2" << endl;


	return 0;
}

vector<int> ejercicio1(){
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
	int d = 0;
	vector<string> s = obtenerPalabras();
	if (T < L){
		d = L-T;

	}
}

vector<string> obtenerPalabras(){
	vector<string> s;
	string frase, temp;
	cout << "Inserte la frase: " << endl;
	cin >> frase;
	cout << "Inserte el tamano de la linea" << endl;
	cin >> L;

	for (int i = 0; i < frase.length(); ++i){
		if (frase[i] != ' '){
			s.push_back(temp);
			temp = "";
		}
		else{
			temp += frase[i];
			T++;
		}
	}
	if (temp.length() != 0)
		s.push_back(temp);

	return s;
}
