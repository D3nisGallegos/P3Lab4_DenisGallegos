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
			v = true; 
		}
	}
	return v; 
}


int main(int argc, char** argv) {
	
	vector <int> identificadores; 
	Inventario* inventario;
	int opcion =0; 
	while (opcion !=4 ){
		cout << "     INVENTARIO DE AMAZON: " <<endl;
		cout << "1) Mantenimiento de productos. " <<endl;  
		cout << "2) Estadisticas generales. " <<endl;
		cout << "3) Busqueda por nombre. " <<endl; 
		cout << "4) Salir.";
		cout << "Ingrese la opcion: " <<endl; 
		cin >> opcion;
		switch (opcion){
			case 1:
				{
				int opcion2 = 0;
				while (opcion2 != 4){
					cout << "     MANTENIMIENTO: " <<endl; 
					cout << "1) Agregar productos." <<endl;
					cout << "2) Modificar productos. " <<endl;
					cout << "3) Eliminar productos. " <<endl; 
					cout << "4) Salir.";
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
							double precio = 0; 
							cin >> precio; 
							Producto* product = new Producto(id, nombre, categoria, unidades, precio);
							identificadores.push_back(id);
							inventario->Agregarproducto(product);
							cout << "Producto Agregado correctamente. " <<endl;
							break; 
							}//Fin del caso 1. 
						case 2:
							{
						    cout << "Modificar producto: " <<endl; 
						    cout << "Ingrese el id del producto a modificar: " <<endl;
							int id; 
							cin >> id; 
							bool valid = false; 
							vector <Producto*> todos = inventario->GETproductos();
							for (int c = 0; c < inventario->GETproductos().size();c++){
								int h = inventario->GETproductos() [c]->GETid(); 
								if (h == id){
									valid = true; 
									Producto* objeto = inventario->GETproductos() [c];
									cout << "Ha accedido al objeto: " <<endl; 
									cout << "Id: " << objeto->GETid() << " Nombre: " << objeto->GETnombre() << " Categ: " << objeto->GETcategoria() << " Unidades: " << objeto->GETcantidad() << " Precio: " << objeto->GETprecio();
									int opcion3 = 0; 
									while (opcion3 != 6){
										cout << "1- modificar id." <<endl;
										cout << "2- modificar nombre. " <<endl; 
										cout << "3- modificar categoria. " <<endl; 
										cout << "4- modificar unidades." <<endl;
										cout << "5- modificar precio. " <<endl; 
										cout << "6 - salir." <<endl;
										cout << "Ingrese la opcion. " <<endl; 
										if (opcion3 == 1){
											cout << "Ingrese el nuevo id: " <<endl;
											int h = 0; 
											cin >> h;
											bool v = validar(h, identificadores);
											if (v == true){
												cout << "El id ingresado ya existe." <<endl;
												break; 
											}else {
												int elem = 0;
												for (int j = 0; j < identificadores.size();j++){
													if (objeto->GETid() == identificadores [j]){
														elem = j; 
													}
												}
												identificadores [elem] = h;
											}
											objeto->SETid(h); 
										}else if (opcion3 == 2){
											cout << "Ingrese el nuevo nombre: " <<endl;
											string h;
											cin.ignore(); 
											getline(cin, h);
											objeto->SETnombre(h);
										}else if (opcion3 == 3){
											cout << "Ingrese la nueva categoria: " <<endl;
											string h;
											cin.ignore(); 
											getline(cin, h);
											objeto->SETcategoria(h);
										}else if (opcion3 == 4){
											cout << "Ingrese la nueva cantidad: " <<endl;
											int h; 
											cin >> h;
											objeto->SETcantidad(h);
										}else if (opcion3 == 5){
											cout << "Ingrese el nuevo precio: " <<endl;
											double h; 
											cin >> h;
											objeto->SETprecio(h);
										}
										cout << "Producto modificado correctamente.";
									}
								}	
							}
							if (valid == false){
								cout << "El id ingresado no existe." <<endl;
							}								 
							break; 
							}//Fin del caso 2. 
						case 3:
							{
							cout << "Eliminar producto: " <<endl;
							cout << "Ingrese el id del producto a eliminar:" <<endl; 
							int id; 
							cin >> id; 
							bool valid = false; 
							Producto* nuevo; 
							vector <Producto*> todos = inventario->GETproductos();
							for (int c = 0; c < inventario->GETproductos().size();c++){
								int h = inventario->GETproductos() [c]->GETid(); 
								if (h = id){
									valid = true; 
									Producto* objeto = inventario->GETproductos() [c];
									cout << "Ha accedido al objeto: " <<endl; 
									cout << "Id: " << objeto->GETid() << " Nombre: " << objeto->GETnombre() << " Categ: " << objeto->GETcategoria() << " Unidades: " << objeto->GETcantidad() << " Precio: " << objeto->GETprecio();
									delete inventario->GETproductos() [c]; 		
									nuevo = objeto; 					
								}
							}
							int elemento = 0;
							for (int j = 0; j < inventario->GETproductos().size();j++){
								Producto* objeto = inventario->GETproductos() [j];
								if (nuevo == objeto){
									elemento = j; 
								}
							}
							inventario->GETproductos().erase(inventario->GETproductos().begin()+elemento);
							if (valid == false){
								cout << "El id ingresado no existe. " <<endl;		
							}
							break; 
							}//Fin del caso 3.
					}//Fin del switch del menu 1. 	
				}//Fin del while del menu 1. 
				break; 
				}//Fin del caso 1.
		    case 2:
		   		{
		   		cout << "ESTADISTICAS GENERALES: " <<endl;	
		   		cout << "Listado: " <<endl;
		   		double preciototal = 0; 
		   		int unidadestotales = 0; 
		   		int productosunicos = inventario->GETproductos().size();
		   		for (int c = 0;c < inventario->GETproductos().size();c++){
		   			Producto* objeto = inventario->GETproductos() [c];
		   			preciototal += objeto->GETprecio();
		   			unidadestotales += objeto->GETcantidad();
				}
				for (int c = 0;c < inventario->GETproductos().size();c++){
		   			Producto* objeto = inventario->GETproductos() [c];
		   			inventario->GETcategorias().push_back(objeto->GETcategoria());
				}
				for (int c = 0; c < inventario->GETcategorias().size();c++){
					string categ = inventario->GETcategorias() [c];
					cout << "Categoria: " << categ <<endl; 
					for (int j = 0; j < inventario->GETproductos().size();j++){
						Producto* objeto = inventario->GETproductos() [j];
						if (objeto->GETcategoria() == categ){
							cout << "id: " << objeto->GETid() << " nombre: " << objeto->GETnombre() << " categoria: " << objeto->GETcategoria() << " cantidad: " << objeto->GETcantidad() << " precio: "<< objeto->GETprecio() <<endl; 
						}
					}
				}
				cout << "Productos unicos: " << productosunicos <<endl;
				cout << "Precio total de inventario: " << preciototal <<endl;
				cout << "Unidades de productos totales: " << unidadestotales <<endl;
				
		   		break; 	
				}//Fin de caso 2.
			case 3:
				{
				cout << "BUSQUEDA POR NOMBRE: " <<endl; 
				cout << "Ingrese la cadena a buscar en el inventario. " <<endl; 
				string cadena; 
				cin.ignore(); 
				getline(cin, cadena);
				vector <Producto*> subproductos; 
				for (int c = 0; c < inventario->GETproductos().size();c++){
					
				}		
				break; 
				}//Fin del caso 3.
		}//Fin del switch del menu principal. 
	}//Fin del while del menu principal. 
	
	
	
	return 0;
}//Fin del MAIN.





