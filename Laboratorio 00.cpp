#include <iostream>
#include <vector>
using namespace std;

//clase laberinto para simular el movimiento de un laberinto
class Laberinto {
private:
    //propiedades; el mapa del laberinto y la posicion del jugador 
    vector<vector<char>> mapa;
    int jugadorX, jugadorY;
public:
    Laberinto(){
		//usamos el constructor para crear el laberinto simple de 10 * 10 puede modificarse a gusto, se pueden agregar mas paredes 
        mapa = {
            {'#','#','#','#','#','#','#','#','#','#'},
            {'#','J',' ',' ',' ','#','#','#','H','#'},
            {'#','#','#',' ',' ','#','#','#',' ','#'},
            {'#',' ',' ',' ',' ',' ','#','#',' ','#'},
            {'#',' ','#','#','#',' ','#','#',' ','#'},
            {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
            {'#',' ',' ',' ','#','#','#','#',' ','#'},
            {'#','#','#',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#'},
            {'#','#','#','#','#','#','#','#','#','#'}
        };

        //posicion inicial donde estara el jugador
        jugadorX = 1;
        jugadorY = 1;
    }

	//metodo para mostar el laberinto al ejecutar el programa
    void mostrar() {
        for (int i = 0; i < mapa.size(); i++) {          //recorre las filas 
            for (int j = 0; j < mapa[i].size(); j++) {   //recorre las columnas
                cout << mapa[i][j];                      //nos permite generar cada caracter del laberinto creado
            }
            cout << endl;                               
        }
    }

    //metodo para mover al jugador segun la tecla ingresada
    bool mover(char direccion) {
        int nuevoX = jugadorX;
        int nuevoY = jugadorY;

        //control de movimiento segun la tecla ingresada
        if (direccion == 'W' || direccion == 'w') nuevoX--;       //arriba
        else if (direccion == 'S' || direccion == 's') nuevoX++;  //abajo
        else if (direccion == 'A' || direccion == 'a') nuevoY--;  //izquierda
        else if (direccion == 'D' || direccion == 'd') nuevoY++;  //derecha
        else {
			//si se ingresa otra tecla aparte de w, a, s, d no se muve y se muestra el mensaje de error
            cout << "Movimiento no valido, intente de nuevo.\n";
            return false;
        }

		//como estamos usando # verificamos si es pared o no, si es pared no se mueve y se muestra el mensaje de error
        if (mapa[nuevoX][nuevoY] == '#') {
            cout << "Pared!!! No puedes pasar.\n";
            return false;
        }

        //para la salida usmos la H la cual es la salida
        if (mapa[nuevoX][nuevoY] == 'H') {
            cout << "Has llegado a la salida!\n";
            return true;
        }

        //actualizamos la posicion del jugador
        mapa[jugadorX][jugadorY] = ' ';   //bora la posicion anterior
        jugadorX = nuevoX;                //actualiza fila
        jugadorY = nuevoY;                //actualiza columna
        mapa[jugadorX][jugadorY] = 'J';   //coloca al jugador en la nueva posicion
        return false;
    }
};

int main() {
	Laberinto lab;          //este objeto nos permite cear el laberinto y controlar el movimiento del jugador
	bool terminado = false; //controla si el juego termino o el jugador llego a la salida
    char movimiento;        //almacena la tecla ingresada

    cout << "Usa W (arriba), S (abajo), A (izquierda), D (derecha)\n";
    while (!terminado) {
        lab.mostrar();                  //muestra el laberinto creado
        cout << "Movimiento: ";
		cin >> movimiento;              //pide al usuario una tecla ente w, a, s, d para mover al jugador
        terminado = lab.mover(movimiento); //da movimiento al jugador
    }
    return 0;
}