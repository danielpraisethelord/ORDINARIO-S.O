
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdio>

using namespace std;

void posxy(int x, int y);
void marcoxy(int largo,int ancho,int x,int y);
void terminarPrograma();
void centrarStr(string texto, int y);
void color(int x);
string intTostr (int n);
int strTostr2 (string texto);
string substr (string texto,int npos, int num);
void delay(int secs);
void izquierda(const char *texto, int y);
string intTostr(int n);
string mayusculas(string texto);
string minusculas(string texto);
void burbujaNumeros (float numeros[], int longitud);
void burbujaCadena(string arreglo[], int cantidad);
void setConsoleSize(int ancho, int largo);
void cuadriculaM( int filas , int columnas, int x, int y);
void cuadriculaMM(int filas, int columnas, int x, int y);
void evitarSaltoDeLinea();
string intTostr(int n);
int strToint2(string texto);
string substr2(string texto, int npos, int num);
string floatTostr(float valor);
int entero(float valor);
float decimal(float valor);
string rPad(string texto,char chr,int n);
string lPad(string texto, char chr, int n);
string floatTostr2(float n);




void posxy(int x, int y) {    // Esta funcion sirve para colocar texto en las coordenadas deseadas
	COORD coordenada;  //definimos la palabra a usar como variable para las coordenadas
	coordenada.X=x; //definimos la coordenada x usando la variable que definimos agregando .X para la coordenada x
	coordenada.Y=y; //definimos la coordenada y usando la variable que definimos agregando .Y para la coordenada y
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coordenada); //esto es lo que har� que el texto se imprima en las coordendas deseadas 
	}
	
void marcoxy(int largo, int ancho, int x, int y) {
    // Mover el cursor y en blanco y negro
    // al n�mero de filas "y" especificado
    for (int i = 0; i < y; i++) {
        cout << endl;
    }
    // Mover el cursor a la posici�n "x" especificada
    for (int i = 0; i < x; i++) {
        cout << " ";
    }

    // Imprimir la esquina superior izquierda del marco
    cout << char(201);
    // Imprimir los lados superiores del marco
    for (int i = 0; i < ancho - 2; i++) {
        cout << char(205);
    }
    // Imprimir la esquina superior derecha del marco
    cout << char(187) << endl;

    // Imprimir los lados izquierdos y derechos del marco
    // para la altura "largo" especificada
    for (int i = 0; i < largo - 2; i++) {
        // Mover el cursor a la posici�n "x" especificada
        for (int j = 0; j < x; j++) {
            cout << " ";
        }
        // Imprimir el borde izquierdo del marco
        cout << char(186);
        // Imprimir el interior del marco
        for (int j = 0; j < ancho - 2; j++) {
            cout << " ";
        }
        // Imprimir el borde derecho del marco
        cout << char(186) << endl;
    }

    // Mover el cursor a la posici�n "x" especificada
    for (int i = 0; i < x; i++) {
        cout << " ";
    }
    // Imprimir la esquina inferior izquierda del marco
    cout << char(200);
    // Imprimir los lados inferiores del marco
    for (int i = 0; i < ancho - 2; i++) {
        cout << char(205);
    }
    // Imprimir la esquina inferior derecha del marco
    cout << char(188) << endl;
}



void terminarPrograma(){  //Esta funcion sirve para terminar el programa una vez llamada la funcion


    cout << "Terminando programa..." << endl;
    exit(0); // La funci�n exit() con el argumento 0 indica que el programa termina correctamente
}


void centrarStr(string texto, int y) {
    // Obtener la longitud del texto a centrar
    int nlen = texto.length();
    // Calcular la posici�n "x" para centrar el texto en la pantalla
    int x = 59 - (nlen / 2);
    // Mover el cursor a la posici�n "x" y "y" especificada
    posxy(x, y);
    // Imprimir el texto centrado
    cout << texto;
}


void color(int x) {
    // Llamar a la funci�n "SetConsoleTextAttribute()" para establecer el color de texto en la consola
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    
    
    // La funci�n "color()" se utiliza para establecer el color del texto en la consola.
    //El par�metro "x" es el c�digo de color que se va a establecer. 
    //El primer par�metro de la funci�n "SetConsoleTextAttribute()" es "GetStdHandle(STD_OUTPUT_HANDLE)", que obtiene el identificador de la consola actual.
    //El segundo par�metro es "x", que es el c�digo de color que se va a establecer en la consola.
}

/* system("mode con: cols=85 lines=28") //No se incluye en la libreria, pero sirve para poner un limite en los margenes de la consola 
*/ 



