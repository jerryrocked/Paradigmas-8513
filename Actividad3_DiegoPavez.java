package Actividad3;
import java.util.Scanner;
import static java.lang.Math.abs;
public class Actividadtres {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("* * * * * * * * * * * * * * *\n"
                +          "* ¡Bienvenido al banco XYZ! *\n"
                +          "*                           *\n"
                +          "*   Seleccióne una de las   *\n"
                +          "*    siguientes opciones:   *\n"
                +          "*                           *\n"
                +          "*    1.Cuenta Ahorro        *\n"
                +          "*    2.Cuenta Corriente     *\n"
                +          "*    3.Cuenta plazo a fijo  *\n"
                +          "*                           *\n"
                +          "* * * * * * * * * * * * * * *");
        System.out.print("Ingrese una opción: ");
        int opcion=sc.nextInt();     
        switch(opcion){
            case 1:
                float monto1,ganancia1;
                System.out.print("Ingrese el monto del deposito: ");
                monto1 = sc.nextFloat();
                ganancia1=monto1/100;
                System.out.println("Con Cuenta Ahorro, estaría ganando en un año "+abs(ganancia1)+" pesos.");
                break;
            case 2:
                float monto2,ganancia2;
                System.out.print("Ingrese el monto del deposito: ");
                monto2 = sc.nextFloat();
                ganancia2=(monto2*0.5f)/100;
                System.out.println("Con Cuenta Corriente, estaría ganando en un año "+abs(ganancia2)+" pesos.");
                break;
            case 3:
                System.out.println("""
                                   Cantidad de meses a consultar:
                                   1.Tres meses
                                   2.Seis meses
                                   """);
                System.out.print("Escoga una opción: ");
                int opcion3 = sc.nextInt();
                if(opcion3==1){
                    float monto3,ganancia3;
                    System.out.print("Ingrese el monto del deposito: ");
                    monto3 = sc.nextFloat();
                    ganancia3=(monto3*3.6f)/100;
                    System.out.println("Con Cuenta a plazo fijo, estaría ganando en tres meses "+abs(ganancia3)+" pesos.");
                }
                else if(opcion3==2){
                    float monto3,ganancia3;
                    System.out.print("Ingrese el monto del deposito: ");
                    monto3 = sc.nextFloat();
                    ganancia3=(monto3*7.2f)/100;
                    System.out.println("Con Cuenta a plazo fijo, estaría ganando en tres meses "+abs(ganancia3)+" pesos.");             
                }
        }     
    }           
}