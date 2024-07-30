#include<iostream>
#include<unistd.h>
#include<sys/ioctl.h>
#include "t.cpp"

using namespace std;

int main() {
    int a = 0;
    char grid[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    Jugador p[2] = { {0, ""}, {0, ""} };

    title();
    cout << "\nIngrese sus nombres:\n";
    cout << "Player 1: ";
    cin >> p[0].nombre;
    cout << "Player 2: ";
    cin >> p[1].nombre;
    cout << "\nLas coordenadas son:"<< endl;
    tablero();

    do {
        line();
        title();
        menu();
        cin >> a;
        line();

        switch (a) {
            case 1: {
                int player = 1, coordenada;
                while (true) {
                    mostrarTablero(grid);
                    cout << "Player " << (player % 2 == 1 ? p[0].nombre : p[1].nombre) << ": \nIngrese la coordenada: ";
                    cin >> coordenada;

                    if(coordenada < 1 || coordenada > 9 || grid[coordenada - 1] != ' '){
                        cout << "Coordenada inválida, por favor intente de nuevo: ";
                        cin >> coordenada;
                    }
                    if (player%2 != 0){
                        grid[coordenada-1]= 'X';
                    }else{
                        grid[coordenada-1]= 'O';
                    }

                    if (comprobarGanador(grid)) {
                        mostrarTablero(grid);
                        cout << "Player " << (player % 2 == 1 ? 1 : 2) << " gana!\n";
                        (player % 2 == 1 ? p[0].punt : p[1].punt)++;
                        break;
                    }

                    if (player == 9) {
                        mostrarTablero(grid);
                        cout << "Es un empate!\n";
                        break;
                    }

                    player++;
                }

                // Reiniciar el tablero para una nueva partida
                fill(begin(grid), end(grid), ' ');
                break;
            }
            case 2: {
                mostrarPuntajes(p);
                break;
            }
            case 3: {
                creditos();
                break;
            }
            case 4: {
                cout << "\nGracias por jugar!\n\n";
                line();
                break;
            }
            default: {
                cout << "Opción no válida, por favor intente de nuevo.\n";
                break;
            }
        }
    } while (a != 4);

    return 0;
}
