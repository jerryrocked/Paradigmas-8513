#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Estructura para almacenar nodos de la lista
// será una lista de nombres
// por lo tanto cada elemento de la lista estará
// compuesto por una cadena que contendrá el nombre
// a almacenar y un puntero que servirá para apuntar
// al siguiente nodo de la lista, a este tipo de lista
// se les denomina de enlace simple.
class nuevo{
  public:
    char nombre[50];

};

typedef struct NodoLista : public nuevo{


  struct NodoLista *Siguiente;

} Nodo;

// Predefinición de funciones

int InsertarElemento(Nodo **);

void ListarElementos(Nodo *);

int BorrarElementoListaFinal(Nodo **);

int BorrarElementoListaPrincipio(Nodo **);

int BorrarElementoIntermedio(Nodo **);

// Función principal
int main(int argc, char *argv[])

{
    // Crear el puntero Raíz de la lista
    // y se inicializa a nulo como valor
    // inicial
    Nodo *Inicio = NULL;
    // Crear una variable para solicitar las
    // opciones del menú
    int opcion=0;
    int opcion2=0;
    // Visualizar el menu de opciones
    do {
        cout<<"\n1.- Insertar elemento en la lista.";
        cout<<"\n2.- Listar elementos de la lista.";
        cout<<"\n3.- Borrar elemento de la lista.";
        cout<<"\n0.- Salir del programa.";
        cout<<"\n=====================================";
        cout<<"\nOpcion ...: ";
        cin>>opcion;
        switch(opcion) {

          case 1:
               // Insertar elemento de la lista
               // El puntero de inicio se ha de pasar por referencia
               // ya que es puede verse afectado si se inserta el primer
               // elemento de la lista
               InsertarElemento(&Inicio);
               break;

          case 2:

               ListarElementos(Inicio);
               break;
          case 3:
               cout<<"\n(0) Volver Menu Anterior.";
               cout<<"\n(1) Borrar al final.";
               cout<<"\n(2) Borrar al principio.";
               cout<<"\n(3) Borrar Intermedio.";
               cout<<"\n.... ";
               cin>>opcion2;

               switch(opcion2) {

                 case 1:

                      BorrarElementoListaFinal(&Inicio);

                      break;

                 case 2:

                      BorrarElementoListaPrincipio(&Inicio);

                      break;
                 case 3:

                      BorrarElementoIntermedio(&Inicio);
                      break;
               }
               break;
        }
    } while(opcion!=0);
  system("PAUSE" );
  return 0;

}
// Función para insertar un elemento en la lista
// al final de la misma, como se puede observar
// el puntero de inicio que se recibe se ha pasado
// por referencia y por tanto se ha de especificar
// con un doble asterisco
int InsertarElemento(Nodo **Inicio)
{
     Nodo *Elemento = NULL;
     Nodo *Recorrer = NULL;
     Nodo *Ultimo = NULL;
     // Recorremos la lista hasta llegar al final
     // de la misma, en el puntero ultimo se quedara
     // almacenado la dirección de memoria del ultimo
     // elemento de la lista, si no existe ningún elemento
     // en la lista se queda con valor nulo asignado
     // En primer lugar se asigna el contenido del puntero
     // de inicio al puntero recorrer
     Recorrer = *Inicio;
     while(Recorrer!=NULL) {
       Ultimo = Recorrer;
       Recorrer=Recorrer->Siguiente;
     }
     // Creamos el nuevo nodo o elemento que se quiere
     // insertar
     Elemento = (Nodo *)malloc(sizeof(Nodo));
     // si ha existido un problema y no se crea el elemento
     // devolver un error, este tipo de interrupción del código
     // es preferible realizarlo utilizando condicionales y
     // insertando un return para forzar la finalización de
     // la función
     if(Elemento == NULL ) return -1;
     // Si se llega a este punto el elemento ha sido creado y
     // solicitamos el nombre que se ha de almacenar en el
     // mismo
     cout<<"\nTeclear Nombre : ";
     cin>>Elemento->nombre;
     // asignamos el valor nulo al puntero siguiente de la lista
     // ya que este elemento será el ultimo de la misma y por
     // tanto no hay mas elementos posteriores
     Elemento->Siguiente = NULL;
     // Modificamos el puntero siguiente del ultimo elemento de la

     // lista para que apunte al elemento nuevo creado preguntando
     // primero si el valor de ultimo es null, ya que si es así
     // significa que el elemento nuevo creado es el primero y por
     // tanto hay que modificar el puntero de inicio
     if (Ultimo == NULL ) {
        // Es el primero de la lista
        *Inicio = Elemento;
     } else {
        // Es el ultimo de la lista
       Ultimo->Siguiente = Elemento;
     }
     // Salir de la función sin errores
     return 0;
}

