#include <iostream>
#include <fstream>

using namespace std;

// se define una clase llamada asignatura, que contiene las distintas asignaturas con su correspondiente codificiacion

class asignatura {
    public:
    string asig[5]={"PROGRAMACION", "BASE DE DATOS", "ALGORITMO Y ESTRUCTURA DE DATOS", "DESARROLLO WEB Y MOVIL", "PARADIGMAS DE PROGRAMACION"};
    string cod[5]={"PR001", "BD002", "AE003", "DM004", "PP005"};
    double calificaciones[5]={1.0, 1.0, 1.0, 1.0, 1.0};

    void mostrarasig();
    void ingresarcalif();
};

// de la clase asignatura se heredan los arrays para declarar funciones que utilicen esos datos para el programa

void asignatura::mostrarasig(){

    // esta función muestra las 5 asignaturas del problema, con un número identificador para poder seleccionarlas

    int i;

    for (i = 0; i<5; i++){
        cout<<i + 1 << " " + asig[i];
        cout<<" "<<cod[i]<<endl;
    }
};

// a su vez, se crea la funcion ingresar calificaciones, que permite agregar distintos valores al array que tendrá las notas de las distintas asignaturas

void asignatura::ingresarcalif(){

    int j;

    for (j = 0; j<5; j++){

        cout<<"\n - Ingrese la calificacion ";
        double calificacion;
        cin >> calificacion;
        calificaciones[j] = calificacion;
    }
};

// se crea una clase persona, que servirá de clase padre para estudiante y profesor.

class persona{

  public:
  string nom,rut;
  string n[200];
  int rol;
  void ingresarRol();
};

// se crea una funcion que define si es estudiante o profesor.

void persona::ingresarRol(){

  cout<<"Es usted es un Estudiante (1) o Profesor (2)?: ";
  cin >> rol;

  if(rol == 1){
    cout << "\n --- > Usted es un Estudiante." << endl;
  }

  else if(rol == 2){
    cout << "\n --- > Usted es un Profesor." << endl;
  }

  else{
    cout << "\n --- > Debe seleccionar '1' o '2'" << endl;
  }

};

class estudiante: public persona, public asignatura {

  // esta clase hereda los atributos y metodos de persona y asignatura
  public:
    string asignatura;
    bool aprobado;
    void vercalif();
};

void estudiante::vercalif(){

    int i;

    for (i = 0; i<5; i++){
        cout<<"calificacion "<< i + 1 << ": "<< calificaciones[i] << endl;
    }
};

class profesor: public persona, public asignatura {
  public:
    string rutProfe, asignatura;
    bool enviado;
    void ingresarcalif();
    void enviarcalif();
};

void profesor::ingresarcalif(){

    int i;

    for (i = 0; i<5; i++){
        cout<<"calificacion "<< i + 1 << ": "<< calificaciones[i] << endl;
    }
};


int main()
{

    cout << "--> BIENVENIDO A LA PLATAFORMA DE ASIGNATURAS UNAB" << endl;

    persona pe;
    pe.ingresarRol();

    cout << "\nQue desea hacer?: " << endl;

    if(pe.rol == 1){
        cout << "\n1) Ver Calificaciones"<< endl;
        cout << "\n-> Seleccione una de las opciones: ";
        string r1;
        cin >> r1;

        if(r1 == "1"){
            cout << "\nHa seleccionado Ver Calificaciones" <<endl;
            string s;
            ifstream f( "C:/Users/FULLUNLOCK/Desktop/C++/calificaciones.txt" );
            if ( f.is_open() ) {
            getline( f, s );

            while( !f.eof() ) {
            cout << s << endl;

            getline( f, s );}}

            else
            cerr << "Error de apertura del archivo." << endl;
        }
    }

    else if(pe.rol == 2){
        cout << "\n1) Ingresar Calificaciones" << endl;
        cout << "2) Entregar Calificaciones" << endl;

        cout << "\n-> Seleccione una de las opciones: ";
        string r1;
        cin >> r1;

        if (r1 == "1"){
            cout << "\n-> Ha seleccionado 'Ingresar Calificaciones'" << endl;

            cout << "\n - Profesor, por favor ingrese su rut: ";
            string rutProfe;
            cin >> rutProfe;

            cout << "" << endl;

            asignatura as;
            as.mostrarasig();

            cout << "\n - Ingrese el nombre de la asignatura: ";
            string asignatura;
            cin >> asignatura;

            // se debe cambiar la ruta si se ejecuta en otro dispositivo

            ofstream file;
            file.open("C:/Users/FULLUNLOCK/Desktop/C++/calificaciones.txt");

            cout << "\n-----> " << asignatura <<  endl;

            cout << "\n - Cuantos alumnos son en " << asignatura << "?: ";
            int cantidadAlumnos;
            cin >> cantidadAlumnos;

            string arrAlumnos[cantidadAlumnos];
            int alumnosCalificados = 0;
            string nomAlumnos[cantidadAlumnos];
            string rutAlumnos[cantidadAlumnos];

            int i;

            for(i=0; i < cantidadAlumnos; i++){
                cout << "\n - Ingrese el nombre del alumno " << i + 1 << ": ";
                string nomAlumno;
                cin >> nomAlumno;
                file << "\n" << nomAlumno << " ";
                cout << " - Ingrese el rut del alumno: ";
                string rutAlumno;
                cin >>rutAlumno;
                file << rutAlumno << " ";

                int notasPuestas = 0;
                int totalNotas = 5;

                while(notasPuestas < totalNotas){
                    cout << " - Ingrese calificacion: ";
                    double calif;
                    cin >> calif;
                    estudiante es2;
                    es2.calificaciones[i] = calif;
                    notasPuestas = notasPuestas + 1;
                    file << es2.calificaciones[i] << + " ";}
             }

        cout << "\nCalificados correctamente" << endl;

        file.close();

        }
        else if(r1 == "2"){
            string s;
            ifstream f( "C:/Users/FULLUNLOCK/Desktop/C++/calificaciones.txt" );
            if ( f.is_open() ) {
            getline( f, s );

            while( !f.eof() ) {
            cout << s << endl;

            getline( f, s );}}

        else
            cerr << "Error de apertura del archivo." << endl;

        }


    }

    return 0;
}