int strTostr2 (string texto) {
    // Obtener un puntero al contenido de la cadena de texto
    const char *valor = texto.c_str();
    // Convertir el contenido de la cadena a un n�mero entero utilizando la funci�n "atoi()"
    int result = atoi(valor);
    // Devolver el n�mero entero resultante
    return result;
}


string substr(string texto, int npos, int num) {
    // Crear una cadena vac�a que se utilizar� para almacenar la subcadena resultante
    string result = "";
    // Obtener la longitud de la cadena de texto
    int nlen = texto.length();
    // Obtener un puntero al contenido de la cadena de texto
    const char* cad = texto.c_str();
    // Iterar a trav�s de los caracteres en la subcadena especificada
    for (int i = npos - 1; i < (npos - 1 + num); i++) {
        // Si la posici�n actual est� dentro de los l�mites de la cadena de texto,
        // agregar el car�cter correspondiente a la subcadena resultante
        if (i < nlen) {
            result += cad[i];
        }
    }
    // Devolver la subcadena resultante
    return result;
}


void delay(int secs){ // se utiliza para pausar la ejecuci�n del programa durante un n�mero determinado de segundos
    // Calcula el momento en el que deber� finalizar el delay
    int endTime = time(NULL) + secs;
    // Mientras el tiempo actual no sea igual al tiempo de finalizaci�n, contin�a esperando
    while (time(NULL) != endTime);
}

void izquierda(const char *texto, int y){ //se utiliza para imprimir texto en una posici�n espec�fica en la pantalla, alineado a la izquierda.
    // Calcula la longitud de la cadena de texto
    int nlen = strlen(texto);
    // Calcula la posici�n en x donde debe empezar a escribirse el texto
    int xPos = 79 - nlen;
    // Llama a la funci�n posxy() para colocar el cursor en la posici�n deseada
    posxy(xPos, y);
    // Escribe el texto en la posici�n calculada
    cout << texto;
}

string intTostr(int n){ // se utiliza para convertir un n�mero entero en un string. Los pasos que sigue la funci�n son:
    // Crea un objeto ostringstream llamado "stream"
    ostringstream stream;
    // Inserta el n�mero entero "n" en el objeto "stream"
    stream << n;
    // Convierte el objeto "stream" en un string y lo guarda en la variable "cadena"
    string cadena = stream.str();
    // Retorna el string resultante
    return cadena;
    
}



string mayusculas(string texto){

    
      int nlen = texto.length();
    // Recorre cada car�cter del string y lo convierte a may�sculas
    for(int i = 0; i < nlen; i++){
        texto[i] = toupper(texto[i]);
    }
    // Retorna el string convertido a may�sculas
    return texto;
}

string minusculas(string texto){
    // Se obtiene la longitud del texto
    int nlen = texto.length();
    
    // Se recorre cada caracter del texto
    for (int i = 0; i < nlen; i++){
        // Se convierte el caracter actual a min�scula
        texto[i] = tolower(texto[i]);
    }
    
    // Se retorna el texto en min�sculas
    return texto;
}


