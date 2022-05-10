// Tomas Stange Alvarez


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
int opcion;
cout << "Ingrese una opcion: " << endl;
cout << "Profesor: (1)" << endl;
cout << "Estudiante: (2)" << endl;
cout << "Salir: (3)" << endl;
cin >> opcion;
switch(opcion){
    case 1:
    {
    cout << "--------------Profesor---------------" << endl;
    cout << "¿Desea cargar archivos preexistentes al sistema? (1)" << endl;
    cout << "¿Desea cargar manualmente las notas en el sistema (2)" << endl;
    int opcprofesor;
    cin >> opcprofesor;
    switch(opcprofesor){
        case 1:
        {
        string nam; // Nombre de la asignatura
        string rpm; // Rut del profesor
        string nat; // Nombre archivo texto
        string sec; // Seccion de la asignatura
        cout << "Introduzca el nombre del archivo de texto a cargar en el sistema: " << endl;
        cin >> nat;
        cout << "Ingrese el nombre de la asignatura: ";
        cin >> nam;
        cout << "Ingrese la seccion de la asignatura: ";
        cin >> sec;
        cout << "Ingrese su rut: ";
        cin >> rpm;
        ifstream archivo(nat);
        
        // Variables para los estudiantes

        string e1;
        string e2;
        string e3;
        string e4;
        string e5;

        // Tomar la linea de cada estudiante

        getline(archivo,e1);
        getline(archivo,e2);
        getline(archivo,e3);
        getline(archivo,e4);
        getline(archivo,e5);

        // Largo de las lineas de cada estudiante y asignatura

        int le1 = e1.length();
        int le2 = e2.length();
        int le3 = e3.length();
        int le4 = e4.length();
        int le5 = e5.length();

        // Extraer cada nota del estudiante 1

        string n1e1 = e1.substr((le1 - 15),3); 
        string n2e1 = e1.substr((le1 - 11),3); 
        string n3e1 = e1.substr((le1 - 7),3); 
        string n4e1 = e1.substr((le1 - 3),3);

        // Extraer nombre del estudiante 1

        string nombe1 = e1.substr(0,(le1 - 29));

        // Extraer rut del estudiante 1

        string rute1 = e1.substr((le1 - 28),12);


        // Covertir de las notas del estudiante 1 de string a float

        float e1n1;
        istringstream(n1e1) >> e1n1;
        float e1n2;
        istringstream(n2e1) >> e1n2;
        float e1n3;
        istringstream(n3e1) >> e1n3;
        float e1n4;
        istringstream(n4e1) >> e1n4;

        // Extraer cada nota del estudiante 2

        string n1e2 = e2.substr((le2 - 15),3); 
        string n2e2 = e2.substr((le2 - 11),3); 
        string n3e2 = e2.substr((le2 - 7),3); 
        string n4e2 = e2.substr((le2 - 3),3);

        // Extraer nombre del estudiante 2

        string nombe2 = e2.substr(0,(le2 - 29));
        
        // Extraer rut del estudiante 2

        string rute2 = e2.substr((le2 - 28),12);

        // Covertir de las notas del estudiante 2 de string a float

        float e2n1;
        istringstream(n1e2) >> e2n1;
        float e2n2;
        istringstream(n2e2) >> e2n2;
        float e2n3;
        istringstream(n3e2) >> e2n3;
        float e2n4;
        istringstream(n4e2) >> e2n4;

        // Extraer cada nota del estudiante 3

        string n1e3 = e3.substr((le3 - 15),3);
        string n2e3 = e3.substr((le3 - 11),3); 
        string n3e3 = e3.substr((le3 - 7),3); 
        string n4e3 = e3.substr((le3 - 3),3);

        // Extraer nombre del estudiante 3

        string nombe3 = e3.substr(0,(le3 - 29));

        // Extraer rut del estudiante 3

        string rute3 = e3.substr((le3 - 28),12);

        // Covertir de las notas del estudiante 3 de string a float

        float e3n1;
        istringstream(n1e3) >> e3n1;
        float e3n2;
        istringstream(n2e3) >> e3n2;
        float e3n3;
        istringstream(n3e3) >> e3n3;
        float e3n4;
        istringstream(n4e3) >> e3n4;

        // Extraer cada nota del estudiante 4

        string n1e4 = e4.substr((le4 - 15),3); 
        string n2e4 = e4.substr((le4 - 11),3); 
        string n3e4 = e4.substr((le4 - 7),3); 
        string n4e4 = e4.substr((le4 - 3),3);

        // Extraer nombre del estudiante 4

        string nombe4 = e4.substr(0,(le4 - 29));

        // Extraer rut del estudiante 4

        string rute4 = e4.substr((le4 - 28),12);

        // Covertir de las notas del estudiante 4 de string a float

        float e4n1;
        istringstream(n1e4) >> e4n1;
        float e4n2;
        istringstream(n2e4) >> e4n2;
        float e4n3;
        istringstream(n3e4) >> e4n3;
        float e4n4;
        istringstream(n4e4) >> e4n4;

        // Extraer cada nota del estudiante 5

        string n1e5 = e5.substr((le5 - 15),3); 
        string n2e5 = e5.substr((le5 - 11),3); 
        string n3e5 = e5.substr((le5 - 7),3); 
        string n4e5 = e5.substr((le5 - 3),3);

        // Extraer nombre del estudiante 5

        string nombe5 = e5.substr(0,(le5 - 29));

        // Extraer rut del estudiante 5

        string rute5 = e5.substr((le5 - 28),12);

        // Covertir de las notas del estudiante 5 de string a float

        float e5n1;
        istringstream(n1e5) >> e5n1;
        float e5n2;
        istringstream(n2e5) >> e5n2;
        float e5n3;
        istringstream(n3e5) >> e5n3;
        float e5n4;
        istringstream(n4e5) >> e5n4;

        // Calculo de promedio para cada estudiante

        float pe1 = (e1n1+e1n2+e1n3+e1n4)/4;
        float pe2 = (e2n1+e2n2+e2n3+e2n4)/4;
        float pe3 = (e3n1+e3n2+e3n3+e3n4)/4;
        float pe4 = (e4n1+e4n2+e4n3+e4n4)/4;
        float pe5 = (e5n1+e5n2+e5n3+e5n4)/4;
        
        // Cierre del archivo

        archivo.close(); // Cerramos la conexion con el archivo

        //Estado de los alumnos

        string ee1;
        string ee2;
        string ee3;
        string ee4;
        string ee5;

        // Contador de aprobados y reprobados

        int aprobados;
        int reprobados;

        // Inicializar en 0 los contadores

        aprobados = 0;
        reprobados = 0;

        // Aprobado o reprobado

        if (pe1 >= 4){
            ee1 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee1 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe2 >= 4){
            ee2 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee2 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe3 >= 4){
            ee3 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee3 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe4 >= 4){
            ee4 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee4 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe5 >= 4){
            ee5 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee5 = "Reprobado";
            reprobados = reprobados+1;
        }
        
        // Almacenamos el archivo que subio el profesor en una "Base de datos" en la carpeta del programa
        
        string nomb_arc_guardar;
        nomb_arc_guardar = nam+sec;
        ofstream guardado;
        guardado.open(nomb_arc_guardar);
        guardado << nombe1 << " " << rute1 << " " << fixed << setprecision(1) << pe1 << " " << ee1 << "\n";
        guardado << nombe2 << " " << rute2 << " " << fixed << setprecision(1) << pe2 << " " << ee2 << "\n";
        guardado << nombe3 << " " << rute3 << " " << fixed << setprecision(1) << pe3 << " " << ee3 << "\n";
        guardado << nombe4 << " " << rute4 << " " << fixed << setprecision(1) << pe4 << " " << ee4 << "\n";
        guardado << nombe5 << " " << rute5 << " " << fixed << setprecision(1) << pe5 << " " << ee5 << "\n";

        // Imprimimos por pantalla lo solicitado

        cout << nombe1 << " " << fixed << setprecision(1) << pe1 << endl;
        cout << nombe2 << " " << fixed << setprecision(1) << pe2 << endl;
        cout << nombe3 << " " << fixed << setprecision(1) << pe3 << endl;
        cout << nombe4 << " " << fixed << setprecision(1) << pe4 << endl;
        cout << nombe5 << " " << fixed << setprecision(1) << pe5 << endl;
        cout << "Cantidad de aprobados: " << aprobados << endl;
        cout << "Cantidad de reprobados: " << reprobados << endl;



        break;

        // Aqui termina la opcion automatica

        }
        
        case 2:
        {

        string nam; // Nombre de la asignatura
        string rpm; // Rut del profesor
        string sec; // Seccion de la asignatura
        cout << "Ingrese el nombre de la asignatura: ";
        cin >> nam;
        cout << "Ingrese la seccion de la asignatura: ";
        cin >> sec;
        cout << "Ingrese su rut: ";
        cin >> rpm;

        // Variables para los nombres de los estudiantes

        string nombre1;
        string nombre2;
        string nombre3;
        string nombre4;
        string nombre5;

        // Variables para los apellidos de los estudiantes

        string apelli1;
        string apelli2;
        string apelli3;
        string apelli4;
        string apelli5;

        // Variable para los rut de los estudiantes

        string rute1;
        string rute2;
        string rute3;
        string rute4;
        string rute5;

        // Variables para las notas de los estudiantes

        float e1n1;
        float e1n2;
        float e1n3;
        float e1n4;
    
        float e2n1;
        float e2n2;
        float e2n3;
        float e2n4;

        float e3n1;
        float e3n2;
        float e3n3;
        float e3n4;

        float e4n1;
        float e4n2;
        float e4n3;
        float e4n4;

        float e5n1;
        float e5n2;
        float e5n3;
        float e5n4;

        // Ingreso estudiante 1

        cout << "Ingrese el nombre del estudiante 1: ";
        cin >> nombre1;
        cout << "Ingrese el apellido del estudiante 1: ";
        cin >> apelli1;
        cout << "Ingrese el rut del estudiante 1: ";
        cin >> rute1;
        cout << "Ingrese la nota 1 del estudinte 1: ";
        cin >> e1n1;
        cout << "Ingrese la nota 2 del estudinte 1: ";
        cin >> e1n2;
        cout << "Ingrese la nota 3 del estudinte 1: ";
        cin >> e1n3;
        cout << "Ingrese la nota 4 del estudinte 1: ";
        cin >> e1n4;

        // Ingreso estudiante 2

        cout << "ingrese el nombre del estudiante 2: ";
        cin >> nombre2;
        cout << "Ingrese el apellido del estudiante 2: ";
        cin >> apelli2;
        cout << "Ingrese el rut del estudiante 2: ";
        cin >> rute2;
        cout << "Ingrese la nota 1 del estudinte 2: ";
        cin >> e2n1;
        cout << "Ingrese la nota 2 del estudinte 2: ";
        cin >> e2n2;
        cout << "Ingrese la nota 3 del estudinte 2: ";
        cin >> e2n3;
        cout << "Ingrese la nota 4 del estudinte 2: ";
        cin >> e2n4;

        // Ingreso estudiante 3

        cout << "ingrese el nombre del estudiante 3: ";
        cin >> nombre3;
        cout << "Ingrese el apellido del estudiante 3: ";
        cin >> apelli3;
        cout << "Ingrese el rut del estudiante 3: ";
        cin >> rute3;
        cout << "Ingrese la nota 1 del estudinte 3: ";
        cin >> e3n1;
        cout << "Ingrese la nota 2 del estudinte 3: ";
        cin >> e3n2;
        cout << "Ingrese la nota 3 del estudinte 3: ";
        cin >> e3n3;
        cout << "Ingrese la nota 4 del estudinte 3: ";
        cin >> e3n4;

        // Ingreso estudiante 4

        cout << "ingrese el nombre del estudiante 4: ";
        cin >> nombre4;
        cout << "Ingrese el apellido del estudiante 4: ";
        cin >> apelli4;
        cout << "Ingrese el rut del estudiante 4: ";
        cin >> rute4;
        cout << "Ingrese la nota 1 del estudinte 4: ";
        cin >> e4n1;
        cout << "Ingrese la nota 2 del estudinte 4: ";
        cin >> e4n2;
        cout << "Ingrese la nota 3 del estudinte 4: ";
        cin >> e4n3;
        cout << "Ingrese la nota 4 del estudinte 4: ";
        cin >> e4n4;

        // Ingreso estudiante 5

        cout << "ingrese el nombre del estudiante 5: ";
        cin >> nombre5;
        cout << "Ingrese el apellido del estudiante 5: ";
        cin >> apelli5;
        cout << "Ingrese el rut del estudiante 5: ";
        cin >> rute5;
        cout << "Ingrese la nota 1 del estudinte 5: ";
        cin >> e5n1;
        cout << "Ingrese la nota 2 del estudinte 5: ";
        cin >> e5n2;
        cout << "Ingrese la nota 3 del estudinte 5: ";
        cin >> e5n3;
        cout << "Ingrese la nota 4 del estudinte 5: ";
        cin >> e5n4;
        
        // Calculo de promedio para cada estudiante

        float pe1 = (e1n1+e1n2+e1n3+e1n4)/4;
        float pe2 = (e2n1+e2n2+e2n3+e2n4)/4;
        float pe3 = (e3n1+e3n2+e3n3+e3n4)/4;
        float pe4 = (e4n1+e4n2+e4n3+e4n4)/4;
        float pe5 = (e5n1+e5n2+e5n3+e5n4)/4;

        //Estado de los alumnos

        string ee1;
        string ee2;
        string ee3;
        string ee4;
        string ee5;

        // Contador de aprobados y reprobados

        int aprobados;
        int reprobados;

        // Inicializar en 0 los contadores

        aprobados = 0;
        reprobados = 0;

        // Aprobado o reprobado

        if (pe1 >= 4){
            ee1 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee1 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe2 >= 4){
            ee2 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee2 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe3 >= 4){
            ee3 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee3 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe4 >= 4){
            ee4 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee4 = "Reprobado";
            reprobados = reprobados+1;
        }
        if (pe5 >= 4){
            ee5 = "Aprobado ";
            aprobados = aprobados+1;
        } 
        else{
            ee5 = "Reprobado";
            reprobados = reprobados+1;
        }

        // Almacenamos el lo que subio el profesor en una "Base de datos" en la carpeta del programa
        
        string nomb_arc_guardar;
        nomb_arc_guardar = nam+sec;
        ofstream guardado;
        guardado.open(nomb_arc_guardar);
        guardado << nombre1 << " " << apelli1 << " " << rute1 << " " << fixed << setprecision(1) << pe1 << " " << ee1 << "\n";
        guardado << nombre2 << " " << apelli2 << " " << rute2 << " " << fixed << setprecision(1) << pe2 << " " << ee2 << "\n";
        guardado << nombre3 << " " << apelli3 << " " << rute3 << " " << fixed << setprecision(1) << pe3 << " " << ee3 << "\n";
        guardado << nombre4 << " " << apelli4 << " " << rute4 << " " << fixed << setprecision(1) << pe4 << " " << ee4 << "\n";
        guardado << nombre5 << " " << apelli5 << " " << rute5 << " " << fixed << setprecision(1) << pe5 << " " << ee5 << "\n";

        // Imprimir en pantalla

        cout << nombre1 << " " << apelli1 << " " << fixed << setprecision(1) << pe1 << endl;
        cout << nombre2 << " " << apelli2 << " " << fixed << setprecision(1) << pe2 << endl;
        cout << nombre3 << " " << apelli3 << " " << fixed << setprecision(1) << pe3 << endl;
        cout << nombre4 << " " << apelli4 << " " << fixed << setprecision(1) << pe4 << endl;
        cout << nombre5 << " " << apelli5 << " " << fixed << setprecision(1) << pe5 << endl;
        cout << "Cantidad de aprobados: " << aprobados << endl;
        cout << "Cantidad de reprobados: " << reprobados << endl;


        // Aqui va la opcion de cargar notas manualmente

        }
    
    }
    break;
    }
    case 2:
    {
    cout << "--------------Estudiante---------------" << endl;

    // Nombre del estudiante
    
    string nombre;

    // Apellido del estudiante

    string apellido;

    // Rut del estudiante

    string rut;

    // Cantidad de asignaturas a buscar

    float cab;
    float busquedas;
    busquedas = 0;

    // Variable nombre de la asignatura a buscar

    string nab1;
    string nab2;
    string nab3;
    string nab4;
    string nab5;

    nab1 = "vacio";
    nab2 = "vacio";
    nab3 = "vacio";
    nab4 = "vacio";
    nab5 = "vacio";

    // Variable para la seccion de la asignatura a buscar

    string sb1;
    string sb2;
    string sb3;
    string sb4;
    string sb5;

    cout << "Ingrese su nombre" << endl;
    cin >> nombre;
    cout << "Ingrese su apellido" << endl;
    cin >> apellido;
    cout << "Ingrese su rut" << endl;
    cin >> rut;
    cout << "¿Cuantas asignaturas desea buscar?" << endl;
    cin >> cab;
    
    while (busquedas < 1){
        if (cab == 1){
            cout << "Ingrese los datos de la asignatura para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura" << endl;
            cin >> nab1;
            cout << "Ingrese la seccion de la asignatura" << endl;
            cin >> sb1;
        }
        if (cab == 2){
            cout << "Ingrese los datos de la asignatura 1 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 1" << endl;
            cin >> nab1;
            cout << "Ingrese la seccion de la asignatura 1" << endl;
            cin >> sb1;
            cout << "Ingrese los datos de la asignatura 2 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 2" << endl;
            cin >> nab2;
            cout << "Ingrese la seccion de la asignatura 2" << endl;
            cin >> sb2;
        }
        if (cab == 3){
            cout << "Ingrese los datos de la asignatura 1 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 1" << endl;
            cin >> nab1;
            cout << "Ingrese la seccion de la asignatura 1" << endl;
            cin >> sb1;
            cout << "Ingrese los datos de la asignatura 2 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 2" << endl;
            cin >> nab2;
            cout << "Ingrese la seccion de la asignatura 2" << endl;
            cin >> sb2;
            cout << "Ingrese los datos de la asignatura 3 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 3" << endl;
            cin >> nab3;
            cout << "Ingrese la seccion de la asignatura 3" << endl;
            cin >> sb3;
        }
        if (cab == 4){
            cout << "Ingrese los datos de la asignatura 1 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 1" << endl;
            cin >> nab1;
            cout << "Ingrese la seccion de la asignatura 1" << endl;
            cin >> sb1;
            cout << "Ingrese los datos de la asignatura 2 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 2" << endl;
            cin >> nab2;
            cout << "Ingrese la seccion de la asignatura 2" << endl;
            cin >> sb2;
            cout << "Ingrese los datos de la asignatura 3 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 3" << endl;
            cin >> nab3;
            cout << "Ingrese la seccion de la asignatura 3" << endl;
            cin >> sb3;
            cout << "Ingrese los datos de la asignatura 4 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 4" << endl;
            cin >> nab4;
            cout << "Ingrese la seccion de la asignatura 4" << endl;
            cin >> sb4;
        }
        if (cab == 5){
            cout << "Ingrese los datos de la asignatura 1 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 1" << endl;
            cin >> nab1;
            cout << "Ingrese la seccion de la asignatura 1" << endl;
            cin >> sb1;
            cout << "Ingrese los datos de la asignatura 2 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 2" << endl;
            cin >> nab2;
            cout << "Ingrese la seccion de la asignatura 2" << endl;
            cin >> sb2;
            cout << "Ingrese los datos de la asignatura 3 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 3" << endl;
            cin >> nab3;
            cout << "Ingrese la seccion de la asignatura 3" << endl;
            cin >> sb3;
            cout << "Ingrese los datos de la asignatura 4 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 4" << endl;
            cin >> nab4;
            cout << "Ingrese la seccion de la asignatura 4" << endl;
            cin >> sb4;
            cout << "Ingrese los datos de la asignatura 5 para buscar sus resultados" << endl;
            cout << endl;
            cout << "Ingrese el nombre de la asignatura 5" << endl;
            cin >> nab5;
            cout << "Ingrese la seccion de la asignatura 5" << endl;
            cin >> sb5;
        }
        if (cab > 5){
            cout << "Maximo de 5 asignaturas a buscar, vuelva a intentarlo" << endl;
        }
    busquedas = busquedas + 1;
    continue;    
    }

    // Nombre archivo abrir (Nombre del archivo de texto para buscar)

    string naa1; 
    string naa2;
    string naa3;
    string naa4;
    string naa5;

    naa1 = nab1+sb1;
    naa2 = nab2+sb2;
    naa3 = nab3+sb3;
    naa4 = nab4+sb4;
    naa5 = nab5+sb5;

    // Apertura del archivo de texto

    ifstream archivo1(naa1);
    ifstream archivo2(naa2);
    ifstream archivo3(naa3);
    ifstream archivo4(naa4);
    ifstream archivo5(naa5);

    //Variables para los estudiantes

    string e1;
    string e2;
    string e3;
    string e4;
    string e5;

    // Tomar linea de cada estudiante

    getline(archivo1,e1);
    getline(archivo1,e2);
    getline(archivo1,e3);
    getline(archivo1,e4);
    getline(archivo1,e5);

    // Largo de la linea de cada estudiante

    int le1 = e1.length();
    int le2 = e2.length();
    int le3 = e3.length();
    int le4 = e4.length();
    int le5 = e5.length();

    // Extraer nombre del estudiante 1

    string nombe1 = e1.substr(0,(le1 - 27));

    // Extraer rut del estudiante 1

    string rute1 = e1.substr((le1 - 26),12);

    // Extraer nota y estado del estudiante 1

    string ne1 = e1.substr((le1 - 13));

    // Extraer nombre del estudiante 2

    string nombe2 = e2.substr(0,(le2 - 27));

    // Extraer rut del estudiante 2

    string rute2 = e2.substr((le2 - 26),12);

    // Extraer nota y estado del estudiante 2

    string ne2 = e2.substr((le2 - 13));
    
    // Extraer nombre del estudiante 3

    string nombe3 = e3.substr(0,(le3 - 27));

    // Extraer rut del estudiante 3

    string rute3 = e3.substr((le3 - 26),12);

    // Extraer nota y estado del estudiante 3

    string ne3 = e3.substr((le3 - 13));
    
    // Extraer nombre del estudiante 4

    string nombe4 = e4.substr(0,(le4 - 27));

    // Extraer rut del estudiante 4

    string rute4 = e4.substr((le4 - 26),12);

    // Extraer nota y estado del estudiante 4

    string ne4 = e4.substr((le4 - 13));
    
    // Extraer nombre del estudiante 5

    string nombe5 = e5.substr(0,(le5 - 27));

    // Extraer rut del estudiante 5

    string rute5 = e5.substr((le5 - 26),12);

    // Extraer nota y estado del estudiante 5

    string ne5 = e5.substr((le5 - 13));

    // Ver cual estudiante es para almacenar sus notas

    string ramo1;
    string ramo2;
    string ramo3;
    string ramo4;
    string ramo5;

    if (rut == rute1){
        ramo1 = nab1 + " " + ne1;
        cout << ramo1 << endl;
    }
    if (rut == rute2){
        ramo1 = nab1 + " " + ne2;
        cout << ramo1 << endl;
    }
    if (rut == rute3){
        ramo1 = nab1 + " " + ne3;
        cout << ramo1 << endl;
    }
    if (rut == rute4){
        ramo1 = nab1 + " " + ne4;
        cout << ramo1 << endl;
    }
    if (rut == rute5){
        ramo1 = nab1 + " " + ne5;
        cout << ramo1 << endl;
    }
    if (rut != rute1 && rut != rute2 && rut != rute3 && rut != rute4 && rut != rute5) {
        ramo1 = "No existe en el listado de notas";
        cout << ramo1 << endl;
    }

    break;
    }
    case 3:
        cout << "Hasta luego" << endl;
        break;
    default:
        cout << "Vuelva a empezar e ingrese la opcion correctamente" << endl;
        cout << "---------------------Error 404--------------------" << endl;
}
}