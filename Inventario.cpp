#include <vector>
#include <string>
#include "Producto.cpp"

using namespace std; 

class Inventario{
	
	private: 
	
	vector <Producto*> productos; 
	vector <string> categorias;
	
	public: 
	
	Inventario(){
		
	}//Fin del constructor. 
	
	Inventario(vector <Producto*> producto, vector <string> categ){
		productos = producto;
		categorias = categ; 
	}//Fin del constructor.
	
	void Agregarproducto(Producto* x){
		productos.push_back(x);
	}
	
	vector <Producto*> GETproductos(){
		return productos; 
	} 
	
	void SETproductos(vector <Producto*> x){
		productos = x; 
	} 
	
	vector <string> GETcategorias(){
		return categorias; 
	} 
	
	void SETcategorias(vector <string> x){
		categorias = x; 
	} 
	
	
};
