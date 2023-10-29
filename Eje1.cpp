#include <iostream>
using namespace std;
#define tam 4

struct pila {
    int tope;
    char color[tam];
};

pila tubo1, tubo2, tubo3;

void init(pila &p) {
    p.tope = -1;
}

bool estaLlena(pila p) {
    return (p.tope == tam - 1);
}

bool estaVacia(pila p) {
    return (p.tope == -1);
}

void push(pila &p, char n) {
    if (!estaLlena(p)) {
        p.tope++;
        p.color[p.tope] = n;
    }
}

void pop(pila &p) {
    if (!estaVacia(p)) {
        p.tope--;
    }
    else
        cout << "La pila está vacía, no se puede desapilar." << endl;
}

char verTope(pila &p) {
    return p.color[p.tope];
}



//a. cargaTubo, que permita introducir datos en el cada uno de los tubos 

//lo llamariamos una vez para cada tubo
void cargaTubo(pila &tubo){
	char color;
	do{
		if( color=='S'){
			break;
		}
		if(estaLlena(tubo)){
			cout<<"Pila llena, no se pueden ingresar mas elementos"<<endl;
			color = 's';
			break;
			}else{
				cout<<"Ingrese Inicial en mayuscula V: Verde. R: Rojo. A: Amarillo. S: salir."<<endl;
				cin>> color;
					if( color == 'V' ||  color == 'A' ||  color== 'R'){
						push(tubo, color);	
					//	cout<< "Color ingresado:"<< verTope(tubo)<<endl;	
					}else{
						cout<<"DATO INCORRECTO , vuelva a ingresarlo..."<<endl;
					}
				}
	   }
		while( color!= 'S' );
}

//b. pasarPelota, pasa todos los elementos de Tubo1 a Tubo2

//pasa de tubo1 hacia el tubo2 todos los elementos de tubo1

void pasarPelota(pila &tubo1, pila &tubo2) {
  
    char elem;

    while (!estaVacia(tubo1)) {

        push(tubo2, verTope(tubo1));
        pop(tubo1);
        
    }

    
}

//c. hayColor, que recibe un color “rojo” y determina si está en la Tubo1, todos los elementos deben quedar nuevamente en Tubo1
void hayColor(pila &tubo1){
	char resp;
	do{
	cout<<"ingrese INICIAL(mayus) del color a buscar en el tubo"<<endl;
	cout<<" R: Rojo.  A: Amarillo  V: Verde  - S: Salir"<<endl;
	cin>> resp;
	} while(  resp!='R' || resp!='A' || resp!='V' || resp!='S');
	
	pila aux;
	init(aux);
	bool cumple=false;
	
	//paso todo a aux
	pasarPelota( tubo1, aux);
	
	while(!estaVacia(aux) &&  resp!='S' ){
		if(  verTope(aux) == resp  ){
			//si esta el color cumple es true , push al tubo1 y pop al aux
			cumple=true;
			push(tubo1, verTope(aux));
			pop(aux);
		}else{
			//Sino... solo push y pop
			push(tubo1, verTope(aux));
			pop(aux);
		}	
	};
	
	//Msj para el color ingresado si existe...o no
	if(cumple){
		cout<<"El color ingresado existe en el tubo1"<<endl;
	}else{
		cout<<"El color ingresado NO existe en el tubo1"<<endl;

	}
	
}

//d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás.
void colorear(pila &tubo1, pila &tubo2, pila &tubo3){
	
	//agrego colores como los tubos en el ejemplo...
	push(tubo1, 'V');
	push(tubo1, 'R');
	push(tubo1, 'A');
	push(tubo1, 'R');
	
	push(tubo2, 'V');
	push(tubo2, 'A');
	
	push(tubo3, 'A');
	push(tubo3, 'R');
	push(tubo3, 'R');
	
	//vacio el tubo1 para pasarle luego lo del tubo2
	pila aux;
	pasarPelota(tubo1, aux);
	//tubo2 vacio para recibir pelotitas rojas
	pasarPelota(tubo2,tubo1);
	
	while(!estaVacia(aux)){
	char elem= verTope(aux);
	if(elem == 'R'){
		push(tubo2, elem);
		pop(aux);
	}else if(!estaLlena(tubo1)){
		push(tubo1, elem);
		pop(aux);
	}
	
	};
	
	while(!estaVacia(tubo3)){
	char elem= verTope(tubo3);
	if(elem == 'R'){
		push(tubo2, elem);
		pop(tubo3);
	}else if(!estaLlena(aux)){
		push(aux, elem);
		pop(tubo3);
	}
	
	};
	
	
	if(!estaLlena(tubo3)){
		while( !estaLlena(tubo3)){
			char elem= verTope(aux);
			push(tubo3, elem);
			pop(aux);
		};
	}
	
	
	
	
}


int main() {
    init(tubo1);
    init(tubo2);
    init(tubo3);
    
	//agrego los colores como los tubos en la foto
	push(tubo1, 'V');
	push(tubo1, 'R');
	push(tubo1, 'A');
	push(tubo1, 'R');
	
	

    
  	//cargaTubo(tubo1);
  	
	pasarPelota(tubo1, tubo2);
	
	

     return 0;

}