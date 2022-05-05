
package com.mycompany.actividad2;
import java.util.Scanner;

public class Actividad2 {

    public static void main(String[] args) {
        int Ingreso;
        int Opcion;
        int Opcion2;
        Scanner Input = new Scanner(System.in);
        System.out.println("Bienvenido al banco XYZ");
        System.out.println("\nIngrese su monto para calcular: ");
        Ingreso = Input.nextInt(); // Se pide el monto de la persona para calcular
        System.out.flush();  
        System.out.println("\nElija un tipo de cuenta");
        System.out.println("1.- Cuenta Ahorro");
        System.out.println("2.- Cuenta Corriente");
        System.out.println("3.- Cuenta a Plazo Fijo");
        System.out.println("\nSu opcion: ");
        Opcion = Input.nextInt(); // Se pide el input del Switch
        
        switch (Opcion){
            case 1 -> { // Caso Ahorro
                System.out.println("En un ano ganara: $" + Math.round(Ingreso*1.01-Ingreso));
            }
            case 2 -> { // Caso Corriente
                System.out.println("En un ano ganara: $" + Math.round(Ingreso*1.005-Ingreso));
            }
            case 3 -> { // Caso plazo Fijo (3 o 6 meses)
                int i;
                System.out.println("Seleccione un plazo");
                System.out.println("1.- 3 Meses");
                System.out.println("2.- 6 Meses");
                System.out.println("Su opcion: ");
                Opcion2 = Input.nextInt();
                Double Total = Double.valueOf(Ingreso);
                switch (Opcion2) {
                    case 1 -> { // 3 Meses
                        for (i=0;i<3;i++){
                            Total = Total * 1.012;
                        }
                        System.out.println("En 3 meses ganara: $" + Math.round(Total - Ingreso));
                    }
                    case 2 -> { // 6 Meses
                        for (i=0;i<6;i++){
                            Total = Total * 1.012;
                        }
                        System.out.println("En 6 meses ganara: $" + Math.round(Total - Ingreso));
                    }
                    default -> {
                        System.out.println("Opcion no valida, saliendo del programa...");
                    }
                }
            }
            default -> {
                System.out.println("Opcion no valida, saliendo del programa...");
            }
        }
    }
}