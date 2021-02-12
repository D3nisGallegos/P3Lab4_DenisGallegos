#include <iostream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <cstring>
#include <string>
//#include "Producto.cpp"
#include "Inventario.cpp"

using namespace std; 

bool validar(int identificador, vector <int> identificadores){
	bool v = false; 
	for (int c = 0; c < identificadores.size();c++){
		int id = identificadores[c]; 
		if (id == identificador){
			v == true; 
		}
	}
	return v; 
}


int main(int argc, char** argv) {
	
	vector <int> identificadores; 
	int opcion =0; 
	while (opcion !=4 ){
		cout << "     INVENTARIO DE AMAZON: " <<endl;
		cout << "1) Mantenimiento de productos. " <<endl;  
		cout << "2) Estadisticas generales. " <<endl;
		cout << "3) Busqueda por nombre. " <<endl; 
		cout << "Ingrese la opcion: " <<endl; 
		cin >> opcion;
		switch (opcion){
			case 1:
				{
				int opcion2 = 0;
				while (opcion2 != 4){
					cout << " MANTENIMIENTO: " <<endl; 
					cout << "1) Agregar productos." <<endl;
					cout << "2) Modificar productos. " <<endl;
					cout << "3) Eliminar productos. " <<endl; 
					cout << "Ingrese la opcion: " <<endl; 
					cin >> opcion2;
					switch (opcion2){
						case 1:
							{
							cout << "Agregar producto: " <<endl; 
							cout << "Ingrese el id: " <<endl; 
							int id; 
							cin >> id; 
							bool v = validar(id, identificadores);
							if (v == true){
								cout << "El id del producto ya existe. " <<endl;
								break;
							}
							cout << "Ingrese el nombre: " <<endl; 
							string nombre; 
							cin.ignore();
							getline(cin, nombre);
							cout << "Ingrese la categoria: " <<endl; 
							string categoria; 
							cin.ignore();
							getline(cin, categoria);
							cout << "Ingrese la cantidad de unidades: " <<endl; 
							int unidades; 
							cin >> unidades; 
							cout << "Ingrese el precio: " <<endl; 
							double precio; 
							cin >> precio; 
							Producto* product = new Producto(id, nombre, categoria, unidades, precio);
							identificadores.push_back(id);
							cout << "creado." <<endl;
							break; 
							}//Fin del caso 1. 
						case 2:
							{
								
							break; 
							}//Fin del caso 2. 
						case 3:
							{
								
							break; 
							}//Fin del caso 3.
					}//Fin del switch del menu 1. 	
				}//Fin del while del menu 1. 
				break; 
				}//Fin del caso 1.
		}//Fin del switch del menu principal. 
	}//Fin del while del menu principal. 
	
	
	
	return 0;
}//Fin del MAIN.