// Función para listar elementos de la lista
// Se recibe como valor el contenido del puntero
// que indica el primer elemento de la lista
void ListarElementos(Nodo *Inicio)
{
     // Se crea una variable para recorrer la lista
     // asignándole como primer valor el elemento al
     // cual apunta el puntero de inicio
     Nodo *Recorrer = Inicio;
     // Se visualiza un mensaje
     cout<<"\nListado de elementos de la lista";
     cout<<"\n===================================";
     // Si hay elementos en la lista se recorre
     // intercambiando el valor del puntero siguiente
     // asignándolo al puntero recorrer que indica que
     // existe o no un elemento según su valor
     while(Recorrer!=NULL)
     {
        // Se visualiza el elemento
        cout<<"\n%s"<<Recorrer->nombre;
        // Se cambia al elemento siguiente
        Recorrer=Recorrer->Siguiente;
     }
     cout<<"\n===================================\n";
}
// Función Borrar elemento de la lista al principio
int BorrarElementoListaPrincipio(Nodo **Inicio)
{
    // Variable para almacenar el elemento a borrar
    Nodo *Borrar=NULL;
    // Se comprueba si el puntero de inicio apunta a
    // algún elemento si es así es que existen elementos
    // y se puede borrar el primero en caso contrario
    // no existe ningún elemento y no se puede borrar nada
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n";
       return -1;
    } else {
      Borrar = *Inicio;
      *Inicio = (*Inicio)->Siguiente;
      free (Borrar);
    }
    return 0;
}
// Función Borrar elemento de la lista al final
int BorrarElementoListaFinal(Nodo **Inicio)
{
    Nodo *Borrar=NULL;;
    Nodo *Recorrer=NULL;
    Recorrer=*Inicio;
    if(Recorrer==NULL) {
     cout<<"\nNo existen elementos que borrar\n";
     return -1;
    }
    // Mientras no se llegue al ultimo elemento
    while(Recorrer->Siguiente!=NULL) {
      Borrar = Recorrer;
      Recorrer= Recorrer->Siguiente;
    }
    // Si borrar es null es que solo existe un elemento
   // y por tanto el valor de inicio ha de cambiar si no
   // es así existen mas elementos y se ha borrar el ultimo
   if(Borrar==NULL) {
       Borrar = *Inicio;
      *Inicio = NULL;
      free (Borrar);
   } else {
     free(Borrar->Siguiente);
     Borrar->Siguiente=NULL;
   }
    return 0;
}


// Función Borrar elemento de la lista al principio
int BorrarElementoIntermedio(Nodo **Inicio)
{
    // Variables para usar la lista
    Nodo *Recorrer=NULL;
    Nodo *Borrar=NULL;
    Nodo *Anterior=NULL;
    // Variable para solicitar el elemento a borrar
    char NombreBuscar[30];
    int encontrado=0;
    // Solicitar el nombre a eliminar
    cout<<"\nNombre a eliminar: ";
    cin>>NombreBuscar;
    // Se comprueba si el puntero de inicio apunta a
    // algún elemento si es así es que existen elementos
    // y se puede borrar el primero en caso contrario
    // no existe ningún elemento y no se puede borrar nada
    if (*Inicio==NULL) {
       cout<<"\nNo hay elementos que borrar\n";
       return -1;
    } else {
        // Recorrer la lista buscando el elemento
        cout<<"\nBuscando: %s "<<NombreBuscar;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer!=NULL && encontrado==0)
        {
            // Se visualiza el elemento
            cout<<".";
            if(strcmp(Recorrer->nombre,NombreBuscar)==0) {
                cout<<" (Encontrado Ok)\n";
                encontrado=1;
                Borrar = Recorrer;
                if(Recorrer==*Inicio) {
                    *Inicio = Recorrer->Siguiente;
                } else {
                    Anterior->Siguiente = Borrar->Siguiente;
                }
                free(Borrar);
            } else {
                // Se cambia al elemento siguiente
                Anterior = Recorrer;
                Recorrer=Recorrer->Siguiente;
            }
        }
    }
    return 0;
}
