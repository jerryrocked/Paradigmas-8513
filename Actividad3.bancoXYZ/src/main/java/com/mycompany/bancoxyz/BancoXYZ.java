package com.mycompany.bancoxyz;
import java.util.Scanner;

/**
 *Este programa es sobre el banco XYZ, el cual ofrece productos a clientes nuevos para apertura de una cuenta.
 * Las cuentas son:
 * 
 * - CUENTA AHORRO - 1% ANUAL
 * - CUENTA CORRIENTE - 0.5% ANUAL
 * - CUENTA A PLAZO FIJO - 1.2% MENSUAL (SOLO 3 MESES Y 6 MESES, EL CLIENTE DEBE SELECCIONAR)
 * 
 * Debe calcular cuanto ganará un cliente, dependiendo de la cuenta que seleccione
 */

public class BancoXYZ {

    public static void main(String[] args) {
        
        // variables del programa
        int opcion;                 // opcion del cliente
     
        System.out.println("Bienvenido al sistema XYZ!");
        System.out.println("Tenemos para ofrecer los mejores productos! Tu escoges el tipo de cuenta: ");
        System.out.println("\n1) CUENTA AHORRO -> 1% ANUAL \n2) CUENTA CORRIENTE -> 0.5% ANUAL \n3) CUENTA A PLAZO FIJO -> 1.2% MENSUAL \n4) SALIR");
       
        // se crea el objeto de la clase Scanner para leer por teclado
        Scanner sc = new Scanner(System.in);
        System.out.println("\nSeleccione un número de las opciones: ");
        opcion = sc.nextInt();
        
        switch(opcion){
            
            // CUENTA DE AHORRO
            case 1: System.out.println("\nHa seleccionado 1) CUENTA AHORRO");
                    System.out.println("\nEntonces, su cuenta generará 1% anual a partir del monto ingresado");
                    double monto = devuelveMonto();
                    System.out.println("\n--> El monto ingresado es de: $" + monto + " mensual");
                    double cta_ahorro = cuentaAhorro(monto);
                    System.out.println("\n\nEntonces, la ganancia anual en esta cuenta es de: $" + cta_ahorro + " anuales");
                    break;
            
            // CUENTA CORRIENTE     
            case 2: System.out.println("\nHa seleccionado 2) CUENTA CORRIENTE");
                    System.out.println("\nEntonces, su cuenta generará 0.5% anual");
                    double monto2 = devuelveMonto();
                    System.out.println("\n--> El monto ingresado es de: $" + monto2 + " mensual");
                    double cta_corriente = cuentaCorriente(monto2);
                    System.out.println("\n\nEntonces, la ganancia anual en esta cuenta es de: $" + cta_corriente + " anuales");
                    break;
            
            // CUENTA A PLAZO FIJO       
            case 3: System.out.println("\nHa seleccionado 3) CUENTA A PLAZO FIJO");
                    System.out.println("\nEntonces, su cuenta generará 1.2% mensual");
                    double monto3 = devuelveMonto();
                    System.out.println("\n--> El monto ingresado es de: $" + monto3 + " mensual");
                    double cta_plazo_fijo = cuentaPlazoFijo(monto3);
                    break;
            
            // SALIR DEL SISTEMA       
            case 4: System.out.println("\nHa seleccionado 4) SALIR");
                    System.out.println("\nMuchas gracias, hasta pronto!");
                    break;
            
            // VALOR INCORRECTO
            default: System.out.println("Ha ingresado un valor incorrecto. \nVuelva a intentarlo");
                    break;
        }
    }
    
    // definicion de las funciones del programa
    
    public static double devuelveMonto(){
        double monto;
        Scanner sc2 = new Scanner(System.in);
        System.out.println("\nPor favor ingrese el monto que desea ingresar: ");
        monto = sc2.nextDouble();
        return monto; 
    }
    
    public static double cuentaAhorro(double monto){
        double montoAnual =monto + (monto*1/100);        // monto anual = (monto mensual)*12
        System.out.println("\nPor lo tanto el monto anual es : $" + montoAnual);
        double unoPrcnt = (montoAnual-monto); // porcentaje de ganancia final
        System.out.println("\nPor lo tanto la ganancia en el 1% del monto anual es : $" + unoPrcnt);
        return unoPrcnt; 
    }
    
    public static double cuentaCorriente(double monto2){
        double montoAnual = monto2 + (monto2*0.5/100);          // monto anual = (monto mensual)*12
        System.out.println("\nPor lo tanto el monto anual es : $" + montoAnual);
        double halfPrcnt = (montoAnual-monto2);  // porcentaje de ganancia final
        System.out.println("\nPor lo tanto la ganancia en el 0.5% del monto anual es : $" + halfPrcnt);
        return halfPrcnt; 
    }
    
    public static double cuentaPlazoFijo(double monto3){
        Scanner sc = new Scanner(System.in);
        int meses;
        System.out.println("\nSeleccione si es para 3 o 6 meses: ");
        meses = sc.nextInt();
        
        switch(meses){
            case 3: System.out.println("\nHa seleccionado 3 meses");
                    double monto_tercer_mes = monto3 + (monto3*1.2/100);
                    monto_tercer_mes = monto_tercer_mes + (monto_tercer_mes*1.2/100);
                    monto_tercer_mes = monto_tercer_mes + (monto_tercer_mes*1.2/100);
                    System.out.println("\nEl monto al tercer mes de ingresar dinero es: $" + monto_tercer_mes);
                    double ganancia3 = monto_tercer_mes - monto3;
                    System.out.println("\nLa ganancia por 3 meses de Cuenta a Plazo Fijo es de: $" + ganancia3);
                    break;
            case 6: System.out.println("\nHa seleccionado 6 meses");
                    double monto_sexto_mes = monto3 + (monto3*1.2/100);
                    monto_sexto_mes = monto_sexto_mes + (monto_sexto_mes*1.2/100);
                    monto_sexto_mes = monto_sexto_mes + (monto_sexto_mes*1.2/100);
                    monto_sexto_mes = monto_sexto_mes + (monto_sexto_mes*1.2/100);
                    monto_sexto_mes = monto_sexto_mes + (monto_sexto_mes*1.2/100);
                    monto_sexto_mes = monto_sexto_mes + (monto_sexto_mes*1.2/100);
                    System.out.println("\nEl monto al sexto mes de ingresar dinero es: $" + monto_sexto_mes);
                    double ganancia6 = monto_sexto_mes - monto3;
                    System.out.println("\nLa ganancia por 3 meses de Cuenta a Plazo Fijo es de: $" + ganancia6);
                    break;
        }
        
        return meses;
    }
}
