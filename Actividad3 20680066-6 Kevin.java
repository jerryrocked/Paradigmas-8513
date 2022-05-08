/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.actividad3;
import java.util.Scanner;
/**
 *
 * @author test
 */
public class Actividad3 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Que cuenta desea abrir(a)(b)(c)");
        String s = in.nextLine();
        System.out.println("ingresaste " + s);
        switch (s) {
            case "a":
                System.out.println("Cuenta ahorro.");
                break;
            case "b":
                System.out.println("Corriente");
                break;
            case "c":
                System.out.println("A plazo fijo");
                break;
        
        }
        System.out.println("Cuanto dinero tiene ");
        int num = in.nextInt();
        System.out.println("3 o 6 meses? ");
        int meses = in.nextInt();
        double percentil = num / 100;
        double subentil;
        double suma ;
        double total;
        switch (s) {
            case "a":
                System.out.println("Cuenta ahorro.");
                subentil = meses * (1/12);
                break;
            case "b":
                System.out.println("Corriente");
                subentil = meses * (0.5/12);
                break;
            case "c":
                System.out.println("A plazo fijo");
                subentil = meses * 1.2;
                
                break;
            default:
                System.out.println("Opcion invalida.");
                subentil = 0;
                break;
        }
        suma = subentil * num;
        System.out.println("Obtendras " + suma + "en" + meses + "meses");
        
    }
}
