#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Empleado{
	private:
		string nombre, apellido;
		int edad;
		float salario;
	
	public:
		Empleado(string nom, string ape, int ed, float sal){
			nombre = nom;
			apellido = ape;
			edad = ed;
			salario = sal;
		}
		
		void mostrarInfo(){
			cout << "Nombre del empleado: " << nombre << endl;
			cout << "Apellido del empleado: " << apellido << endl;
			cout << "Edad del empleado: " << edad << endl;
			cout << "Salario del empleado: " << salario << endl << endl;
		}
};

int main(){
	Empleado empleado1("Katherine", "Palacios", 19, 2500);
	Empleado empleado2("Melissa", "Salguero", 18, 4000);
	Empleado empleado3("Diego", "Maradona", 20, 5000);
	
	cout << "Informacion del empleado #1" << endl;
	empleado1.mostrarInfo();
	cout << "Informacion del empleado #2" << endl;
	empleado2.mostrarInfo();
	cout << "Informacion del empleado #3" << endl;
	empleado3.mostrarInfo();
	
	return 0;
}
