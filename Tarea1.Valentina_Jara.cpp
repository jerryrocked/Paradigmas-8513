#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

class Persona{
	public:
	struct {
    int rut[9];
    string nom,apllido;
	}reg;	
	Persona();
	~Persona();
	void datosper();
};
void Persona::datosper(){
  string nom,apellido;
  int rut;
  cout<<"DATOS USUARIOS"<<endl;
  cout<<"NOMBRE Y APELLIDO SE INGRESAN POR SEPARADO"<<endl;
  cout <<"\nIngrese su Nombre: "; cin>>nom;
  cout<<"\n Ingrese su apellido: "; cin>>apellido;
  cout <<"\nIngrese su Rut sin puntos ni guion : ";cin>>rut;
};

Persona::Persona(){
  
};
Persona::~Persona(){
  cout<<"Saliendo del programa";
};

class Asignatura{
	public:
	string a[10],c[10];
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	Asignatura();
	~Asignatura();
  void notas_as();
  void mostrarp();
	void mostrarp2();
	void mostrarp3();
	void mostrarp4();
	void mostrarp5();
  void menu();
};

Asignatura::Asignatura(){
  
};
Asignatura::~Asignatura(){
  cout<<"Saliendo del programa";
};

class profesor{
  public:
  profesor();
  ~profesor();
  void ingreso();
  void ingreso2();
  void ingreso3();
  void ingreso4();
  void ingreso5();
};