void burbujaNumeros(float numeros[], int longitud) {

    float aux;
    for (int i = 0; i < longitud; i++) {
        for (int j = 0; j < longitud - i - 1; j++) { 
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
    cout << aux; 
    
}


void burbujaCadena(string arreglo[], int cantidad) {
  for(int i = 0; i < cantidad-1; i++) {
    for(int j = 0; j < cantidad-i-1; j++) {
      if(arreglo[j] > arreglo[j+1]) {
        swap(arreglo[j], arreglo[j+1]);
      }
    }
  }
}

void cuadriculaM( int filas , int columnas, int x, int y){
	char c;
	for(int j=y;j<=(filas*2+y); j=j+2){
		for(int i=x; i<=(columnas*8+x); i++){
			
		c=196;
		posxy(i,j);cout<<c;
		}
	}		
	for(int j=y;j<=(filas*2+y); j++){
	for(int i=x; i<=(columnas*8+x); i=i+8){
		
		c=179;
		posxy(i,j);cout<<c;
 }
	}	
	c=218;//esquina superior izquierda
	posxy(x,y);cout<<c;
	c=192;//esquina inferior izquierda
	posxy(x,y+(filas*2));cout<<c;
	c=191;//esquina superior derecha
	posxy(columnas*8+x,y);cout<<c;
	c=217;//esquina inferior derecha
	posxy(columnas*8+x, filas*2+y);cout<<c;
	for(int j=(1);j<(filas); j++){
		for(int i=(1); i<(columnas); i++){
			//esquina superior
			c=194;
			posxy(i*8+x, y );cout<<c;
			//esquina inferior
			c=193;
			posxy(i*8+x, filas*2+y );cout<<c;	
			//Intersecciones
			c=197;
			posxy(i*8+x, j*2+y );cout<<c;
			//Esquinas izquierda
			c=195;
			posxy(x,j*2+y);cout<<c;
			//Esquina derecha
			c=180;
			posxy(columnas*8+x, j*2+y );cout<<c;
		}		
	}		
	}

void cuadriculaMM(int filas, int columnas, int x, int y) {
    char c;
    for(int j=y; j<=(filas*2+y); j=j+2) {
        for(int i=x; i<=(columnas*12+x); i++) {
            c = 196;
            posxy(i,j);
            cout << c;
        }
    }
    for(int j=y; j<=(filas*2+y); j++) {
        for(int i=x; i<=(columnas*12+x); i=i+7) {
            c = 179;
            posxy(i,j);
            cout << c;
        }
    }
    c = 218; // esquina superior izquierda
    posxy(x,y);
    cout << c;
    c = 192; // esquina inferior izquierda
    posxy(x,y+(filas*2));
    cout << c;
    c = 191; // esquina superior derecha
    posxy(columnas*12+x,y);
    cout << c;
    c = 217; // esquina inferior derecha
    posxy(columnas*12+x, filas*12+y);
    cout << c;
    for(int j=1; j<(filas); j++) {
        for(int i=1; i<(columnas); i++) {
            // esquina superior
            c = 194;
            posxy(i*12+x, y);
            cout << c;
            // esquina inferior
            c = 193;
            posxy(i*12+x, filas*2+y);
            cout << c;
            // intersecciones
            c = 197;
            posxy(i*12+x, j*2+y);
            cout << c;
            // esquinas izquierda
            c = 195;
            posxy(x, j*2+y);
            cout << c;
            // esquina derecha
            c = 180;
            posxy(columnas*12+x, j*2+y);
            cout << c;
        }
    }
}

void evitarSaltoDeLinea() {
    // Ignorar el carácter de nueva línea pendiente en el flujo de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string floatTostr2(float n){//pide un numero entero que trasnformara en string
	ostringstream stream;//se crea un objeto stream de tipo ostringstream que permite escribir datos en una cadena de caracteres
	stream<<n;//se inserta el numero n el stream
	string cadena= stream.str();//se devuelve una copia de la cadena que se ha estado escribiendo en el objeto stream,se almacena en un string
	return cadena;//se regresa el objeto cadena con el int transformado a string
}
int strToint(string texto){//se recibe una cadena de texto y lo trasnfroma a enteros
	const char *valor=texto.c_str();//se devuelve un puntero constante a una arreglo de caracteres que contiene la cadena del texto que recibimos
	int result=atoi(valor);//la funcion atoi convierte una cadena de caracteres en un numero entero, recibe el puntero que generamos anteriormente
	return result;//regresa un valor entero almacenado en result
}

string substr2(string texto, int npos, int num){//esta funcion substrae caracteres de un texto tomando en cuenta desde que posicion tomarlos y cuanto texto agarrar
	string result="";//se establece una cadena vacia
	int nlen=texto.length();//se obtiene la longitud del texto y se almacena en nlen
	const char* cad=texto.c_str();//se obtiene un puntero constante a la primera posicion de la cadena texto
	for (int i=npos-1;i<(npos-1+num);i++){//un for que empieza un caracter antes de donde le indicamos tomar el texto hasta el numero de caracteres que queriamos
		if(i<nlen) result+=cad[i];//aca se checa que i no sea mayor a la longitud del texto
		//y si i es menor,el caracter se agrega a la cadena result
	}
	return result;//finalemnte regresa la cadena de texto deseada
}


 

int entero(float valor){
    int nEntero = static_cast<int>(valor);
    return nEntero;
}


float decimal(float valor){
    int nEntero=entero(valor);
    float nDecimal=valor-nEntero;
    return nDecimal;
}
string rPad(string texto, char chr, int n) {
    string result = "";
    int nlen = texto.length();
    for (int i = 0; i < (n - nlen); i++) {
        result += chr;
    }
    result += texto;  // Agrega el texto original después del relleno
    return result;
}

string lPad(string texto, char chr, int n) {
    string result = texto;
    int nlen = texto.length();
    for (int i = 0; i < (n - nlen); i++) {
        result = chr + result;
    }
    return result;
}
