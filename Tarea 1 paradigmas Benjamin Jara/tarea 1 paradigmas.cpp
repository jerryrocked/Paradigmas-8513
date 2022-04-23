//Benjamin Jara

#include<iostream>
#include<string>
#include<string.h>
#include<strings.h>
#include<cstdlib>
#include<cstdio>
#include<fstream> //para declarar un archivo
#include<iomanip>
using std::cout; using std::fstream;
using std::endl; using std::string;
using namespace std;

/*------------------CLASE PERSONA--------------------*/
class persona{
  protected: //metodos
  int i;
  string nom,rut,dir,telf; 
  string n[200];
  int edad;
  public: //atributos
  void datos_persona(); //constructor
  void persona_profe();
  void mostrardat();
};
void persona::datos_persona(){ //construimos la clase persona
  struct
    {
        int i;
        string _nom;
        string n[200];
        int   _edad;
        int _rut;
        float _nota;
        string _nomasig;
    } persona;
    //struct persona arreglop[100];
    cout<<"Escriba el Nombre: ";
    cin>>persona._nom;
 /*   cout<<"Escriba la Edad: ";
    cin>>persona._edad;*/
    cout<<"Escriba su rut: ";
    cin>>persona._rut;
    cout<<"\n";
    cout<<"\n";
    cout<<"Estimado alumno "<<persona._nom<<endl;
};

/*-----------------CLASE PROFESOR---------------*/

class profesor: public virtual persona{//declaramos la clase herencia 
    public: //atributos
    profesor(){ }; //contructor
    //~profesor(){ };
    void persona_profe();	
    void mostrar_prof();
    void entregarnotas();
};
//constructor clase profesor
void profesor::persona_profe(){
  cout<<"\n";
  cout<<"------Sección profesor.--------"<<endl;

  ofstream archivo; //creamos archivo txt 
  float nota[4];
  string apr;
  char s;
  char opc;
  float promedio;
  string nombreasig, seccion, nom;
  while(s== 's'){
  cin.ignore(); // descarta el último '\n' 
/* Funciona de modo que el usuario profesor pone el numero de seccion y crea el archivo txt, luego va añadiendole el nombre del alumno, sus notas y automáticamente indica su promedio y su  estado de aprobacion o reprobacion de la asignatura*/
  cout<<"\nAsignaturas.";
  cout<<"\n";
  cout<<"\nProgramación -> PR001";
  cout<<"\nBase de Datos -> BD002";
  cout<<"\nAlgoritmo y estructura de datos -> AE003";
  cout<<"\nDesarrollo Web y Movil -> DM004";
  cout<<"\nParadigmas de programación -> PP005";
  cout<<"\n";
  cout<<"\nIngrese el codigo de la asignatura (En mayúscula): ";cin>>seccion; 
  archivo.open(seccion,std::ios_base::app); //abre el archivo
  if (archivo.fail()){ //si no se puede crear la seccion se sale
    cout<<"No se pudo crear la seccion";
    exit(1);
    }
        cin.ignore();
        cout<<"\nNombre del estudiante: ";getline(cin, nom);
        archivo.write(nom.data(), nom.size()); //Permite agregar mas alumnos al txt
        cout<<"\ningresa nota 1: ";cin>>nota[0]; //agrega las notas al txt
        cout<<"\ningresa nota 2: ";cin>>nota[1];
        cout<<"\ningresa nota 3: ";cin>>nota[2];
        cout<<"\ningresa nota 4: ";cin>>nota[3];
        promedio = (nota[0] + nota [1] + nota [2] + nota[3])/4;
        if (promedio>= 3.9){  // condiciona el promedio indicando si reprueba o aprueba 
          apr = " -> APROBADO";
            }
        else
          apr = " -> REPROBADO";
    
      archivo<<": "<<fixed<<setprecision(1)  <<nota[0]<<" "<<nota[1]<<" "<<nota[2]<<" "<<nota[3]<<" "<<"promedio -> "<<promedio<<" "<<apr<<endl; //mostrar en el archivo
    archivo.close();
    cout<<"\nDesea subir mas notas? (s) o (n) ";cin>>s;//condicionfin del while
  
    }
  };
/*----------------CLASE ALUMNO-----------------*/

