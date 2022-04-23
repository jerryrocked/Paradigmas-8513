#include<iostream>
#include<string>
#include<string.h>
#include<strings.h>
#include<vector>
#include<sstream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

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

class Persona{
    public:
        string Nombre,Apellido,RUT;
        void Pedir_Datos();
};

void Persona::Pedir_Datos(){
        cout<<"Ingrese su nombre: ";
        cin>>Nombre;
        cout<<"\nIngrese su Apellido: ";
        cin>>Apellido;
        cout<<"\nIngrese su RUT: ";
        cin>>RUT;
        system ("CLS");
};

class Asignatura{
    public:
        string Nombre_Asignatura,Codigo,Seccion;
        float Nota;
        void Agregar_Asignatura();
        void Mostrar_Nota();
};

void Asignatura::Agregar_Asignatura(){
    cout<<"Asignaturas:"<<endl;
    cout<<"1.- Programacion"<<endl;
    cout<<"2.- Base de Datos"<<endl;
    cout<<"3.- Algoritmo y Estructura de datos"<<endl;
    cout<<"4.- Desarrollo web y mobil"<<endl;
    cout<<"5.- Paradigma de programacion"<<endl;
    cout<<"\nElija una opcion(1-5): ";
    cin>>Nombre_Asignatura;
    if (Nombre_Asignatura == "1"){
        Nombre_Asignatura = "Programacion";
        Codigo = "PR001";
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
    cout<<"Elija su seccion(1-2): ";
    cin>>Seccion;
    system ("CLS");
};

class Estudiante: public Persona, public Asignatura{
    public:
        vector <Asignatura> Asignaturas;
        int Cantidad_Clases;
        void Pedir_Clases();
        void Mostrar_Notas();
};

void Estudiante::Pedir_Clases(){
    cout<<"Ingrese la cantidad de clases que posee: ";
    cin>>Cantidad_Clases;
    for(int i = 0; i<Cantidad_Clases; i++){
        Asignatura Agregar;
        Agregar.Agregar_Asignatura();
        Asignaturas.push_back(Agregar);
    };
};

void Estudiante::Mostrar_Notas(){
    bool Encontrado, Aprobado;
    string Linea;
    vector <string> Texto;
    for(int i = 0; i < Cantidad_Clases; i++){
        Encontrado = false;
        Aprobado = false;
        ifstream Archivo_Notas(Asignaturas[i].Codigo+"_"+Asignaturas[i].Seccion+".txt");
        ofstream Archivo_Alumno(RUT+".txt");
        while (getline (Archivo_Notas, Linea)){
            Texto = split(Linea,' ');
            if (Texto[0] == RUT){
                Encontrado = true;
                if ((stof(Texto[1])) >= 4.0){
                    Aprobado = true;
                }
                Archivo_Alumno<<Asignaturas[i].Nombre_Asignatura<<" "<<Texto[1]<<" ";
                cout<<Asignaturas[i].Nombre_Asignatura<<" "<<Texto[1]<<" ";
                if (Aprobado == true){
                    cout<<"Aprobado"<<endl;
                    Archivo_Alumno<<"Aprobado"<<endl;
                }
                else if (Aprobado == false){
                    cout<<"Aprobado"<<endl;
                    Archivo_Alumno<<"Reprobado"<<endl;
                }
            }
        }
        if (Encontrado == false){
            cout<<Asignaturas[i].Nombre_Asignatura<<" "<<"NOTAS NO REGISTRADAS"<<endl;
            Archivo_Alumno<<Asignaturas[i].Nombre_Asignatura<<" "<<"NOTAS NO REGISTRADAS"<<endl;
        }
    }
};

class Profesor: public Persona, public Asignatura{
    public:
        string Nombre_Archivo;
        void Pedir_Nombre_Archivo();
};

void Profesor::Pedir_Nombre_Archivo(){

    string Linea;
    int Contador = 0;
    float Promedio;
    string Nombre_Archivo;
    vector <string> Texto;
    vector <pair<string,float> >Datos; // Par con los datos
    cout<<"Ingrese el nombre del archivo (Incluir .txt): ";
    cin>>Nombre_Archivo; // Text.txt por ejemplo
    system ("CLS");

    ifstream Archivo_Notas(Nombre_Archivo);
    ofstream Crear_Archivo(Codigo+"_"+Seccion+".txt");
    while (getline (Archivo_Notas, Linea)){
        Texto = split(Linea,' ');
        Promedio = (stof(Texto[3])) + (stof(Texto[4])) + (stof(Texto[5])) + (stof(Texto[6]));
        Promedio = Promedio/4;
        Promedio = roundf(Promedio * 100) / 100;
        Datos.push_back(make_pair(Texto[2],Promedio));
    }
    sort(Datos.begin(), Datos.end(), sortbysecdesc);
    int Largo = Datos.size();
    for(int i = 0; i<Largo; i++){
        if (Datos[i].second >= 4.0){
            Contador++;
        }
        cout<<Datos[i].first<<" "<<Datos[i].second<<endl;
        Crear_Archivo<<Datos[i].first<<" "<<Datos[i].second<<endl;
        
    }
    cout<<"Aprobados: "<<Contador<<endl<<"Reprobados: "<<Largo-Contador<<endl;
    cout<<"Notas Agregadas con exito!";
};

int main() {
    // Variables //
    int Opcion;
    Profesor Docente;
    Estudiante Alumno;

    // Menu //
    system ("CLS");
    cout<<"\tMenu\n"<<endl;
    cout<<"1.-Ingresar Notas"<<endl;
    cout<<"2.-Solicitar Notas"<<endl;
    cout<<"Elija una opcion: ";
    cin>>Opcion;
    system ("CLS");
    switch (Opcion)
    {
    case 1:
        Docente.Pedir_Datos();
        Docente.Agregar_Asignatura();
        Docente.Pedir_Nombre_Archivo();
        break;
    case 2:
        Alumno.Pedir_Datos();
        Alumno.Pedir_Clases();
        Alumno.Mostrar_Notas();
        break;
    }

}