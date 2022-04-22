//librerias a utilizar
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Persona{
    public:
        string nombre[50];
        string rut[50];
        int i=0;
    void Guardar(); // registrar nuevo usuario
    void mostrar_df();
};//aqui podemos ver la clase persona la cual se encargara de guardar la variables nombre, rut de tipo string ademas podemos tener la variable i que sera utilizada mas adenlante en el codigo y con sus respectivas funciones

class alumno : public Persona{
    public:
        int seccion; // secciones correspondientes 1, 2, 3
    void soli_nota(); // funcion para pedir sus notas
};//en esta clase podremos apreciar la clase alumno que hereda los datos de persona y ademas esta en publico contiene una funcion la cual es solicitud de notas y una variable entera que son las secciones

class Ramos{
    public:
        string nrc[3] = {" SEC 8790 "," SEC 8892 "," SEC 15678 "};//introducimos las secciones correspondientes.
        string ID[5] = {" PR001 PROGRAMACION"," BD002 BASE DE DATOS"," AE003 ALGORITMOS Y ESTRUCTURA DE DATOS"," DM004 DESARROLLO WEB MOVIL"," PP005 PARADIGMA DE PROGRAMACION"};//introduciremos las materias con sus id repectivas
        string Ramos_nombres[5] = {"PROGRAMACION","BASE DE DATOS", "ALGORITMOS Y ESTRUCTURA DE DATOS", "DESARROLLO WEB Y MOVIL", "PARADIGMAS DE PROGRAMACION"};//a continuacion tendremos los nombres de los ramos pedidos en el proyecto a realizar

};//en esta parte del codigo podemos identificar la clase materia la cual sera publica y ademas tendra dos variables que se definiran como string tanto de NRC, ID y ademas materia con sus respectivos nombres.

class Profesor : public Persona,public Ramos{
    public:
        void crear_archivo();// esta funcion permitira crear el archivo y puedan salir con su informacion correspondiente
        void nota_alumno(string rut2, int Ramo);
        void cargar_archivo();//en esta  funcion permitira que el archivo pueda ser cargado
    private://sera privado ya que el profesor calculara las notas
        float ND,nt[4];
    void calcular_ND();
};//en la clase profesor podremos observar que contiene el publico de la persona y ademas de ramos lo que heredara el profesor para obtener la informacion respectiva de los alumnos que el ingrese con sus respectivas notas

void Profesor::calcular_ND(){
    ND = nt[0] + nt[1] + nt[2] + nt[3];//notas a calcular
    ND = ND / 4;//promedio de las notas ingresadas
}//en la siguiente funcion podremos observar que calculara las notas de cada estudiante y se iran para la clase profesor

void Persona::Guardar(){
    bool flag = true;//se crea esta variable con el fin de comprobar que la funcion y el while pueda funcionar
    int option = 0;
    while(flag == true){
        cin.ignore();
        cout<<"Ingrese su nombre y apellido: ";//se ingresa el nombre y el apellido
        getline(cin,nombre[i]);
        cout<<"Ingrese su rut con puntos y guion: ";//se ingresa el rut completo de la persona
        getline(cin,rut[i]);
        i++;
        cout<<"Desea ingresar otra persona?: (1)/(0) ";
        cin>>option;
        if(option == 0){
            flag = false;
        }
        mostrar_df();
    }
}//en la siguiente funcion podemos decir que cada persona es ingresada para ser guardada en su respectiva casilla correspondiente

void Persona::mostrar_df(){
    cout<<"\n";
    for(int j=0;j<=i;j++){
        cout<<nombre[j]<<"\t"<<rut[j]<<endl;
    }
}//esta funcion permitira que cada estudiante sea imprimido con su rut y nombre correspondiente

