/* Se desea modelar las filas de un banco, de cada persona se sabe el DNI y la operación que
desea realizar, según un menú de opciones las operaciones son depósitos(D), extracciones(E),
varios (O). Declare tres Queues de cada tipo de operación correspondiente.
A. Inicialmente la gente forma 1 fila, cuando comienza la atención las personas se distribuyen
según la operación, sacando un turno (botón “Simular turno”).
B. Modele estructura persona. Debe introducir por una pantalla un DNI, y elegir el tipo de
operación, según sea, se encola la persona para ser atendida en la fila correspondiente.
C. Otra función “atender”, ira sacando gente de la fila elegida por orden de llegada.
D. Se deben averiguar cuál es el último número agregado a cierta cola. Ej. Ultimo DNI en Extracción 
*/
#include <math.h>
#include <cstdlib>
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX=3;
struct cola{
   
	int Fila[MAX];  
    int cantidad=0;
    int P=0;
    int U=-1;

   
  public:
  	
	bool ColaVacia (){  
		bool error;
		if (cantidad==0)
		error = true;
		else
		error = false;
		return error;
	}
	
	bool ColaLlena (){
		bool error;
		if (cantidad==MAX)
		error = true;
		else{
			error=false;
			}
			return error;
		}
		
	void Encolar(int dato){
			if (cantidad!=MAX){
				U = (U+1%MAX);
				Fila[U]=dato;
				cantidad++;
			} else
			cout<<"No se puede insertar"<<endl;
		}
	
	void Desencolar (){   
		if (cantidad!=0){
			P=(P+1%MAX);
			cantidad--;
		}else	
			cout<<"No se puede eliminar";
	}
	
	int verPrimero (){   // FRONT
	   return Fila[P];
		
	}

	int verUltimo (){    // BACK
		return Fila[U];
	}  
	
	int getCantidad(){ 
	    cout<< cantidad; return cantidad;}
	
	 

}
cola,colae,colad,colav;





	



void DNI(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Extracciones"<<endl;
		cout<<"[2] -Depositos"<<endl;
		cout<<"[3] -Varios"<<endl;
		cout<<"[0] -VOLVER"<<endl;
		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: if (!colae.ColaLlena()){
				cout<<"Ingrese su numero de DNI: "<<endl;
				cin>>dato;
				colae.Encolar(dato);
				cout<<"DNI insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
			case 2: if (!colad.ColaLlena()){
				cout<<"Ingrese su numero de DNI: "<<endl;
				cin>>dato;
				colad.Encolar(dato);
				cout<<"DNI insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
			case 3: if (!colav.ColaLlena()){
				cout<<"Ingrese su numero de DNI: "<<endl;
				cin>>dato;
				colav.Encolar(dato);
				cout<<"DNI insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
				
			}	system("PAUSE");
	}while(op!=0); 	}

void Atender(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Atender Extracciones"<<endl;
		cout<<"[2] -Atender Depositos"<<endl;
		cout<<"[3] -Atender Varios"<<endl;
		cout<<"[0] -VOLVER"<<endl;

		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: if (!colae.ColaVacia()){
					cout<<"Primero de la fila atendido: "<<colae.verPrimero()<<endl;
					colae.Desencolar();}
					else cout<<"No hay fila"<<endl; break;
			case 2: if (!colad.ColaVacia()){
					cout<<"Primero de la fila atendido"<<colad.verPrimero()<<endl;
					colad.Desencolar();}
					else cout<<"No hay fila"<<endl; break;
			case 3: if (!colav.ColaVacia()){
					cout<<"Primero de la fila atendido"<<colav.verPrimero()<<endl;
					colav.Desencolar();}
					else cout<<"No hay fila"<<endl; break;
				
				
			}	system("PAUSE");
	}while(op!=0); 	}

void Averiguar(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Ultimo de la cola de Extracciones"<<endl;
		cout<<"[2] -Ultimo de la cola de Depositos"<<endl;
		cout<<"[3] -Ultimo de la cola de Varios"<<endl;
		cout<<"[0] -VOLVER"<<endl;
		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: cout<<"Ultimo de la cola: "<<colae.verUltimo()<<endl; break;
			case 2: cout<<"Ultimo de la cola: "<<colad.verUltimo()<<endl; break;
			case 3: cout<<"Ultimo de la cola: "<<colav.verUltimo()<<endl; break;
		
			
			}	system("PAUSE");
	}while(op!=0); 	}
	
	
	
int main(){

	int dato, op;
	
	do{
		system("cls");
		cout<<"[Menu de PRINCIPAL]"<<endl;
		cout<<"[1] -Simular Turno"<<endl;
		cout<<"[2] -Atender a los primeros de cada fila"<<endl;
		cout<<"[3] -Averiguar el ultimo numero de una cola"<<endl;
		cout<<"[0] -SALIR"<<endl;
		cin>>op;
		switch(op){ 
		
		case 1: {DNI( op, dato);
			break;}
		case 2:	{Atender( op,dato);
			break;}
		case 3: {Averiguar( op,dato);
			break;}	

		
	}	
	}while(op!=0);
	
	
	
	
	
	
	
	
	

	
	
	
return 0;}
