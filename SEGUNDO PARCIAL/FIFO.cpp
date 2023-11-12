#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int numFrames; // Número de marcos de página disponibles
    cout << "Ingrese el número de marcos de página: ";
    cin >> numFrames;

    queue<int> frames; // Cola para almacenar los marcos de página
    unordered_set<int> pageSet; // Conjunto para verificar la presencia de páginas en marcos
    vector<int> referenciaPaginas; // Vector para almacenar la secuencia de referencia de páginas

    // Leer la secuencia de referencia de páginas hasta que se ingrese un número negativo
    int pagina;
    cout << "Ingrese la secuencia de referencia de páginas (ingrese un número negativo para detenerse):\n";
    while (cin >> pagina && pagina >= 0) {
        referenciaPaginas.push_back(pagina);
    }

    int fallosDePagina = 0;
    int aciertosDePagina = 0;

    // Simulación de FIFO
    for (int pagina : referenciaPaginas) {
        if (pageSet.find(pagina) == pageSet.end()) {
            fallosDePagina++;
            if (frames.size() >= numFrames) {
                int paginaReemplazada = frames.front();
                frames.pop();
                pageSet.erase(paginaReemplazada);
            }
            frames.push(pagina);
            pageSet.insert(pagina);
        } else {
            aciertosDePagina++;
        }
    }

    cout << "Número de fallos de página: " << fallosDePagina << endl;
    cout << "Número de aciertos de página: " << aciertosDePagina << endl;

    return 0;
}
