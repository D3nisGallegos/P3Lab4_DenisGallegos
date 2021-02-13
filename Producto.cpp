#include <string>

using namespace std; 

class Producto{
	
	private :
		int id; 
		string nombre; 
		string categoria; 
		int cantidad; 
		double precio; 
	
	public: 
	
	Producto(){
		
	}//Fin del constrcutor. 
	
	Producto(int iden, string name, string categ, int cant, double price){
		id = iden; 
		nombre = name;
		categoria = categ; 
		cantidad = cant; 
		precio = price; 
	}
	
	int GETid(){
		return id; 
	}
	
	void SETid(int x){
		id = x; 
	}
	
	int GETcantidad(){
		return cantidad; 
	}
	
	void SETcantidad(int x){
		cantidad = x; 
	}
	
	string GETnombre(){
		return nombre; 
	}
	
	void SETnombre(string x){
		nombre = x; 
	}
	
	string GETcategoria(){
		return categoria; 
	}
	
	void SETcategoria(string x){
		categoria = x; 
	}
	
	double GETprecio(){
		return precio; 
	}
	
	void SETprecio(double x){
		
		precio = x; 
	}
	
};


