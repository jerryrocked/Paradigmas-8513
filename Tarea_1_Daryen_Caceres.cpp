#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int opcion;
//clase profesor
class profesor{
public:
struct{
  string n_profesor, r_profesor;
}prof; 
profesor(){ };
~profesor(){ };
void datos_profesor();
void mostrar_profesor();
};

//datos del rpofesor (nombre y rut)
void profesor::datos_profesor(){
  cout<<"Ingrese nombre del profesor: "; cin>> prof.n_profesor;
  cout<<"Ingrese el Rut del profesor: "; cin>>prof.r_profesor;
  cout<<endl;
};

//mostrar los datos del profesor 
void profesor::mostrar_profesor(){
  cout<<"Nombre: "<<prof.n_profesor<<endl;
  cout<<"Rut: "<<prof.r_profesor<<endl;
};

//clase asignatura
class asignatura: public profesor{
public:
asignatura(){};
~asignatura(){};
void ingresar_notas();
};

//ingrear notas  
void asignatura::ingresar_notas(){
  int i,cont=0, j=0;
  float promedio;
  string asignatura_profe, n_alumno, n1, n2, n3, n4, a_alumno,txt= ".txt";
  string arreglo[50];
  cout<<"Ingrese la asignatura: "; cin>>asignatura_profe;
  //se crea el txt
  string nombreArchivo = asignatura_profe+txt;
  //escribimos en el txt
  ofstream archivo;
  //se abre el txt
  archivo.open(nombreArchivo.c_str(), fstream::out);
  while (j<4){
    //se ingresan los datos
    cout<<"Ingrese nombre del alumno: "; cin>>n_alumno;
    cout<<"Ingrese apellido del alumno: "; cin>>a_alumno;
    //se ingresan las notas
    cout<<"Ingrese las notas del alumno "<<endl<<endl;
    cout<<"Ingrese nota 1: "; cin>>n1;
    cout<<"Ingrese nota 2: "; cin>>n2; 
    cout<<"Ingrese nota 3: "; cin>>n3; 
    cout<<"Ingrese nota 4: "; cin>>n4;
    float nota1 = stof(n1);
    float nota2 = stof(n2);
    float nota3 = stof(n3);
    float nota4 = stof(n4);
    /*promedio = (nota1+nota2+nota3+nota4)/4;
    cout<<"El alumno "<<n_alumno<<" tiene un promedio del ramo "<<asignatura_profe<<": "<<promedio;
    cout<<endl;*/
    //se ingresan los promedios de los estudiantes
    //string p(to_string(promedio));
    
    //ingresar las notas a un txt
  arreglo[0] = n_alumno; arreglo[1] = " ";
  arreglo[2] = a_alumno; arreglo[3] = " ";
  arreglo[4] = n1; arreglo[5] = " ";
  arreglo[6] = n2; arreglo[7] = " ";
  arreglo[8] = n3; arreglo[9] = " ";
  arreglo[10] = n4;

  
    cout<<"arreglo:";
  //abro el archivo txt
  
  for (i=0;i<11;i++){
    //se va agregando las notas a un txt 
    cout<<arreglo[i];
    archivo<<arreglo[i];
  }
  archivo<<"\n";
  //se cierra el archivo
  cout<<endl;
  j++;
  }
  //se cierra el txt 
  archivo.close();
}

//clase alumno 
class alumno{
public:
struct{
  string n_alumno, r_alumno;
}alum;
alumno(){ };
~alumno(){ };
void datos_alumno();
void mostrar_alumno();
void promedio_alumno();
};

//datos alumno
void alumno:: datos_alumno(){
  cout<<"Ingrese nombre del alumno: "; cin>> alum.n_alumno;
  cout<<"Ingrese Rut del alumno: "; cin>>alum.r_alumno;
  cout<<endl;
}

//mostrar datos alumno 
void alumno:: mostrar_alumno(){
  cout<<"Nombre: "<<alum.n_alumno<<endl;
  cout<<"Rut: "<<alum.r_alumno<<endl;
}

void alumno:: promedio_alumno(){
  float promedio;
  string n1,n2,n3,n4;
  string nombre,apellido, asignatura, profesor,txt=".txt";
  //campos para el txt
  string promedio_n[50];
  int i,j=0;
  //nombre del txt 
  cout<<"Ingrese la asignatura: "; cin>>asignatura;
  cout<<endl;
  string nombreArchivo = asignatura+txt;
  ofstream archivo;
  
  cout<<"Ingrese el nombre del profesor: "; cin>>profesor;
  archivo.open(nombreArchivo.c_str(), fstream::out);
  while(j<4){
  cout<<"Ingrese el nombre del alumno: "; cin>>nombre;
  cout<<endl;
  //se ingresa el nombre del alumno
  cout<<"Ingrese el apellido del alumno: "; cin>>apellido;
  cout<<endl;
  //se ingresa la asignatura
  cout<<"Ingrese las notas del alumno"<<endl;
  cout<<"Ingrese nota 1: "; cin>>n1;
  cout<<"Ingrese nota 2: "; cin>>n2; 
  cout<<"Ingrese nota 3: "; cin>>n3; 
  cout<<"Ingrese nota 4: "; cin>>n4;
  cout<<endl;
  //se ingresan las notas del alumno
  float nota1 = stof(n1);
  float nota2 = stof(n2);
  float nota3 = stof(n3);
  float nota4 = stof(n4);
  //obtengo el promedio en un dato float
  promedio = (nota1+nota2+nota3+nota4)/4;
  cout<<"El alumno "<<nombre<<" tiene un promedio del ramo "<<asignatura<<": "<<promedio;
  cout<<endl;
  //redonde el promedio
  printf("%.1f\n",promedio);
  //paso de float a string
  string p(to_string(promedio));
  //ingresar promedio a un txt
  cout<<endl;
  cout<<"promedio: "<<p;
  cout<<endl;
  promedio_n[0] = nombre; promedio_n[1] = " ";
  promedio_n[2] = apellido; promedio_n[3] = " ";
  promedio_n[4] = p;
  //agrego las notas al arreglo
  //abro el archivo txt
  
  for (i=0;i<5;i++){
    //se va agregando las notas a un txt 
    cout<<promedio_n[i];
    archivo<<promedio_n[i];
  }
  archivo<<"\n";
  cout<<endl;
  j++;
  }
}

// menu
void menu()
{
  cout<<"¿Usted es alumno o profesor?"<<endl;
  cout<<"1) Profesor\n";
  cout<<"2) Alumno\n";
  cout<<"3) Salir\n";
  cout<<"Ingrese la opcion: "; cin>>opcion;

  switch(opcion)
  {
    case 1:{
      profesor profesor;
      asignatura asignatura;
      
      profesor.datos_profesor();
      profesor.mostrar_profesor();
      asignatura.ingresar_notas();
      }
    
    case 2:{
      alumno alumno;
      alumno.datos_alumno();
      alumno.mostrar_alumno();
      alumno.promedio_alumno();
      }

    case 3:{
      cout<<"Saliendo del programa"<<endl;
    }
  }
}

int main() {
  menu();
}