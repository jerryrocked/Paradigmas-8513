// Librerias
#include<iostream> 
#include<string>
#include<string.h>
#include<strings.h>
#include<vector>
#include<sstream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

//

// Este codigo se realizo en conjunto con Vicente Tudela 20.954.386-9

vector<string> split(string str, char delimiter) {  // Sacado de https://gist.github.com/cunhacas/b803bdcd295f0aea9864
    vector<string> internal;                        // Para manejar los archivos de manera mas facil
    stringstream ss(str); 
    string tok;

    while(getline(ss, tok, delimiter)) {        
        internal.push_back(tok);
    }
    
    return internal;
}

bool sortbysecdesc(const pair<string,float> &a, // Algoritmo sacado de https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-2-sort-in-descending-order-by-first-and-second/
                   const pair<string,float> &b)
{
       return a.second>b.second;
}

float round(float var) // Algoritmo sacado de https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

class Persona{      // Se crea la clase persona con sus Atributos y funciones
    public:
        string Nombre,Apellido,RUT;
        void Pedir_Datos(); // Se define la funcion para Pedir los datos de persona
};

void Persona::Pedir_Datos(){ // Se Solicitan datos de la persona (Estudiante/Profesor)
        cout<<"Ingrese su nombre: ";    // COUT es el Mensaje // CIN es el Input
        cin>>Nombre;
        cout<<"\nIngrese su Apellido: ";
        cin>>Apellido;
        cout<<"\nIngrese su RUT: ";
        cin>>RUT;
        system ("CLS");
};

class Asignatura{     // Se genera la clase Asignatura con sus atributos y funciones
    public:
        string Nombre_Asignatura,Codigo,Seccion;
        float Nota;
        void Agregar_Asignatura();  // Se define la funcion para agregar asignaturas (Profesor/Alumno)
};

void Asignatura::Agregar_Asignatura(){ //  Se solicitan los datos de la asignatura (1 para profesor y maximo 5 para el alumno)
    cout<<"Asignaturas:"<<endl;
    cout<<"1.- Programacion"<<endl;
    cout<<"2.- Base de Datos"<<endl;
    cout<<"3.- Algoritmo y Estructura de datos"<<endl;
    cout<<"4.- Desarrollo web y mobil"<<endl;
    cout<<"5.- Paradigma de programacion"<<endl;
    cout<<"\nElija una opcion(1-5): ";
    cin>>Nombre_Asignatura;
    if (Nombre_Asignatura == "1"){          // Se define el codigo (Ya que es solo 1) en base a la 
        Nombre_Asignatura = "Programacion"; // eleccion del nombre de la persona, el codigo sera utilizado
        Codigo = "PR001";                   // para la generacion de archivo al igual que la seccion
    }
    else if (Nombre_Asignatura == "2"){
        Nombre_Asignatura = "Base de Datos";
        Codigo = "BD002";
    }
    else if (Nombre_Asignatura == "3"){
        Nombre_Asignatura = "Algoritmo y Estructura de datos";
        Codigo = "AE003";
    }
    else if (Nombre_Asignatura == "4"){
        Nombre_Asignatura = "Desarrollo web y mobil";
        Codigo = "DM004";
    }
    else if (Nombre_Asignatura == "5"){
        Nombre_Asignatura = "Paradigma de programacion";
        Codigo = "PP005";
    }
    cout<<"Elija su seccion(1-2): "; // Se utilizara pra la generacion de archivo
    cin>>Seccion;
    system ("CLS");                 // Limpiar consola
};

class Estudiante: public Persona, public Asignatura{ // Se define el estudiante heredando de persona y asignatura
    public:
        vector <Asignatura> Asignaturas;            // Se genera un vector para almacenar cada asignatura que posea
        int Cantidad_Clases;                        // Se define la cantidad de clases que posee
        void Pedir_Clases();                        // Se define la funcion para pedir las clases
        void Mostrar_Notas();                       // Se define la funcion para mostrar notas por pantalla
};