profesor::profesor(){
  
};
profesor::~profesor(){
  cout<<"Saliendo del programa";
};
void profesor::ingreso(){
  int seccion;
  cout<<"PROGRAMACION"<<endl;
  cout<<"\n1-> Seccion 1"<<endl;
  cout<<"\n2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion;
  switch(seccion){
    case 1:{
      cout<<"\nCREANDO ARCHIVO";
      ofstream archivo ("PROGRAMACION_S1.txt",ios::app);
      string alumno,apell;
      int cantidad;
      float promedio,suma=0,calif;
      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	    cout<<"\nNombre del Alumno: "<<endl; 
      cin>>alumno;
      cout<<"\nApellido del Alumno: "<<endl; 
      cin>>apell;
      archivo<<alumno<<" "<<apell<<" ";
      cin.ignore();
      float arregloCalif[4];
      cout<<"INGRESE LAS NOTAS"<<endl;
      for(int i=0;i<4;i++)
      {
          do{
      cout<<"NOTA "<<i+1<<endl;
      cin>>calif;
    }while(calif<0 || calif>7);
        arregloCalif[i]=calif;
        archivo<<calif<<" "<<fixed<<setprecision(1);
        suma = suma+arregloCalif[i];
      }
      promedio=suma/4;
      archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
      archivo.close();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    profesor prof;
    Asignatura as;
    switch(accion){
      case 1:{
        prof.ingreso();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
    }
    case 2:{
      cout<<"\nCREANDO ARCHIVO";
        ofstream archivo ("PROGRAMACION_S2.txt",ios::app);
        string alumno,apell;
        int cantidad;
        float promedio,suma=0,calif;
	      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	      cout<<"\nNombre del Alumno: "<<endl; 
        cin>>alumno;
        cout<<"\nApellido del Alumno: "<<endl; 
        cin>>apell;
        archivo<<alumno<<" "<<apell<<" ";
        cin.ignore();
        float arregloCalif[4];
        cout<<"INGRESE LAS NOTAS"<<endl;
        for(int i=0;i<4;i++)
        {
            do{
        cout<<"NOTA "<<i+1<<endl;
        cin>>calif;
      }while(calif<0 || calif>7);
          arregloCalif[i]=calif;
          archivo<<calif<<" "<<fixed<<setprecision(1);
          suma = suma+arregloCalif[i];
        }
        promedio=suma/4;
        archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
        archivo.close();
      int accion;
      cout<<"¿desea continuar agregando notas?"<<endl;
      cout<<"\n1: SI"<<endl;
      cout<<"2: NO"<<endl;
      cout<<"Seleccione una opcion: ";
      cin>>accion;
      Asignatura as;
      profesor prof;

      switch(accion){
        case 1:{
          prof.ingreso();
          break;
        }
        case 2:{
          as.menu();
          break;  
        }
      }//volver al menu
    }//caso 2
  }//switch seccion
};
void profesor::ingreso2(){
  int seccion;
  cout<<"BASE DE DATOS"<<endl;
  cout<<"\n1-> Seccion 1"<<endl;
  cout<<"\n2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion;
  switch(seccion){
    case 1:{
      cout<<"\nCREANDO ARCHIVO";
      ofstream archivo ("BASE DE DATOS_S1.txt",ios::app);
      string alumno,apell;
      int cantidad;
      float promedio,suma=0,calif;
	    cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	    cout<<"\nNombre del Alumno: "<<endl; 
      cin>>alumno;
      cout<<"\nApellido del Alumno: "<<endl; 
      cin>>apell;
      archivo<<alumno<<" "<<apell<<" ";
      cin.ignore();
      float arregloCalif[4];
      cout<<"INGRESE LAS NOTAS"<<endl;
      for(int i=0;i<4;i++)
      {
          do{
      cout<<"NOTA "<<i+1<<endl;
      cin>>calif;
    }while(calif<0 || calif>7);
        arregloCalif[i]=calif;
        archivo<<calif<<" "<<fixed<<setprecision(1);
        suma = suma+arregloCalif[i];
      }
      promedio=suma/4;
      archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
      archivo.close();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    profesor prof;
    Asignatura as;
    switch(accion){
      case 1:{
        prof.ingreso2();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
    }
    case 2:{
      cout<<"\nCREANDO ARCHIVO";
        ofstream archivo ("BASE DE DATOS_S2.txt",ios::app);
        string alumno,apell;
        int cantidad;
        float promedio,suma=0,calif;
	      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	      cout<<"\nNombre del Alumno: "; 
        cin>>alumno;
        cout<<"\nApellido del Alumno: ";
        cin>>apell;
        archivo<<alumno<<" "<<apell<<" ";
        cin.ignore();
        float arregloCalif[4];
        cout<<"INGRESE LAS NOTAS"<<endl;
        for(int i=0;i<4;i++)
        {
            do{
        cout<<"NOTA "<<i+1<<endl;
        cin>>calif;
      }while(calif<0 || calif>7);
          arregloCalif[i]=calif;
          archivo<<calif<<" "<<fixed<<setprecision(1);
          suma = suma+arregloCalif[i];
        }
        promedio=suma/4;
        archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
        archivo.close();
      int accion;
      cout<<"¿desea continuar agregando notas?"<<endl;
      cout<<"\n1: SI"<<endl;
      cout<<"2: NO"<<endl;
      cout<<"Seleccione una opcion: ";
      cin>>accion;
      Asignatura as;
      profesor prof;

      switch(accion){
        case 1:{
          prof.ingreso2();
          break;
        }
        case 2:{
          as.menu();
          break;  
        }
      }//volver al menu
    }//caso 2
  }//switch seccion
};
void profesor::ingreso3(){
  int seccion;
  cout<<"ALGORITMO Y ESTRUCTURA DE DATOS"<<endl;
  cout<<"\n1-> Seccion 1"<<endl;
  cout<<"\n2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion;
  switch(seccion){
    case 1:{
      cout<<"\nCREANDO ARCHIVO";
      ofstream archivo ("ALGORITMO Y ESTRUCTURA DE DATOS_S1.txt",ios::app);
      string alumno,apell;
      int cantidad;
      float promedio,suma=0,calif;
	    cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	    cout<<"\nNombre del Alumno: "<<endl; 
      cin>>alumno;
      cout<<"\nApellido del Alumno: "<<endl; 
      cin>>apell;
      archivo<<alumno<<" "<<apell<<" ";
      cin.ignore();
      float arregloCalif[4];
      cout<<"INGRESE LAS NOTAS"<<endl;
      for(int i=0;i<4;i++)
      {
          do{
      cout<<"NOTA "<<i+1<<endl;
      cin>>calif;
    }while(calif<0 || calif>7);
        arregloCalif[i]=calif;
        archivo<<calif<<" "<<fixed<<setprecision(1);
        suma = suma+arregloCalif[i];
      }
      promedio=suma/4;
      archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
      archivo.close();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    profesor prof;
    Asignatura as;
    switch(accion){
      case 1:{
        prof.ingreso3();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
    }
    case 2:{
      cout<<"\nCREANDO ARCHIVO";
        ofstream archivo ("ALGORITMO Y ESTRUCTURA DE DATOS_S2.txt",ios::app);
        string alumno,apell;
        int cantidad;
        float promedio,suma=0,calif;
	      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	      cout<<"\nNombre del Alumno: \n"; cin>>alumno;
        cout<<"\nApellido del Alumno: \n"; cin>>apell;
        archivo<<alumno<<" "<<apell<<" ";
        cin.ignore();
        float arregloCalif[4];
        cout<<"INGRESE LAS NOTAS"<<endl;
        for(int i=0;i<4;i++)
        {
            do{
        cout<<"NOTA "<<i+1<<endl;
        cin>>calif;
      }while(calif<0 || calif>7);
          arregloCalif[i]=calif;
          archivo<<calif<<" "<<fixed<<setprecision(1);
          suma = suma+arregloCalif[i];
        }
        promedio=suma/4;
        archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
        archivo.close();
      int accion;
      cout<<"¿desea continuar agregando notas?"<<endl;
      cout<<"\n1: SI"<<endl;
      cout<<"2: NO"<<endl;
      cout<<"Seleccione una opcion: ";
      cin>>accion;
      Asignatura as;
      profesor prof;

      switch(accion){
        case 1:{
          prof.ingreso3();
          break;
        }
        case 2:{
          as.menu();
          break;  
        }
      }//volver al menu
    }//caso 2
  }//switch seccion
};
void profesor::ingreso4(){
 int seccion;
  cout<<"DESARROLLO WEB Y MOBIL"<<endl;
  cout<<"\n1-> Seccion 1"<<endl;
  cout<<"\n2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion;
  switch(seccion){
    case 1:{
      cout<<"\nCREANDO ARCHIVO";
      ofstream archivo ("DESARROLLO WEB Y MOBIL_S1.txt",ios::app);
      string alumno,apell;
      int cantidad;
      float promedio,suma=0,calif;
	    cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	    cout<<"\nNombre del Alumno: "<<endl; 
      cin>>alumno;
      cout<<"\nApellido del Alumno: "<<endl; 
      cin>>apell;
      archivo<<alumno<<" "<<apell<<" ";
      cin.ignore();
      float arregloCalif[4];
      cout<<"INGRESE LAS NOTAS"<<endl;
      for(int i=0;i<4;i++)
      {
          do{
      cout<<"NOTA "<<i+1<<endl;
      cin>>calif;
    }while(calif<0 || calif>7);
        arregloCalif[i]=calif;
        archivo<<calif<<" "<<fixed<<setprecision(1);
        suma = suma+arregloCalif[i];
      }
      promedio=suma/4;
      archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
      archivo.close();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    profesor prof;
    Asignatura as;
    switch(accion){
      case 1:{
        prof.ingreso4();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
    }
    case 2:{
      cout<<"\nCREANDO ARCHIVO";
        ofstream archivo ("DESARROLLO WEB Y MOBIL_S2.txt",ios::app);
        string alumno,apell;
        int cantidad;
        float promedio,suma=0,calif;
	      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	      cout<<"\nNombre del Alumno: "<<endl; 
        cin>>alumno;
        cout<<"\nApellido del Alumno: "<<endl; 
        cin>>apell;
        archivo<<alumno<<" "<<apell<<" ";
        cin.ignore();
        float arregloCalif[4];
        cout<<"INGRESE LAS NOTAS"<<endl;
        for(int i=0;i<4;i++)
        {
            do{
        cout<<"NOTA "<<i+1<<endl;
        cin>>calif;
      }while(calif<0 || calif>7);
          arregloCalif[i]=calif;
          archivo<<calif<<" "<<fixed<<setprecision(1);
          suma = suma+arregloCalif[i];
        }
        promedio=suma/4;
        archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
        archivo.close();
      int accion;
      cout<<"¿desea continuar agregando notas?"<<endl;
      cout<<"\n1: SI"<<endl;
      cout<<"2: NO"<<endl;
      cout<<"Seleccione una opcion: ";
      cin>>accion;
      Asignatura as;
      profesor prof;

      switch(accion){
        case 1:{
          prof.ingreso5();
          break;
        }
        case 2:{
          as.menu();
          break;  
        }
      }//volver al menu
    }//caso 2
  }//switch seccion 
;}
void profesor::ingreso5(){
  int seccion;
  cout<<"PARADIGMAS DE PROGRAMACION"<<endl;
  cout<<"\n1-> Seccion 1"<<endl;
  cout<<"\n2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion;
  switch(seccion){
    case 1:{
      cout<<"\nCREANDO ARCHIVO";
      ofstream archivo ("PARADIGMAS DE PROGRAMACION_S1.txt",ios::app);
      string alumno,apell;
      int cantidad;
      float promedio,suma=0,calif;
	    cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	    cout<<"\nNombre del Alumno: "<<endl; 
      cin>>alumno;
      cout<<"\nApellido del Alumno: "<<endl; 
      cin>>apell;
      archivo<<alumno<<" "<<apell<<" ";
      cin.ignore();
      float arregloCalif[4];
      cout<<"INGRESE LAS NOTAS"<<endl;
      for(int i=0;i<4;i++)
      {
          do{
      cout<<"NOTA "<<i+1<<endl;
      cin>>calif;
    }while(calif<0 || calif>7);
        arregloCalif[i]=calif;
        archivo<<calif<<" "<<fixed<<setprecision(1);
        suma = suma+arregloCalif[i];
      }
      promedio=suma/4;
      archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
      archivo.close();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    profesor prof;
    Asignatura as;
    switch(accion){
      case 1:{
        prof.ingreso5();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
    }
    case 2:{
      cout<<"\nCREANDO ARCHIVO";
        ofstream archivo ("PARADIGMAS DE PROGRAMACION_S2.txt",ios::app);
        string alumno,apell;
        int cantidad;
        float promedio,suma=0,calif;
	      cout<<"NOMBRE Y APELLIDO DE INGRESAN POR SEPARADO\n";
	      cout<<"\nNombre del Alumno: "<<endl; 
        cin>>alumno;
        cout<<"\nApellido del Alumno: "<<endl; 
        cin>>apell;
        archivo<<alumno<<" "<<apell<<" ";
        cin.ignore();
        float arregloCalif[4];
        cout<<"INGRESE LAS NOTAS"<<endl;
        for(int i=0;i<4;i++)
        {
            do{
        cout<<"NOTA "<<i+1<<endl;
        cin>>calif;
      }while(calif<0 || calif>7);
          arregloCalif[i]=calif;
          archivo<<calif<<" "<<fixed<<setprecision(1);
          suma = suma+arregloCalif[i];
        }
        promedio=suma/4;
        archivo<<"El promedio es: "<<fixed<<setprecision(1)<<promedio<<endl<<"\n";
        archivo.close();
      int accion;
      cout<<"¿desea continuar agregando notas?"<<endl;
      cout<<"\n1: SI"<<endl;
      cout<<"2: NO"<<endl;
      cout<<"Seleccione una opcion: ";
      cin>>accion;
      Asignatura as;
      profesor prof;

      switch(accion){
        case 1:{
          prof.ingreso5();
          break;
        }
        case 2:{
          as.menu();
          break;  
        }
      }//volver al menu
    }//caso 2
  }//switch seccion
};

class estudiante{
  public:
  estudiante();
  ~estudiante();
  void notas();
};

estudiante::estudiante(){
  
};
estudiante::~estudiante(){
  cout<<"Saliendo del programa";
};
void estudiante::notas(){
  cout<<"NOTAS ASIGNATURAS"<<endl;
  cout<<"1. PR001"<<endl;
  cout<<"2. BD002"<<endl;
  cout<<"3. AE003"<<endl;
  cout<<"4. DM004"<<endl;
  cout<<"5. PP005"<<endl;
  int res;
  Asignatura as;
  cout<<"Seleccione una opcion: "<<endl; cin>>res;
  switch(res){
    case 1:{
      as.mostrarp();
      break;
    }//caso 1
    case 2:{
      as.mostrarp2();
      break;
    }//caso 2
    case 3:{
      as.mostrarp3();
      break;
    }//caso 3
    case 4:{
      as.mostrarp4();
      break;
    }//caso 4
    case 5:{
      as.mostrarp5();
      break;
    }//caso 5
    int accion;
    cout<<"¿desea continuar viendo notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;
    estudiante es;
    switch(accion){
      case 1:{
        es.notas();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//switch accion
  }//switch res
};

void Asignatura::notas_as(){
  int opcion,opc;
	cout<<"Seleccione las Asignaturas: ";
	cout<<"\n 1. "<<mat[0];
	cout<<"\n 2. "<<mat[1];
	cout<<"\n 3. "<<mat[2];
	cout<<"\n 4. "<<mat[3];
	cout<<"\n 5. "<<mat[4];
	cout<<"\n Seleccione una Opcion: ";
	cin>>opcion;
  for (int i=0;i<5;i++){
    switch (opcion){
      case 1: {
        a[i]=mat[0];
			  c[i]=cod[0];
			  break;
		  }
		  case 2: {
			  a[i]=mat[1];
			  c[i]=cod[1];
			  break;
		  } 
		  case 3: {
			  a[i]=mat[2];
			  c[i]=cod[2];
			  break;
		  } 
		  case 4: {
			  a[i]=mat[3];
        c[i]=cod[3];
			  break;
		  } 
		  case 5: {
			  a[i]=mat[4];
			  c[i]=cod[4];
			  break;
		  } 
		}
  }
  if (opcion==1){
    profesor prof;
    prof.ingreso();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;

    switch(accion){
      case 1:{
        as.notas_as();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//volver al menu
  }
  else if (opcion==2){
    profesor prof;
    prof.ingreso2();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;

    switch(accion){
      case 1:{
        as.notas_as();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }//volver al menu
  }
  else if (opcion==3){
    profesor prof;
    prof.ingreso3();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;

    switch(accion){
      case 1:{
        as.notas_as();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }
  }//volver al menu
  else if (opcion==4){
    profesor prof;
    prof.ingreso4();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;

    switch(accion){
      case 1:{
        as.notas_as();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }
  }//volver al menu 
  else if (opcion==5){
    profesor prof;
    prof.ingreso5();
    int accion;
    cout<<"¿desea continuar agregando notas?"<<endl;
    cout<<"\n1: SI"<<endl;
    cout<<"2: NO"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>accion;
    Asignatura as;

    switch(accion){
      case 1:{
        as.notas_as();
        break;
      }
      case 2:{
        as.menu();
        break;  
      }
    }
  }//volver al menu
};
void Asignatura::mostrarp2(){
  int seccion2;
  cout<<"BASE DE DATOS"<<endl;
  cout<<"1-> Seccion 1"<<endl;
  cout<<"2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion2;
  switch(seccion2){
    case 1:{
      ifstream archivo;
      archivo.open("BASE DE DATOS_S1.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//case 1
    case 2:{
      ifstream archivo;
      archivo.open("BASE DE DATOS_S2.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//caso 2
  }//switch seccion
};
void Asignatura::mostrarp3(){
  int seccion2;
  cout<<"ALGORITMO Y ESTRUCTURA DE DATOS"<<endl;
  cout<<"1-> Seccion 1"<<endl;
  cout<<"2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion2;
  switch(seccion2){
    case 1:{
      ifstream archivo;
      archivo.open("ALGORITMO Y ESTRUCTURA DE DATOS_S1.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//case 1
    case 2:{
      ifstream archivo;
      archivo.open("ALGORITMO Y ESTRUCTURA DE DATOS_S2.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//caso 2
  }//switch seccion
};
void Asignatura::mostrarp4(){
  int seccion2;
  cout<<"DESARROLLO WEB Y MOBIL"<<endl;
  cout<<"1-> Seccion 1"<<endl;
  cout<<"2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion2;
  switch(seccion2){
    case 1:{
      ifstream archivo;
      archivo.open("DESARROLLO WEB Y MOBIL_S1.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//case 1
    case 2:{
      ifstream archivo;
      archivo.open("DESARROLLO WEB Y MOBIL_2.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//caso 2
  }//switch seccion
};
void Asignatura::mostrarp5(){
  int seccion2;
  cout<<"PARADIGMAS DE PROGRAMACION"<<endl;
  cout<<"1-> Seccion 1"<<endl;
  cout<<"2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion2;
  switch(seccion2){
    case 1:{
      ifstream archivo;
      archivo.open("PARADIGMAS DE PROGRAMACION_S1.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//case 1
    case 2:{
      ifstream archivo;
      archivo.open("PARADIGMAS DE PROGRAMACION_S2.txt");
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//caso 2
  }//switch seccion
};
void Asignatura::mostrarp(){
  int seccion2;
  cout<<"PROGRAMACION"<<endl;
  cout<<"1-> Seccion 1"<<endl;
  cout<<"2-> Seccion 2"<<endl;
  cout<<"Seleccione una opcion: ";
  cin>>seccion2;
  switch(seccion2){
    case 1:{
      ifstream archivo;
      archivo.open("PROGRAMACION_S1.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//case 1
    case 2:{
      ifstream archivo;
      archivo.open("PROGRAMACION_S2.txt");
      if(archivo.fail()){
        cout<<"No hay notas en el sistema para esta asignatura"<<endl;
      }
      string linea,texto;
      while (getline(archivo, linea)) {
        texto = texto+linea+"\n";
      }
      cout<<texto<<endl;
      Asignatura as;
      as.menu();
      break;
    }//caso 2
  }//switch seccion
};


void Asignatura::menu(){
  int opc;
	cout<<"SISTEMA DE NOTAS UNIVERSIDAD ANDRES BELLO \n";
	cout<<"1. Profesor \n";
	cout<<"2. Estudiante \n";
	cout<<"3. Salir \n";
	cout<<"Seleccionar Opcion: ";
	cin>>opc;
  Asignatura as;
  estudiante es;
  profesor prof;
  Persona p;
  switch (opc){
		case 1:
      int op;
      cout<<"\n1 INGRESAR NOTAS"<<endl;
      cout<<"\n2 VER NOTAS"<<endl;
      cout<<"\nSeleccione una opcion: "; cin>>op;
      switch(op){
        case 1:{
          as.notas_as();
          break;
        }
        case 2:{
          es.notas();
          break;
        }
      }
		case 2:{
      p.datosper();
			es.notas();
			break;
    }
		case 3:{
			cout<<"Saliendo del sistema";
      exit(1);
      break;
    }
	}
};

int main(int argc, char** argv) {
	Asignatura as;
  as.menu();
}