void alumno::soli_nota(){
    while(true){
        string name;
        cout<<"Ingrese su rut con puntos y guion: ";//se ingressa el rut completo
        cin>>name;
        name += ".txt";//se le agrega el .txt para que pueda ser impreso a continuacion cuando el alumno solicite sus notas
        cout<<endl;
        ifstream f;
        string line;
        f.open(name,ios::in);
        if(f.fail()){cout<<"El profesor no ha subido sus notas.\n";break;}//se valida si el profesor a subido las notas de el alumno
        while(!f.eof()){//el while permitira que el lea el archivo y diga cuantas ramos a aprobado el alumno con su respectivo rut
            getline(f,line);
            cout<<line<<endl;
        }
    cout<<"\n EL ALUMNO A APROBADO O REPROBADO LOS SIGUIENTES RAMOS \n";
    break;
    }
}//en esta funcion es donde el alumno podra solicitar su nota y podra ver si esta cargada o de lo contrario si el profesor aun no la ha subido le dira que no esta no se encuentra aun en el sistema

void Profesor::crear_archivo(){
    int Ramos,seccion;//se crean variables enteras para su ingreso
    string nombre2,ape,rut2;//se crearan variables string para su ingreso
    int op = 1;
    while(true){
        cout<<"\n---Bienvenido al ingreso de notas manualmente.---\n\n";
        cout<<"Seleccione el codigo de Ramo que imparte:\n"<<ID[0]<<" (0)\n"<<ID[1]<<" (1)\n"<<ID[2]<<" (2)\n"<<ID[3]<<" (3)\n"<<ID[4]<<" (4)\n: ";
        cin>>Ramos;
        if(Ramos < 0 || Ramos > 4){//en esta parte tendra un validador para poder identificar que el usuario ingrese los numeros correctos
            cout<<"\n--------ERROR AL INGRESAR LOS DATOS INTENTE NUEVAMENTE--------\n";
            break;
        }
        cout<<"\nSeleccione la seccion:\n"<<nrc[0]<<" (0)\n"<<nrc[1]<<" (1)\n"<<nrc[2]<<" (2)\n: ";
        cin>>seccion;
        if(seccion < 0 || seccion > 2){
            cout<<"\n--------ERROR AL INGRESAR LOS DATOS INTENTE NUEVAMENTE--------\n";
            break;
        }
        system("clear");
        string name = nrc[seccion];//se guardaran los datos correspondientes
        name += ID[Ramos];
        name += ".txt";
        ofstream f;
        f.open(name, fstream::app);//se abrira el archivo para y se guardara todo lo que se ingrese.
        while(op==1){
            cout<<"Ingrese el nombre, apellido y rut del estudiante: \n"; 
            cin>>nombre2>>ape>>rut2;
            for(int i=0;i<4;i++){
                cout<<"Ingrese la nota numero: "<<i+1<<": ";
                cin>>nt[i];
              if(nt[i]> 0 && nt[i] <= 7){}
              else{
                cout<<"Ingreso mal la nota vuelva a intentarlo denuevo"<<endl;
                i--;
              }
            }
            calcular_ND();//funcion que permitira el calculo de las notas
            nota_alumno(rut2, Ramos);
            f<<nombre2<<" "<<ape<<" "<<ND<<endl;
            cout<<"\nDesea ingresar mas alumnos? (1 = si)/(0 = no): ";//si de desea ingresar alumnos que los agrege
            system("clear");//limpiara la pantalla
            cin>>op;
            if(op==0){//validador que si la opcion es 0 no se agregaran mas estudiantes
                break;
            }
        }
        f.close();
        cout<<"\n Se han guardado correctamente los estudiantes \n";
        break;
    }
}//en esta funcion lo que hace se va ingresar la materia y ademas si se desean agregar mas alumnos con ello lo guardara o seguira ingresando alumnos para asi poder tener el documento con sus respectivas notas

