package com.mycompany.actividad3;
import java.util.Scanner;
public class act_3 {

    public static void main(String[] args) {
        System.out.println("-------Bienvenido al Banco-------"+"\n");
        System.out.print("Escoja una opción: ");
        System.out.println("1. Cuenta de Ahorro"+"\n"+"2. Cuenta Corriente"+"\n"+"3. Cuenta a Plazo Fijo"+"\n");
        Scanner sc= new Scanner(System.in);
        int op=sc.nextInt();
        switch (op) {
            case 1:{
                System.out.print("\n"+"---Cuenta de Ahorro---"+"\n"+"Ingrese la cantidad que desea depositar:");
                float cantidad=sc.nextFloat();
                System.out.print("Ingrese el año del depósito: ");
                int anio=sc.nextInt();
                float gan= cantidad/100;
                System.out.print("Para el año "+(anio+1)+" la ganancia sera de "+gan+" pesos");
                break;
                }
            case 2:{
                System.out.println("\n"+"---Cuenta Corriente---"+"\n"+"Ingrese la cantidad que desea depositar: ");
                float cantidad=sc.nextFloat();
                System.out.print("Ingrese el año del depósito: ");
                int anio=sc.nextInt();
                float gan= (cantidad*0.5f)/100;
                System.out.print("Para el anio "+(anio+1)+" la ganancia sera de "+gan+" pesos");
                break;
                }
            case 3:
                System.out.print("---Cuenta a Plazo Fijo---"+"\n"+"Por cuánto tiempo desea la cuenta"+"\n"+"1. 3 Meses"+"\n"+"2. 6 Meses");
                int tiempo=sc.nextInt();
            switch (tiempo) {
                case 1:{
                    System.out.print("\n"+"---Cuenta a Plazo Fijo de 3 Meses---"+"\n"+"Ingrese la cantidad que desea depositar: ");
                    float cantidad=sc.nextFloat();
                    float gan=(cantidad*1.2f)/100;
                    float ganC=gan*3;
                    System.out.print("Dentro de un mes la ganancia sera de "+gan+" y de "+ganC+" pesos en 3 meses");
                    break;
                    }
                case 2:{
                    System.out.print("\n"+"---Cuenta a Plazo Fijo de 6 Meses---"+"\n"+"Ingrese la cantidad que desea depositar: ");
                    float cantidad=sc.nextFloat();
                    float gan= (float)((cantidad*1.2)/100);
                    float ganC=gan*6;
                    System.out.println("Dentro de un mes la ganancia sera de "+gan+" y de "+ganC+" pesos en 6 meses");
                    break;
                    }
                default:
                    System.out.println("Opcion incorrecta");
                    break;
            }
break;
            default:
                System.out.println("Opcion incorrecta");
                break;
        }
    }
}