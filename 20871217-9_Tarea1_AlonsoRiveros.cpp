// Profesor, este trabajo fue realizado en conjunto de Macarena Castro,      Diego Pavez, Angelo Cancino y Luciano Roca.
// Para este codigo el ingreso de notas por alumno es de 4 notas.
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Personal {
public:
  string nombre;
  string identificador;
};//Clase de atributos publicos como el identificador(rut) y el nombre

class Escolar : Personal {
public:
  map<string, float[4]> Notas;
  Escolar(string nombreEscolar) { nombre = nombreEscolar; }
  void setNotas(string Nombre, float nota1, float nota2, float nota3,float nota4) {
    Notas[Nombre][0] = nota1;
    Notas[Nombre][1] = nota2;
    Notas[Nombre][2] = nota3;
    Notas[Nombre][3] = nota4;
  }

  float mediaRamos(string nombreMateria) {
    float suma = 0;
    for (int i = 0; i < 4; i++) {
      Notas[nombreMateria][i];
      suma = Notas[nombreMateria][i] + suma;
    };
    float media = 0;
    media = suma / 4;
    return media;
  }
  string tenerNombre() { return nombre; }
  
  float mostrarMedia() {
    float media = 0;
    for (auto it = Notas.begin(); it != Notas.end(); it++) {
      for (int i = 0; i < 4; i++) {
        media = Notas[it->first][i] + media;
      }
      cout << media / 4;
    }
  }
  float mediaArchivo() {
    float media = 0;
    for (auto it = Notas.begin(); it != Notas.end(); ++it) {
      media += it->second[0] + it->second[1] +
                  it->second[2] + it->second[3];
    }
    float final = (media / 4);
    return final;
  }
};//clase que hereda los atributos de Personal, contiene la creacion del mapa, la asignacion de notas, entre otras funciones.

class Ramos {
public:
  string código;
  string maestro;
  string nrc;
  string nombre;
  vector<Escolar> listaEscolar;
  Ramos(string Enombre, string Ecódigo, string Enrc) {
    código = Ecódigo;
    nrc = Enrc;
    nombre = Enombre;
  }
  string tenerNRC() { return this->nrc; }
  string tenerNombre() { return this->nombre; }
  string tenerCódigo() { return this->código; }

  void agregarEscolar(Escolar estudiante) { listaEscolar.push_back(estudiante); }
  void calificarEscolar(Escolar &estudiante, float nota1, float nota2,
                       float nota3, float nota4) {
    estudiante.setNotas(estudiante.tenerNombre(), nota1, nota2, nota3, nota4);
  }
  void ordenarEscolar() {
    for (int i = 0; i < listaEscolar.size(); i++) {
      for (int j = 0; j < listaEscolar.size(); j++) {
        if (listaEscolar[i].mediaArchivo() >
            listaEscolar[j].mediaArchivo()) {
          Escolar aux = listaEscolar[i];
          listaEscolar[i] = listaEscolar[j];
          listaEscolar[j] = aux;
        }
      }
    }
    for (int i = 0; i < listaEscolar.size(); i++) {
      cout << listaEscolar[i].tenerNombre() << ": "
           << listaEscolar[i].mediaArchivo() << endl;
    }
  }
  void aprobado() {
    float media = 0;
    int reprobado = 0;
    int aprobado = 0;
    for (auto it = listaEscolar.begin(); it != listaEscolar.end();
         ++it) {
      for (int i = 0; i < 4; i++) {
        media += it->Notas[it->tenerNombre()][i];
      }
      if (media < 4) {
        reprobado = reprobado + 1;
      } else {
        aprobado = aprobado + 1;
      }
    }
  }
  
};//Clase que contiene funciones como la creacion del vector, la asignacion de los datos del alumno (notas, ramo, codigo del ramo, etc), verificar la aprobacion de los alumnos para cada ramo, entre otras.

class Maestro : Personal {
public:
  vector<Ramos> ramoImpartidas;
  Maestro(string nombreProfe, string rut) {
    nombre = nombreProfe;
    identificador = rut;
  }
  void agregarRamo(Ramos ramo){
    ramoImpartidas.push_back(ramo);
  }
};//Esta clase al igual que escolar, hereda los atributos, tiene funciones encargadas de asignar los ramos que dicta cada profesor.

