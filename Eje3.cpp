#include <iostream>
using namespace std;
#define tam 10

struct autoInfo {
    char placa[10];
    char propietario[30];
    char horaEntrada[10];
};

struct pila {
    int tope;
    autoInfo pilaDatos[tam]; // Declarar un arreglo de tipo autoInfo para almacenar los datos
};

void init(pila &p) {
    p.tope = -1;
}

bool estaLlena(pila p) {
    return (p.tope == tam - 1);
}

bool estaVacia(pila p) {
    return (p.tope == -1);
}

void push(pila &p, autoInfo &a) {
    if (!estaLlena(p)) {
        p.tope++;
        p.pilaDatos[p.tope] = a; // Almacenar la estructura autoInfo en el arreglo
    } else {
        cout << "la pila está llena" << endl;
    }
}

void pop(pila &p) {
    if (!estaVacia(p)) {
        p.tope--;
    } else {
        cout << "La pila está vacía, no se puede desapilar." << endl;
    }
}

autoInfo verTope(pila &p) {
    if (!estaVacia(p)) {
        return p.pilaDatos[p.tope];
    } else {
        autoInfo vacio;
        cout << "La pila está vacía, no se puede ver el tope." << endl;
        return vacio;
    }
}

/* 3. Suponga que administra un estacionamiento en forma de callejón(pila), cuenta con Cochera1, 
Cochera2 para 10 autos cada una, ambas solamente tienen una puerta de entrada/salida, y 
que el valor hora es $100- Se diseña una estructura auto con los datos: placa, propietario, y 
hora de entrada. 
A- Si desea estacionar un auto en Cochera1 o Cochera2, el sistema solicita sus datos, y agrega. */

//metodo secundario para metodo ingreso:
void cargarDatos(pila &cochera) {
	
    if (!estaLlena(cochera) ) {
     autoInfo a;
        cout << "Ingrese la patente del vehículo: ";
        cin.ignore(); // Limpia el búfer de entrada
        cin.getline(a.placa, 10);

        cout << "Ingrese nombre y apellido del propietario: ";
        cin.ignore(); // Limpia el búfer de entrada
        cin.getline(a.propietario, 30);

        cout << "Ingrese la hora de ingreso (ejemplo: 13:40): ";
        cin.ignore(); // Limpia el búfer de entrada
        cin.getline(a.horaEntrada, 6);

        push(cochera, a);
        
        cout<<"Auto ingresado"<<endl;
        
    } else {
        cout << "Cochera completa, no hay lugar." << endl;
    }
}



void ingreso(pila &cochera1, pila &cochera2) {
    int resp = 0;
    
 
   do {
    cout << "Para ingresar un coche: Ingresar 1 para Cochera1. Ingresar 2 para Cochera2. Ingrese 3 para Salir: ";
    cin >> resp;
} while (resp != 1 && resp != 2 && resp != 3);


    if (resp == 1) {
        cargarDatos(cochera1);
    } else if (resp == 2) {
        cargarDatos(cochera2);
    }
}

//B- Habrá un procedimiento para mostrar las cocheras por orden de salida de los vehículos. */

void mostrarCocheras(pila &cochera1, pila &cochera2){
	
	pila aux;
	int resp=0;
	

	
	do{
		cout<<"Ingrese la cochera que desea ver"<<endl;
		cout<<" 1 para Cochera1 - 2 para Cochera2 - 3 para Salir"<<endl;
		cin>>resp;
	}while(resp!=1 || resp!=2 || resp!=3);
	
	if(resp==1){
		
			if(!estaVacia(cochera1)){
		
   	    	autoInfo vehiculo = verTope(cochera1);

            cout << "Patente: " << vehiculo.placa << endl;
            cout << "Propietario: " << vehiculo.propietario << endl;
            cout << "Hora de entrada: " << vehiculo.horaEntrada << endl;
            cout << "-------------" << endl;
            push(aux, vehiculo);
            
            pop(cochera1);	
			}else{
				cout<<"Cochera1 vacia, no hay autos "<<endl;
			}
		}
		
		if(resp==2){
			if(!estaVacia(cochera2)){
		
   	   		 autoInfo vehiculo = verTope(cochera2);

            cout << "Patente: " << vehiculo.placa << endl;
            cout << "Propietario: " << vehiculo.propietario << endl;
            cout << "Hora de entrada: " << vehiculo.horaEntrada << endl;
            cout << "-------------" << endl;
            push(aux, vehiculo);
            
            pop(cochera2);
		
			}else{
				cout<<"Cochera2 vacia, no hay autos "<<endl;
			}		
			
		}else{
			cout<<" Programa finalizado, adios..."<<endl;
		}
		
}

int main() {
    pila cochera1;
    pila cochera2;

    init(cochera1);
    init(cochera2);

    int opcion;
    bool a=true;
    while (a) {
        cout << "Opciones:" << endl;
        cout << "1. Ingresar auto" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion;
        if (opcion == 1) {
            ingreso(cochera1, cochera2);
        } else if (opcion == 2) {
            a=false; 
        }
    }

    return 0;
}

