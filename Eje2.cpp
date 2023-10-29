#include <iostream>
using namespace std;
 #define tam 5
#include <stack>


struct pila {
    int tope;
    int num;
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

void push(pila &p, int n) {
    if (!estaLlena(p)) {
        p.tope++;
        p.num = n;
    }
}

void pop(pila &p) {
    if (!estaVacia(p)) {
        p.tope--;
    }
}

int verTope(pila &p) {
    if (!estaVacia(p)) {
        return p.num;
    } 
    return 0;
}

/*PUNTO A :
a. InvierteConAux, Dada una Pila A con números, una Pila B y una Pila C vacías, pasar los
elementos de A a B de manera que queden en el mismo orden que estaban en A. 
(Se permite utilizar la pila C como auxiliar)*/

pila invertirPilasMismoOrden(pila &pilaA, pila &pilaB, pila &pilaC) {
    int elem = 0;
  	//los paso a c, quedan en orden invertido, luego a b y quedan en el mismo orden
  	while(!estaVacia(pilaA)){
  		elem = verTope(pilaA);
  		
  		push(pilaC, elem);
  		pop(pilaA);
	  };
	  
	  while(!estaVacia(pilaC)){
  		elem = verTope(pilaC);
  		
  		push(pilaB, elem);
  		pop(pilaC);
	  };
	return pilaB;
}

/* b. InvierteSinAux, que dada una PilaA, una variable X y una Pila Vacía B. Pasar los elementos 
de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden (original) en pilaA. */

void invertirSinTercerStack(stack<int>& pilaA, stack<int>& pilaB) {
    // Paso 1: Copiar los elementos de pilaA a pilaB en orden inverso usando una variable temporal
    while (!pilaA.empty()) {
        int elemento = pilaA.top();
        pilaA.pop();

        // Paso 2: Desplazar los elementos de pilaB de regreso a pilaA
        while (!pilaB.empty()) {
            pilaA.push(pilaB.top());
            pilaB.pop();
        }

        // Paso 3: Colocar el elemento en pilaB
        pilaB.push(elemento);
    }
}
		
	pila aux ;
//c. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo otro “Y” */
void  intercambiarSiExiste(pila &pila, int buscar, int ingresar){
	
	int elem=0;

	
	while(!estaVacia(pila)){
		push(aux, verTope(pila));
		pop(pila);		
	};
	
	while(!estaVacia(aux)){
		
		elem= verTope(aux);
		if(elem == buscar){
			push(pila, ingresar);
			pop(aux);
		}else{
			push(pila,elem);
			pop(aux);
		}
	};
}


/*. Se tienen pilaA, pilaB, pilaC con enteros, y los procedimientos o funciones son:
a. InvierteConAux, Dada una Pila A con números, una Pila B y una Pila C vacías, pasar los
elementos de A a B de manera que queden en el mismo orden que estaban en A. 
(Se permite utilizar la pila C como auxiliar)
b. InvierteSinAux, que dada una PilaA, una variable X y una Pila Vacía B. Pasar los elementos 
de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden (original) en pilaA.
c. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo otro “Y” */

pila pilaA, pilaB, pilaC ;

int main() {
    init(pilaA);
    init(pilaB);
    init(pilaC);
	
	
  	push(pilaA, 0);
  	push(pilaA, 10);
  	push(pilaA, 20);
  	push(pilaA, 30);
  	push(pilaA, 40);
  	

    invertirPilasMismoOrden(pilaA, pilaB, pilaC);
    
	

     return 0;

}