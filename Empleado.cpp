#include <iostream>
#include <fstream> //Manejo de entrada y salida de archivos
#include <windows.h> 

using namespace std;

//******************* MENÚ DE OPCIONES
int menu(){
	int op;
	system("cls");
	cout << "------------- BIENVENIDO -------------" << endl;
	cout << "Opciones del menu" << endl;
	cout << "1. Agregar empleado" << endl;
	cout << "2. Ver empleados" << endl;
	cout << "3. Buscar empleado" << endl;
	cout << "4. Modificar registro del empleado" << endl;
	cout << "5. Eliminar registro del empleado" << endl;
	cout << "6. Salir" << endl << endl;
	cout << "Ingresa tu opcion: ";
	cin >> op;
	
	return op;
}

//************* VERIFICAR QUE LOS CÓDIGOS NO SEAN IGUALES *********
bool verifica(string Cod){
	ifstream leer("empleados.txt", ios::in);
	
	struct empleado{
		string nom, cod, edad, salario;
	}emp;
	
	leer >> emp.nom;
	
	while(!leer.eof()){
		leer >> emp.edad;
		leer >> emp.cod;
		leer >> emp.salario;
		if(emp.cod == Cod){
			leer.close();
			return false;
		}
		leer >> emp.nom;
	}
	leer.close();
	return true;
}

//********** INSERTAR REGISTROS ******************
void agregar(ofstream &es){
	system("cls");
	
	struct empleado{	
		string nom, cod, edad, salario;
	}emp;

	es.open("empleados.txt", ios::out | ios::app); 
	
	cout << "Nombre: ";
	cin >> emp.nom;
	cout << "Edad: ";
	cin >> emp.edad;
	cout << "Codigo: ";
	cin >> emp.cod;
	cout << "Salario: ";
	cin >> emp.salario;
	
	if(verifica(emp.cod))
		es << emp.nom << " " << emp.edad << " " << emp.cod << " " << emp.salario << " " << endl;
	es.close();
}

//**************** VER REGISTROS DEL SISTEMA *************************
void verRegistros(ifstream &Lec){
	system("cls");
	
	struct empleado{	
		string nombre, codigo, edad, salario;	
	}emp;
	
	Lec.open("empleados.txt", ios::in); 
	
	if(Lec.is_open()){
		cout << "------- EMPLEADOS REGISTRADOS -------" << endl << endl;
		Lec >> emp.nombre;
		while(!Lec.eof()){	
			Lec >> emp.edad;
			Lec >> emp.codigo;
			Lec >> emp.salario;
			
			cout << "Nombre ***********************: " << emp.nombre << endl;
			cout << "Edad *************************: " << emp.edad << endl;
			cout << "Codigo ***********************: " << emp.codigo << endl;
			cout << "Salario **********************: " << emp.salario << endl;
			cout << "************************************" << endl << endl;
			
			Lec >> emp.nombre;	
		}
		Lec.close();
	}else
		cout << "Error al abrir el archivo" << endl;
	system("pause");
}

//*************** BUSCAR REGISTROS *******************************
void buscarEmpleado(ifstream &Lec){
	system("cls");
	Lec.open("empleados.txt", ios::in);
	
	struct perro{
		string nombre, edad, codigo, salario, cod_aux;
	}emp;
	
	bool found = false;
	
	cout << "Ingrese el codigo del empleado: ";
	cin >> emp.cod_aux;
	cout << endl;
	
	Lec >> emp.nombre;
	while(!Lec.eof() && !found){
		Lec >> emp.edad;
		Lec >> emp.codigo;
		Lec >> emp.salario;
		
		if(emp.codigo == emp.cod_aux){
			cout << "Nombre ***********************: " << emp.nombre << endl;
			cout << "Edad *************************: " << emp.edad << endl;
			cout << "Codigo ***********************: " << emp.codigo << endl;
			cout << "Salario **********************: " << emp.salario << endl;
			found = true;
		}
		Lec >> emp.nombre;
	}
	Lec.close();
	
	if(!found)
		cout << "Empleado no encontrado" << endl;
	system("pause");
}

//*************** MODIFICAR REGISTRO DE EMPLEADOS **********************
void modificarEmpleado(ifstream &Lec){
	
	system("cls");
	
	struct empleado{
		
		string nom, cod, edad, salario, cod_aux, nom_aux, edad_aux, salario_aux;
		
	}emp;
	
	Lec.open("empleados.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out); 
	
	if(Lec.is_open()){
		cout << "Ingrese el codigo del registro a modificar: ";
		cin >> emp.cod_aux;
		
		Lec >> emp.nom;
		while(!Lec.eof()){
			
			Lec >> emp.edad;
			Lec >> emp.cod;
			Lec >> emp.salario;
			
			if(emp.cod == emp.cod_aux){
				
				cout << "Ingrese el nombre a modificar: ";
				cin >> emp.nom_aux;
				cout << "Ingrese la edad a modificar: ";
				cin >> emp.edad_aux;
				cout << "Ingrese el salario a modificar: ";
				cin >> emp.salario_aux;
				
				aux << emp.nom_aux << " " << emp.edad_aux << " " << emp.cod << " "<< emp.salario_aux << " "<< endl; 
				
			}else{
				
				aux << emp.nom << " " << emp.edad << " " << emp.cod << " "<< emp.salario << " " << endl;
				
			}
			
			Lec >> emp.nom;	
			
		}
		
		Lec.close();
		aux.close();
	}else
		cout << "Error al abrir el archivo" << endl;
		
	remove("empleados.txt");
	rename("Auxiliar.txt", "empleados.txt");
	
}

//*************** ELIMINAR EMPLEADO DEL SISTEMA *********************
void eliminarEmpleado(ifstream &Lec){
	
	system("cls");
	
	struct empleado{
		
		string nom, cod, edad, salario, cod_aux, nom_aux, edad_aux, salario_aux;
		
	}emp;
	
	Lec.open("empleados.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out); 
	
	if(Lec.is_open()){
		cout << "Ingrese la cedula del registro a eliminar: ";
		cin >> emp.cod_aux;
		
		Lec >> emp.nom;
		while(!Lec.eof()){
			
			Lec >> emp.edad;
			Lec >> emp.cod;
			Lec >> emp.salario;
			
			if(emp.cod == emp.cod_aux){
				
				cout << "Registro eliminado correctamente.";
				Sleep(1500);
				
			}else{
				
				aux << emp.nom << " " << emp.edad << " " << emp.cod << " "<< emp.salario << " " << endl;
				
			}
			
			Lec >> emp.nom;	
			
		}
		
		Lec.close();
		aux.close();
	}else
		cout << "Error al abrir el archivo" << endl;
		
	remove("empleados.txt");
	rename("Auxiliar.txt", "empleados.txt");
	
}

//*********************** MÉTODO PRINCIPAL DEL PROGRAMA *******************
int main(){
	
	ofstream Esc; //Archivo de escritura
	ifstream Lec; //Archivo de lectura
	 
	int op;
	
	do{
		
		system("cls");
		
		op = menu();
		
		switch(op){
			
			case 1:
				{
					agregar(Esc);
				}
			break;
			
			case 2:
				{
					verRegistros(Lec);
				}
			break;
			
			case 3:
				{
					buscarEmpleado(Lec);	
				}	
			break;
			
			case 4:
				{
					modificarEmpleado(Lec);	
				}
			break;
			
			case 5:
				{
					eliminarEmpleado(Lec);	
				}
			break;			
		}
		
	}while(op != 6);
	
	return 0;
	
}


