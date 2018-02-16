/*
 * ejercicio2.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: marwilc
 */

#include <iostream>
#include <iomanip>

using namespace std;

void mostrarMatriz(double **matriz, int fila, int columna){

	for (int k = 0; k < fila; k++){
	 		for (int j = 0; j < columna; ++j){
				cout << setprecision(2) << setiosflags(ios::right) << setw(5) << matriz[k][j];

	 		}
	 		cout << endl;
	 	}
}
void factorizacionLU(double **matrizA, int fila, int columna){

	double factor;

	for (int k = 0; k < fila-1; k++) {
		for (int i = k + 1; i < fila; i++) {

			factor = (double) matrizA[i][k]/matrizA[k][k];
			matrizA[i][k]=factor;
			for (int j = k + 1; j < columna; j++) {
				matrizA[i][j]=matrizA[i][j] - factor * matrizA[k][j];
			}
		}
	}

}

void sustitucionRegresiva(double **matrizA, int fila, int columna, double *x1, double *b){

	double suma;
	for (int i = fila-1; i >= 0; i--) {
		suma = 0;
		for (int j = fila-1; j >= 0 ; j--) {
			if(i != j){
				suma = (double) (suma + (matrizA[i][j]*x1[j]));
			}
		}
		x1[i] = (double) b[i] + suma*(-1) / matrizA[i][i];
	}
}

void sustitucionProgresiva(double **matrizA, int fila, int columna, double *x2, double *b){

	double suma;
	for (int i = 0; i < fila; i++) {
		suma = 0;
		for (int j = 0; j < fila - 1; j++) {
			if(i != j){
				suma = (double) suma + matrizA[i][j]*x2[j];
			}
		}
		x2[i] = (double) b[i] + suma*(-1) / matrizA[i][i];
	}
}

int main(int argc, char **argv) {

	double **matrizA, **matrizU, **matrizL, *x1 , *x2, *b;
	int filaDinamica;
	int colunmaDinamica;

	cin >> filaDinamica >> colunmaDinamica;

 	matrizA = new double *[filaDinamica];
 	matrizL = new double *[filaDinamica];
 	matrizU = new double *[filaDinamica];// construccion de la matriz dinamicamente
 	for (int i = 0; i < filaDinamica; i++) {
		matrizA[i] = new double[colunmaDinamica];
		matrizL[i] = new double[colunmaDinamica];
		matrizU[i] = new double[colunmaDinamica];
	}

 	x1 = new double [filaDinamica];
 	x2 = new double [filaDinamica];
 	b = new double [filaDinamica];

 	for (int k = 0; k < filaDinamica; k++){
 		x1[k]=0;
 		x2[k]=0;
 		for (int j = 0; j < colunmaDinamica; j++)
			cin >> matrizA[k][j];
 	}


 	for (int k = 0; k < filaDinamica; k++)
 	{
 		cin >> b[k];
 	}

 	cout << "Matriz original"<<endl;
 	mostrarMatriz(matrizA, filaDinamica, colunmaDinamica);
 	cout << endl << endl;
 	factorizacionLU(matrizA, filaDinamica, colunmaDinamica);
 	sustitucionRegresiva(matrizA, filaDinamica, colunmaDinamica, x1, b);
 	sustitucionProgresiva(matrizA, filaDinamica, colunmaDinamica, x2, b);
 	cout << "Matriz LU"<<endl;
 	mostrarMatriz(matrizA, filaDinamica, colunmaDinamica);

 	cout << setiosflags(ios::right) << "Sustitucion regresiva" << endl;

 	for (int f = 0; f < filaDinamica; f++) {
 		cout << setw(3) << "x" <<f+1 << setw(2) <<'=' << setw(2) << x1[f] << endl;
	}

	cout << setiosflags(ios::right) << "Sustitucion progresiva" << endl;
 	for (int f = 0; f < filaDinamica; f++) {
 		cout << setw(3) << "x" <<f+1 << setw(2) <<'=' << setw(2) << x2[f] << endl;
	}
 	delete []matrizA;
 	delete []matrizU;
 	delete []matrizL;
 	delete []x1;
 	delete []x2;
 	delete []b;
	return 0;
}



