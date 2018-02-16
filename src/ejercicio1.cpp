#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
///------------------------Funciones------------------------------------
void centrada(float x, float h,int n);
void progresiva(float x, float h,int n);
void richardson(float x, float h, int n);
double Exacto(double x);

int main()
{
	float x = 1.0, h= 0.1 ;
	int n = 10;
	//ingresar los numeros en float y luego se pasa a calcular en double.
	cin >> x;
	cin >> h;

	cout << endl << "Exacto =" << Exacto(x) << endl;

	cout << endl << "Progresiva" << endl << endl;
	progresiva(x,h,n);
	cout << endl << "Centrada" << endl << endl;
	centrada(x,h,n);
	cout << endl <<"Richardson"<< endl << endl;
	richardson(x,h,n);

	return 0;
}
///------------------------Desarrollo de Funciones----------------------
double Exacto(double x)
{
	return((double) 2*x*cos(pow(x,2)));
}
//----------------------------------------------------------------------
void progresiva(float x, float h,int n)
{
	int i;
	double h1,x1;

	h1 = (double)h;
	x1 = (double)x;

	cout << endl <<"Float"<< endl << endl;

	for (i = 1; i <= n ; i++)
	{
		cout << i << ')' << " con h = " << h;
		cout << endl << (sin(pow((x+h),2)) - sin(pow(x,2)))/h << endl;
		h = h/10;
	}

	cout << endl <<"Double" << endl << endl;
	for (i = 1; i <= n ; i++)
	{
		cout << i << ')' << " con h = " << h1;
		cout << setprecision(7) << endl << (sin(pow((x1+h1),2)) - sin(pow(x1,2)))/h1<<endl;
		h1 = h1/10;
	}
}
//----------------------------------------------------------------------
void centrada(float x, float h,int n)
{
	int i;
	double h1,x1;

	h1 = (double)h;
	x1 = (double)x;

	cout << endl << "float" << endl << endl;
	for (i = 1; i <= n ; i++)
	{
		cout << i << ")" << " con h = " << h << endl;
		cout << ((sin(pow((x+h),2)) - sin(pow((x-h),2)))/(2*h)) << endl;
		h = h/10;
	}

	cout << endl <<"Double" << endl << endl;
	for (i = 1; i <= n ; i++)
	{
		cout << i << ")" << "con h = " << h1 << endl;
		cout << setprecision(7) << ((sin(pow((x1+h1),2)) - sin(pow((x1-h1),2)))/(2*h1)) << endl ;
		h1 = h1/10;
	}

}
//----------------------------------------------------------------------
void richardson(float x, float h, int n)
{
	int i=0;
	float Dh1,Dh2,resul;
	double d1,d2,x1,h1;

	x1 = (double)x;
	h1 = (double)h;

	cout << endl << "float " << endl;
	for (i = 1; i <= n ; i++)
	{
		//~ printf("h--> %f x--> %f\n",h,x);
		Dh1 = ((sin(pow((x+h),2)) - sin(pow((x-h),2)))/(2*h));
		Dh2 = ((sin(pow((x+(h/2)),2))-sin(pow((x-(h/2)),2)))/(2*(h/2)));
		resul = ((4*Dh2-Dh1)/3);
		cout << endl << i << ")" << "D2(h) = " << resul;
		h = h/10;
	}

	cout << endl << endl << "double"<< endl;

	for (i = 1; i <= n ; i++)
	{
		//~ printf("h--> %.5e x--> %.5e\n",h1,x1);
		d1 = ((sin(pow((x1+h1),2)) - sin(pow((x1-h1),2)))/(2*h1));
		d2 = ((sin(pow((x1+(h1/2)),2)) - sin(pow((x1-(h1/2)),2)))/(2*(h1/2)));
		cout << setprecision(7) << endl << i << ')'<< "D2(h) = " << (((4*d2)-d1)/3);
		h1 = h1/10;
	}
	cout << endl;
}