class estudiante: public persona/*,public asignatura*/{
  protected: //metodos
    string carrera,mat[5];
    int cantmat;
  public: //atributos
    void datos_estud();
    void mostrarest();
};
/* Lee el archivo txt. Pide el nombre de la seccion para abrir el archivo ya que cada archivo tiene el nombre de la seccion de la asignatura*/
void estudiante::datos_estud(){
  datos_persona(); //herencia de persona
  float promedio;
  string seccion;
  cout<<"\nIngrese el codigo de seccion para ver las notas (En mayúscula): ";cin>>seccion;//ingresa el codigo de seccion para revisar las notas de la seccion
   //string archivo1="archivo1.txt";
    ifstream archivo(seccion.c_str());
  if (archivo.fail()){
    cout<<"No se han subido las notas";
    }
    string linea,nomb,n1,n2,n3,n4;
    int res, lon, i, j=0;
    string arreglo[100];
    char b,l;
    cout<<"Las notas de la seccion "<<seccion<<" son: ";
    cout<<"\n";
    cout<<"\n";
    while (getline(archivo,linea)){
        cout<<linea<<endl; 
        lon = linea.length();
        for (i=0;i<lon;i++){
            i=linea[i];
            b = ' ';
            if (l!=b){
                if(j==0)
                   nomb = nomb+linea[i];
                if(j==1)
                   n1=n1+linea[i]; 
                if(j==2)
                   n2=n2+linea[i];
                if(j==3)
                   n3=n3+linea[i];
                if(j==4)
                   n4=n4+linea[i]; 
            }
            else
                j++;
        }
        cout<<"\n";
        cout<<nomb;
        cout<<n1;
        cout<<n2;
        cout<<n3;
        cout<<n4;
        j=0;
        nomb = " ";
        n1= " ";
        n2= " ";
        n3= " ";
        n4= " ";
      }
    if (j == NULL){ //si el texto esta vacío no ha subido las notas
      cout<<"\n";
      cout<<"Las notas aún no se suben a la plataforma";
  }
    
};

//---------------CLASE ASIGNATURA--------------//

class asignatura: public profesor{
    protected: //metodos
    string asig[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOVIL","PARADIGMAS DE PROGRAMACION"};
    string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
    public: //atributos
    void mostrarasig();
};
void asignatura::mostrarasig(){
  //persona_profe();
  float nota[4];
  float suma=0;
  float promedio;
  float arregloprom[i];
  string seccion;
  cout<<"\nIngrese sección para ver promedios (En mayúscula): ";cin>>seccion;//ingresa el codigo de seccion para revisar las notas de la seccion
   //string archivo1="archivo1.txt";
    ifstream archivo(seccion.c_str());
  if (archivo.fail()){
    cout<<"No se han subido las notas";
    }
    string linea,nomb,n1,n2,n3,n4,n5;
    string prom;
    int res, lon, i, j=0;
    string arreglo[100];
    char b,l;
    cout<<"\n";
    cout<<"Los promedios de la seccion "<<seccion<<" son: ";
    cout<<"\n";
    cout<<"\n";
    while (getline(archivo,linea)){
        cout<<linea<<endl; 
        lon = linea.length();
        for (i=0;i<lon;i++){
            i=linea[5];
            b = ' ';
            if (l!=b){
                if(j==0)
                   nomb = nomb+linea[i];
                if(j==1)
                   n1=n1+linea[i]; 
                if(j==2)
                  n2=n2+linea[i];
                if(j==3)
                   n3=n3+linea[i];
                if(j==4)
                   n4=n4+linea[i];
                if(j==5)
                   n5 = n5+linea[5];
                if(j==6)
                   prom = prom+linea[6];
            }
            else
                j++;
        }
        cout<<"\n";
        cout<<nomb;
        //cout<<n5;
        cout<<prom;
        j=0;
        nomb = " ";
        n5 = " ";
        prom = " ";

      }
}
int main()
{
	persona p; //funcion p de tipo persona
  profesor f; //funcion f de tipo profesor
  estudiante e; //funcion e de tipo estudiante
  asignatura a; //funcion a de tipo asignatura
	char res;
	int opcion;
	while(res == 's'){
		cout<<"---- Universidad Andres Bello ----"<<endl;
	
		cout<<"1. Profesor."<<endl;
		cout<<"2. Estudiante."<<endl;
    cout<<"3. Asignaturas."<<endl;
    cout<<"4. Salir."<<endl;
		cout<<"Seleccione una opcion: ";cin>>opcion;
		
		switch(opcion){
			case 1:{
				f.persona_profe();
        break;
			}
			case 2:{
        e.datos_estud();
				break;
			}
      case 3:{
        a.mostrarasig();
         
        break;
      }
      case 4:{
        cout<<"Saliendo del programa.";
        cin.get(); //finaliza el codigo
        return 0;
        break;
      }
		}
		cout<<"\nDesea continuar? escriba (s) o (n) ";cin>>res;
    if (res == 'n'){
      cout<<"Saliendo del programa.";
    }
	  cout<<"\n";

	}

}