void Estudiante::Pedir_Clases(){
    cout<<"Ingrese la cantidad de clases que posee: "; // Se solicita la cantidad de clases
    cin>>Cantidad_Clases;
    for(int i = 0; i<Cantidad_Clases; i++){            // Se van solicitando informacion de las clases y se van agregando a la Lista/Vector
        Asignatura Agregar;                            // Se define a la variable Asignatura como agregar
        Agregar.Agregar_Asignatura();                  // Se llama a la funcion para agregar los datos
        Asignaturas.push_back(Agregar);                // Se agrega a la lista de asignaturas
    };
};

void Estudiante::Mostrar_Notas(){                      // Se define la funcion mostrar notas

    bool Encontrado, Aprobado;                         // Se define la variable Encontrado, por si encuentra
                                                       // las notas en el archivo y se define la variable aprobado
                                                       // en caso de que tenga un promedio sobre igual a  4.0
    string Linea;                                      // Se define el string de las lineas del archivo a leer
    vector <string> Texto;                             // Se define el vector tipo string para dividir la linea del archivo
    for(int i = 0; i < Cantidad_Clases; i++){          // Se recorren las clases solicitadas en base a la cantidad que uso el usuario
        Encontrado = false;                            // Se define como falsa haber encontrado las notas para cada ciclo
        Aprobado = false;                              // Se define como falsa haber aprobado la asignatura para cada ciclo
        ifstream Archivo_Notas(Asignaturas[i].Codigo+"_"+Asignaturas[i].Seccion+".txt");    // Se lee el archivo en base al codigo y seccion de la asignatura
        ofstream Archivo_Alumno(RUT+".txt");           // Se genera el archivo con el RUT para guardar las notas del alumno
        while (getline (Archivo_Notas, Linea)){        // Se recorre el archivo de la seccion de la clase
            Texto = split(Linea,' ');                  // Se genera un vector con el string de la lista
            if (Texto[0] == RUT){                      // Se verifica el rut
                Encontrado = true;                     // Se define como encontrada las notas
                if ((stof(Texto[1])) >= 4.0){          // Se verifica el promedio para aprobar
                    Aprobado = true;
                }
                Archivo_Alumno<<Asignaturas[i].Nombre_Asignatura<<" "<<Texto[1]<<" ";   // Se escribe el nombre de la asignatura y el promedio en el archivo y se imprime
                cout<<Asignaturas[i].Nombre_Asignatura<<" "<<Texto[1]<<" ";             
                if (Aprobado == true){                                                  
                    cout<<"Aprobado"<<endl;                 // Se imprime por pantalla lo que se escribira
                    Archivo_Alumno<<"Aprobado"<<endl;       // Se escribe y se imprime si el alumno fue aprobado
                }
                else if (Aprobado == false){                
                    cout<<"Reprobado"<<endl;                 // Se escribe y se imprime si el alumno fue aprobado
                    Archivo_Alumno<<"Reprobado"<<endl;
                }
            }
        }
        if (Encontrado == false){       // Si no se encuentra el RUT (No encontro el archivo tambien) se crea el archivo y se imprime que no estan registradas las notas
            cout<<Asignaturas[i].Nombre_Asignatura<<" "<<"NOTAS NO REGISTRADAS"<<endl;
            Archivo_Alumno<<Asignaturas[i].Nombre_Asignatura<<" "<<"NOTAS NO REGISTRADAS"<<endl;
        }
    }
};

class Profesor: public Persona, public Asignatura{ // Se define la clase profesor que herda de Persona y Asignatura
    public:
        string Nombre_Archivo;          // Se define la variable del Archivo que usara el profesor
        void Pedir_Nombre_Archivo();    // Se define la funcion para pedir el nombre del archivo
};

