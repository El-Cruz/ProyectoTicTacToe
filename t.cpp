#include<iostream>
#include<unistd.h>
#include<sys/ioctl.h>

using namespace std;

void line() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int cols = w.ws_col;
    for (int i = 0; i < cols; ++i) {
        cout << '-';
    }
    cout << endl;
}

void title() {
    cout << "\t\t TIC TAC TOE\n";
}

void menu() {
    cout << "\nSeleccione una opción:";
    cout << "\n1. Jugar";
    cout << "\n2. Puntajes";
    cout << "\n3. Créditos";
    cout << "\n4. Salir\n";
}

void creditos() {
    cout << "\nCreditos:\n";
    cout << "Nicolás Cruz\n";
    cout << "Jeremmy Salinas\n";
}
struct Jugador {
    int punt;
    string nombre;
};

bool comprobarGanador(char grid[]) {
    // Comprobar filas
    for (int i = 0; i < 9; i += 3) {
        if (grid[i] != ' ' && grid[i] == grid[i + 1] && grid[i] == grid[i + 2]) {
            return true;
        }
    }
    // Comprobar columnas
    for (int i = 0; i < 3; ++i) {
        if (grid[i] != ' ' && grid[i] == grid[i + 3] && grid[i] == grid[i + 6]) {
            return true;
        }
    }
    // Comprobar diagonales
    if (grid[0] != ' ' && grid[0] == grid[4] && grid[0] == grid[8]) {
        return true;
    }
    if (grid[2] != ' ' && grid[2] == grid[4] && grid[2] == grid[6]) {
        return true;
    }
    return false;
}

void mostrarTablero(char grid[]) {
    cout << " " << grid[0] << " | " << grid[1] << " | " << grid[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << grid[3] << " | " << grid[4] << " | " << grid[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << grid[6] << " | " << grid[7] << " | " << grid[8] << " \n";
}

void tablero(){
    cout << " " << "1" << " | " << "2" << " | " << "3" << " \n";
    cout << "---+---+---\n";
    cout << " " << "4" << " | " << "5" << " | " << "6" << " \n";
    cout << "---+---+---\n";
    cout << " " << "7" << " | " << "8" << " | " << "9" << " \n";
}

void mostrarPuntajes(Jugador p[]) {
    cout << "\nPuntajes:\n";
    cout << p[0].nombre << ": " << p[0].punt << " puntos\n";
    cout << p[1].nombre << ": " << p[1].punt << " puntos\n";
}