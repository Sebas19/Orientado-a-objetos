#include <iostream>
#include <cmath>

using namespace std;
template < class TipoLista > class Lista{
public:
	TipoLista datos;
	Lista *head;
	Lista *tail;
	Lista *sig;
	Lista *ant;
	void init(){
		cout << "Lista creada" << endl;
		head = 0;
		tail = 0;
		sig = 0;
		ant = 0;
		sig = new Lista;
		ant = new Lista;
		head = new Lista;
		tail = new Lista;
		head->sig = tail;
		head->ant = head;
		tail->sig = tail;
		tail->ant = head;
	}
	void recorrido();
	void Inserta(TipoLista nelem);
	bool Eliminacion(TipoLista nelem);
	bool busca(TipoLista nelem);
};
class complejo {
public:
	double preal;
	double pimag;
	complejo(){}
	/*complejo(double x, double y){
		preal = x;
		pimag = y;
	}*/
	init(double x,double y){
		preal = x;
		pimag = y;
	}

};
bool operator<(complejo a,complejo b){

	if(sqrt(pow(a.preal,2) + pow(a.pimag,2)) < sqrt((pow(b.preal,2) + pow(b.pimag,2)))) {
		return true;
	}
	return false;
}
bool operator==(complejo a,complejo b){
	if(a.preal==b.preal && a.pimag==b.pimag){
		return true;
	}
	return false;
}
bool operator!=(complejo a,complejo b){
	if(a.preal!=b.preal && a.pimag!=b.pimag){
		return true;
	}
	return false;
}
template < class TipoLista > void Lista <TipoLista>::recorrido(){
	if(head->sig==tail){cout<<"vacia"<<endl;return;}
	cout << "impresion recorrido" << endl;
	Lista *aux = 0;
	aux = new Lista;
	aux = head;
	while(aux->sig!=tail){
		cout << "impresion while recorrido"  << endl;
		cout <<"Parte real: "<< aux->sig->datos.preal <<" i: "<< aux->sig->datos.pimag << endl;
		aux = aux->sig;
	}

}
template < class TipoLista > void  Lista <TipoLista>::Inserta(TipoLista nelem){
     cout << "impresion inserta" << endl;
     Lista *aux = 0,*nuevo = 0;
      cout << "impresion inserta" << endl;
	aux = new Lista;
	nuevo=new Lista;
	 cout << "impresion inserta" << endl;
	aux = head;
	 cout << "impresion inserta" << endl;
	 cout << "impresion inserta" << endl;
	while(aux->sig->datos < nelem && aux->sig != tail){
		cout << "impresion while inserta" << endl;
		aux = aux->sig;
	}
	nuevo->datos = nelem;
	nuevo->sig = aux->sig;
	nuevo->ant = aux;
	aux->sig = nuevo;
	nuevo->sig->ant = nuevo;
	///*aux = nelem	;
}
template < class TipoLista > bool  Lista <TipoLista>::busca(TipoLista nelem){
	 Lista *aux;
	 aux = new Lista;
	 aux = head;
	 while(aux->sig->datos != nelem && aux->sig != tail ){
	 	aux = aux->sig;
	 }
	 if(aux->sig->datos == nelem) return true;
	 return false;
}
template < class TipoLista > bool  Lista <TipoLista>::Eliminacion(TipoLista nelem){
	if(busca(nelem) && head->sig != tail){
		///recorrido
		Lista *aux;
		aux = new Lista;
		aux = head;
		while(aux->sig->datos != nelem){
			aux = aux->sig;
		}
		aux->sig = aux->sig->sig;
		aux->ant = aux->sig->ant->ant;
		delete aux->sig->ant;
		aux->sig->ant  = aux->ant;
		aux->ant->sig = aux->sig;
		delete aux;
		return true;
	} else {
		return false;
	}
	
}

Lista <complejo> equis;
int main(){
	equis.init();
	///cout << "impresion main" << endl;
	complejo c1;
	c1.init(10,10);
	equis.Inserta(c1);
	complejo c2;
	c2.init(20,20);
	equis.Inserta(c2);
	if(equis.busca(c1)){cout<<"encontrado"<<endl;}
	else{cout<<"false"<<endl;}
	if(equis.Eliminacion(c1)){cout<<"eliminado"<<endl;}
	else{cout<<"false"<<endl;}
	equis.recorrido();
	if(equis.busca(c1)){cout<<"encontrado"<<endl;}
	else{cout<<"false"<<endl;}
	/*if(equis.busca(c1)){cout<<"encontrado"<<endl;}
	else{cout<<"false"<<endl;}
	if(equis.Eliminacion(c1)){cout<<"eliminado"<<endl;}
	else{cout<<"false"<<endl;}*/
	//equis.recorrido();
	////equis.recorrido();
	///cout << "impresion main" << endl;
	/*equis.Inserta(20);
	if(equis.busca(10)){cout<<"encontrado"<<endl;}
	else{cout<<"false"<<endl;}
	if(equis.Eliminacion(10)){cout<<"eliminado"<<endl;}
	else{cout<<"false"<<endl;}
	if(equis.Eliminacion(20)){cout<<"eliminado"<<endl;}
	else{cout<<"false"<<endl;}
	equis.recorrido();*/
	return 0;
}