void Profesor::nota_alumno(string rut2,int ramos){
    string estado = "Reprobado";
    if(ND >= 4){//validador que nos permitira saber si el alumno reprobo o aprobo el ramo entregado
        estado = "Aprobado";
    }
    rut2 += ".txt";
    ofstream f;
    f.open(rut2, fstream::app);//se abrira el archivo y se guardaran con los datos ingresados
    f<<Ramos_nombres[ramos]<<" "<<ND<<" "<<estado<<endl;
    f.close();
}//esta funcion nos permitira si el alumno esta aprovando o reprobando el curso ingresado

int menu(){
    int x;
    cout<<"\n--- Bienvenido al sistema de notas Unab ---\n\n";
    cout<<"-------------Menu de profesores-------------\n";
    cout<<"Registrar notas manualmente (1)"<<endl;
    cout<<"Cargar archivo (2)"<<endl;
    cout<<"-------------Menu de estudiante-------------- \n";
    cout<<"Solicitar nota de alumno (3)"<<endl;
    cout<<"---------------------------------------------\n";
    cout<<"Salir del menu (4)"<<endl;
    cout<<"\nIngrese una opcion: ";
    cin>>x;
    return x;
}//aqui se realizo un menu con el fin que pueda leer una variable entera asignada como x y asi poder trabajar con el menu

void Profesor::cargar_archivo(){
    int Ramo,seccion;
    while(true){//este while nos permitira identificar en todo el programa que se ingresen las notas correctamente con sus respectivos validadores y condiciones
        cout<<"\n---Bienvenido al ingreso de notas mediante archivo.txt.---\n\n";
        cout<<"Seleccione el codigo de materia que imparte:\n"<<ID[0]<<" (0)\n"<<ID[1]<<" (1)\n"<<ID[2]<<" (2)\n"<<ID[3]<<" (3)\n"<<ID[4]<<" (4)\n: ";
        cin>>Ramo;
        if(Ramo < 0 || Ramo > 4){
            cout<<"\n--------ERROR AL INGRESAR LOS DATOS INTENTE NUEVAMENTE--------\n";
            break;
        }
        cout<<"\nSeleccione la seccion:\n"<<nrc[0]<<" (0)\n"<<nrc[1]<<" (1)\n"<<nrc[2]<<" (2)\n: ";
        cin>>seccion;
        if(seccion < 0 || seccion > 2){
            cout<<"\n--------ERROR AL INGRESAR LOS DATOS INTENTE NUEVAMENTE--------\n";
            break;
        }
        else{
            string name;
            name += nrc[seccion];
            name += ID[Ramo];
            name += ".txt";
            ofstream fe;
            ifstream f;
            string filename;
            string nom,ape,rut2;
            cout<<"Ingrese el nombre nombre del archivo (sin .txt): ";
            cin>>filename;
            filename += ".txt";
            f.open(filename, ios::in);
            if(f.fail()){cout<<"\nEl archivo no existe intente nuevamente \n";break;}
            fe.open(name, fstream::app);
            while(!f.eof()){
                f>>nom>>ape>>rut2>>nt[0]>>nt[1]>>nt[2]>>nt[3];
                calcular_ND();
                fe<<nom<<" "<<ape<<" "<<ND<<endl;
                nota_alumno(rut2, Ramo); 
            }
        cout<<"\nlos alumnos aprobados y reprobados son\n";
        break;    
        }
    }
    
}//esta funcion nos permite realizar el cargo de un archivo existente que tenga el profesor y quiera ingresar de una manera mas comoda y asu gusto con su respectivo nombre

int main() {
    int op;
    Profesor P;
    alumno A;
    do{
        op = menu();
        switch (op){//se crea un menu con el switch nos permitira tener diferentes casos que se puedan basar de acuerdo a lo que pida el estudiante o el alumno.
            case 1:
                P.crear_archivo();
                break;
            case 2:
                P.cargar_archivo();
                break;
            case 3:
                A.soli_nota();
            break;
        }
    }while (op != 4);
    
    return 0;
}//en el programa principal llamaremos todas las funciones y clases para que el programa pueda funcionar de manera optima con diferentes casos que seleccione el profesor