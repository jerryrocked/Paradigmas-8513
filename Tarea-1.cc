//Buenas profesor, este trabajo lo realicé junto con Macarena Castro, Luciano Roca, Alonso Riveros, Diego Pavez//

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


class Individuo { //creamos los atributos del individuo//
public:
  string name;
  string id;
};

class Student :: Individuo {    //creamos los atributos y los metodos les damos la forma que ocuparemos//
public:
  map<string, float[4]> grades;     //hacemos un mapa para tener identificado las notas con cada nombre correspondiente//

  Student(string aname) { 
    name = aname; 
    }

  void setgrades(string Name, float grades1, float grades2, float grades3,
                float grades4) {
    grades[Name][0] = grades1;
    grades[Name][1] = grades2;
    grades[Name][2] = grades3;
    grades[Name][3] = grades4;
  }

  string getName() { 
    return name; 
    }   //extraemos el nombre del alumno//

  float meancourse(string course) {    //determinamos el promedio del Ramo que queremos saber//
    float sum = 0;
    for (int i = 0; i < 4; i++) {
      grades[course][i];
      sum = grades[course][i] + sum;
    };
    float mean = 0;
    mean = sum / 4;
    return mean;
  }
  float meanArchiv() {     //Sacamos el promedio del archivo de texto //
    float mean = 0;
    for (auto iterador = grades.begin(); iterador != grades.end(); ++iterador) {
      mean += iterador->second[0] + iterador->second[1] +
                  iterador->second[2] + iterador->second[3];
    }
    float end = (mean / 4);
    return end;
  }

  float printmean() {    //mostramos por pantalla el promedio //
    float mean = 0;
    for (auto it = grades.begin(); it != grades.end(); it++) {
      for (int i = 0; i < 4; i++) {
        mean = grades[it->first][i] + mean;
      }
      cout << mean / 4;
    }
    return (mean/4)
  }
};

class Materia {
public:

  string code;    
  string teacher;
  string cypher;
  string name;

  vector<Student> student_list;

  Materia(string mname, string mcode, string mcypher) {     //le damos forma a los datos que vamos a ocupar posteriormente//
    code = mcode;
    cypher = mcypher;
    name = mname;
  }

  string getName() { return this->name; }     //obtenemos el nombre que necesitamos//

  string getcypher() { return this->cypher; }    //obtenemos el NRC que necesitamos//

  string getCode() { return this->code; }       //obtenemos el codigo//

  void addStudent(Student student) { student_list.push_back(student); }       //añadimos un alumno al final de la lista//
  
  void calStudent(Student &student, float grade1, float grade2,         // le damos formato a la linea entera que tendra el nombre del estudiante y sus notas correspondientes //
                       float grade3, float grade4) {
    student.setgrades(student.getName(), grade1, grade2, grade3, grade4);
  }

  void passed() {     //obtenemos los alumnos que aprobaron//

    float mean = 0;
    int reprobate = 0;
    int passed = 0;

    for (auto iterador = student_list.begin(); iterador != student_list.end();
         ++iterador) {
      for (int i = 0; i < 4; i++) {
        mean += iterador->grades[iterador->getName()][i];
      }
      if (mean < 4) {
        reprobate = reprobate + 1;
      } else {
        passed = passed + 1;
      }
    }
  }

  void ordStudents() {         //ordenamos los alumnos por su promedio de notas//
    for (int i = 0; i < student_list.size(); i++) {
      for (int j = 0; j < student_list.size(); j++) {
        if (student_list[i].meanArchiv() >
            student_list[j].meanArchiv()) {
          Student aux = student_list[i];
          student_list[i] = student_list[j];
          student_list[j] = aux;
        }
      }
    }
    for (int i = 0; i < student_list.size(); i++) {
      cout << student_list[i].getName() << ": "
           << student_list[i].meanArchiv() << endl;
    }
  }
};

class Teach :: Individuo {
public:
  vector<Materia> subject;
  Teach(string p_name, string rut) {    //damos formato a los atributos//
    name = p_name;
    id = rut;
  }

  void Addcourse(Materia course){      //agregamos la materia que queremos al final de la lista//
    subject.push_back(course);
  }
};

int main() {
  int opcion1_1, opcion1_2;
  string teacher_name;
  string teacher_rut;
  string archiv1;
  ifstream archiv;
  char course[100];

  char texto[50];
  string line, nameA, rutA, grades1, grades2, grades3, grades4;         // anteriormente definimos todas las variables que ocuparemos//
  Teach one("Luciano", "21.020.459-8");
  Materia prog("Paradigmas de Programación", "PP005", "NRC: 8422");
  one.Addcourse(prog);
  cout << "1-Profesor\n2-Estudiante" << endl;
  cin >> opcion1_1;
  if (opcion1_1 == 1) {       //al seleccionarla por pantalla, ocupamos esta opcion para crear y operar el txt//
    cout << "Ingrese nombre: ";
    cin >> teacher_name;
    cout << "\nIngrese rut: ";
    cin >> teacher_rut;
    //-----------------//

    cout << "\n1- Ingresar notas\n2- Leer un archivo de notas\n";
    cin >> opcion1_2;

    if (opcion1_2 == 1) {
      cout << "Ingrese el nombre de la asignatura (Con la extensión): ";
      cin >> course;
      ofstream fich(course);
      if (!fich) {
        cout << ("Error al crear el archivo");
        exit(EXIT_FAILURE);
      }
      string student;
      string rut_student;
      float grades1;
      float grades2;
      float grades3;
      float grades4;
      int nalumnos;
      cout << "Ingrese la cantidad de alumnos: \n";
      cin >> nalumnos;

      for (int i = 0; i < nalumnos; ++i) {

        cout << "Escriba el nombre del estudiante: ";
        cin >> student;
        fich << student << " ";

        cout << "Escriba el rut del estudiante: ";
        cin >> rut_student;
        fich << rut_student << " ";

        cout << "Escriba la primera nota: ";
        cin >> grades1;
        fich << grades1 << " ";

        cout << "Escriba la segunda nota: ";
        cin >> grades2;
        fich << grades2 << " ";

        cout << "Escriba la tercera nota: ";
        cin >> grades3;
        fich << grades3 << " ";

        cout << "Escriba la cuarta nota: ";
        cin >> grades4;
        fich << grades4 << " ";

        fich << endl;
        cout << endl;
      }
      
      cout << "Ya se ha generado el archivo de texto";
    }
    
    if (opcion1_2 == 2){          //leemos el txt y sacamos todos los datos que vamos a ocupar posteriormente//

      string nameArchiv;

      cout<<"Ingrese el nombre del archivo (.txt)\n";

      cin>>nameArchiv;

      archiv.open(nameArchiv);

      while (getline(archiv, line)) {
        nameA = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        rutA = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        grades1 = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        grades2 = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        grades3 = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        grades4 = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);

        Student Student(nameA);
        Student.setgrades(nameA,stof(grades1),stof(grades2),stof(grades3),stof(grades4));

      }

  } else if (opcion1_1 == 2) {
    
  } else {
    cout << "opción no válida";
    }
  };
}