void Profesor::Pedir_Nombre_Archivo(){  // Se crea la funcion para pedir nombre del archivo y generar un archivo con las notas correspondiente a la seccion y clase

    string Linea;                       // Se define la variable Linea que corresponde al string de cada linea del archivo
    int Contador = 0;                   // Se define el contador de aprobados/reprobados
    float Promedio;                     // Se define la variable promedio para ser usada en los archivos y en la variable de aprobados
    string Nombre_Archivo;              // Se define la variable del nombre del archivo con las notas
    vector <string> Texto;              // Se define el vector Texto para manejar mejor las lineas del archivo
    vector <pair<string,float> >Datos;  // Vector con un Par con los datos del alumno a revisar
    cout<<"Ingrese el nombre del archivo (Incluir .txt): "; // Se pide el nombre del archivo con las notas
    cin>>Nombre_Archivo;                                    // Text.txt por ejemplo
    system ("CLS");

    ifstream Archivo_Notas(Nombre_Archivo);             // Se lee el archivo con notas
    ofstream Crear_Archivo(Codigo+"_"+Seccion+".txt");  // Se crea el archivo de la clase
    while (getline (Archivo_Notas, Linea)){             // Se toma cada linea del archivo con las notas
        Texto = split(Linea,' ');                       // El string se pasa a vector
        Promedio = (stof(Texto[3])) + (stof(Texto[4])) + (stof(Texto[5])) + (stof(Texto[6]));   // Se suman las notas
        Promedio = Promedio/4;                          // Se divide por 4 (La cantidad de Notas)
        Promedio = roundf(Promedio * 100) / 100;        // Se redondea a la 2da decima
        Datos.push_back(make_pair(Texto[2],Promedio));  // Se agrega al vector de Datos
    }
    sort(Datos.begin(), Datos.end(), sortbysecdesc);    // Se ordenan de manera Desc
    int Largo = Datos.size();           // Se define el largo de los datos
    for(int i = 0; i<Largo; i++){       // Se comienza a reccorer los datos 1 por 1
        if (Datos[i].second >= 4.0){    // Se verifica si aprobo
            Contador++;                 // Si aprobo se agrega un aprobado al contador
        }
        cout<<Datos[i].first<<" "<<Datos[i].second<<endl;           // Se imprimen los datos
        Crear_Archivo<<Datos[i].first<<" "<<Datos[i].second<<endl;  // Se escriben los archivos
        
    }
    cout<<"Aprobados: "<<Contador<<endl<<"Reprobados: "<<Largo-Contador<<endl;  // Se imprimen los aprobados y reprobados
    cout<<"Notas Agregadas con exito!";                                         // Se muestra que se agregaron con exito las notas
};

int main() {
    // Variables //
    int Opcion; // Opcion que elija el usuario
    Profesor Docente;   // Se define una variable tipo clase Profesor
    Estudiante Alumno;  // Se define una variable tipo clase Estudiante

    // Menu //
    system ("CLS"); // Se limpia la consola
    cout<<"\tMenu\n"<<endl;
    cout<<"1.-Ingresar Notas"<<endl;
    cout<<"2.-Solicitar Notas"<<endl;
    cout<<"Elija una opcion: ";
    cin>>Opcion;    // Se solicita la opcion
    system ("CLS");
    switch (Opcion) // Switch case de cada opcion
    {
    case 1:                             // Caso Profesor (Ingresar Notas)
        Docente.Pedir_Datos();          // Se piden los datos al profesor
        Docente.Agregar_Asignatura();   // Se agrega una asignatura
        Docente.Pedir_Nombre_Archivo(); // Se pide el nombre del archivo, se calculan las notas y se genera el archivo con notas finales
        break;
    case 2:                             // Caso Alumno (Pedir Notas)
        Alumno.Pedir_Datos();           // Se piden los datos al Alumno
        Alumno.Pedir_Clases();          // Se pide la cantidad de clases y se agregan al Alumno
        Alumno.Mostrar_Notas();         // Se recorre cada clase y se verifica si existen las notas
        break;
    }
}