int main() {
  int opcion1_1, opcion1_2;
  string nombreprofe;
  string rutprofe;
  string archivo1;
  ifstream archivo;
  char ramo[100];

  char texto[50];
  string linea, nombreA, rutA, nota1A, nota2A, nota3A, nota4A;
  // Asignacion de profesores con sus respectivos datos.
  Maestro valentina("Valentina", "21.020.459-8");
  Maestro alonso("Alonso", "19.847.064-k");
  Maestro diego("Diego", "20.789.444-1");
  Maestro catalina("Catalina", "21.123.456-9");
  Maestro rene("Rene", "20.777.111-5");
  Maestro alvaro("Alvaro", "20.657.122-0");
  // Asignacion de ramos y codigos para la clase ramos
  Ramos paradigmas("Paradigmas de Programación", "PP005", "NRC: 8374");
  Ramos paradigmasDOS("Paradigmas de Programación", "PP005", "NRC: 8364");
  Ramos web("DESARROLLO WEB Y MOBIL","DM004","NRC: 8765");
  Ramos webDOS("DESARROLLO WEB Y MOBIL","DM004","NRC: 8762");
  Ramos estructura("ALGORITMO Y ESTRUCTURA DE DATOS","AE003","NRC: 3456");
  Ramos estructuraDOS("ALGORITMO Y ESTRUCTURA DE DATOS","AE003","NRC: 9875");
  Ramos basedatos("BASE DE DATOS","BD002","NRC: 2345");
  Ramos basedatosDOS("BASE DE DATOS","BD002","NRC: 8765");
  Ramos programacion("PROGRAMACION","PR001","NRC: 2547");
  Ramos programacionDOS("PROGRAMACION","PR001","NRC: 3453");
  // Asignacion de profesores para cada ramo respectivamente.
  valentina.agregarRamo(paradigmas);
  alonso.agregarRamo(paradigmasDOS);
  catalina.agregarRamo(web);
  valentina.agregarRamo(webDOS);
  rene.agregarRamo(estructura);
  alvaro.agregarRamo(estructuraDOS);
  diego.agregarRamo(basedatos);
  alonso.agregarRamo(basedatosDOS);
  rene.agregarRamo(programacion);
  diego.agregarRamo(programacionDOS);
  // Creacion del menú del programa, con opciones de ingreso como alumno o profesor. Por ejemplo la opcion profesor tiene la posibilidad de ingresar notas por medio de la creacion de un txt.
  cout << "1-Profesor\n2-Estudiante" << endl;
  cin >> opcion1_1;
  if (opcion1_1 == 1) {
    cout << "Ingrese nombre: ";
    cin >> nombreprofe;
    cout << "\nIngrese rut: ";
    cin >> rutprofe;
    //-----------------//

    cout << "\n1- Ingresar notas\n2- Leer un archivo de notas\n";
    cin >> opcion1_2;

    if (opcion1_2 == 1) {
      cout << "Ingrese el nombre de la asignatura (Con la extensión): ";
      cin >> ramo;
      ofstream fich(ramo);
      if (!fich) {
        cout << ("Error al crear el archivo");
        exit(EXIT_FAILURE);
      }
      string escolarcin;
      string rutcin;
      float nota1;
      float nota2;
      float nota3;
      float nota4;
      int numeroalumnos;
      cout << "Ingrese la cantidad de alumnos: \n";
      cin >> numeroalumnos;

      for (int i = 0; i < numeroalumnos; ++i) {

        cout << "Escriba el nombre del estudiante: ";
        cin >> escolarcin;
        fich << escolarcin << " ";
        cout << "Escriba el rut del estudiante: ";
        cin >> rutcin;
        fich << rutcin << " ";
        cout << "Escriba la primera nota: ";
        cin >> nota1;
        fich << nota1 << " ";
        cout << "Escriba la segunda nota: ";
        cin >> nota2;
        fich << nota2 << " ";
        cout << "Escriba la tercera nota: ";
        cin >> nota3;
        fich << nota3 << " ";
        cout << "Escriba la cuarta nota: ";
        cin >> nota4;
        fich << nota4 << " ";
        fich << endl;
        cout << endl;
      }
      cout << "Ya se ha generado el archivo de texto";
    }
    
    if (opcion1_2 == 2){
      string nombreArchivo;
      cout<<"Ingrese el nombre del archivo (.txt)\n";
      cin>>nombreArchivo;
      archivo.open(nombreArchivo);
      while (getline(archivo, linea)) {
        nombreA = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        rutA = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        nota1A = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        nota2A = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        nota3A = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        nota4A = linea.substr(0, linea.find(" "));
        linea.erase(0, linea.find(" ") + 1);
        Escolar alumno(nombreA);
        alumno.setNotas(nombreA,stof(nota1A),stof(nota2A),stof(nota3A),stof(nota4A));

      }
      
      
      

  } else if (opcion1_1 == 2) {

  } else {
    cout << "opción no válida";
  }
};
}