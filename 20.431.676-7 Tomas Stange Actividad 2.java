import java.util.Scanner;
public class Actividad3 {
    public static void main(String[] args) 
    {
        Scanner entrada = new Scanner(System.in);
        System.out.println("\n ----------Bienvenido al banco XYZ---------- \n");
        System.out.println("¿Que tipo de cuenta desea abrir?");
        System.out.println("Cuenta de ahorro = 1");
        System.out.println("Cuenta corriente = 2");
        System.out.println("Cuenta a plazo fijo = 3 \n");
        int tipo;
        tipo = entrada.nextInt();
        double dinero;
        double porcentaje;
        int salida;
        int años;
        int meses;
        int ciclo;
        double calculo2 = 0;
        ciclo = 0;
        switch(tipo)
        {
            case 1:
            System.out.println("Ingrese el dinero a depositar: ");
            dinero = entrada.nextDouble();
            System.out.println("Ingrese la cantidad de años: ");
            años = entrada.nextInt();
            calculo2 = dinero;
            while (ciclo < años){
                porcentaje = (dinero * 0.01);
                calculo2 = porcentaje + calculo2;
                ciclo = ciclo + 1;
            }
            salida = (int) calculo2;
            System.out.println("El dinero al final es: " + salida + " en " + años + " años\n");
            break;
            
            case 2:
            System.out.println("Ingrese el dinero a depositar: ");
            dinero = entrada.nextDouble();
            System.out.println("Ingrese la cantidad de años: ");
            años = entrada.nextInt();
            calculo2 = dinero;
            while (ciclo < años){
                porcentaje = (dinero * 0.005);
                calculo2 = porcentaje + calculo2;
                ciclo = ciclo + 1;
            }
            salida = (int) calculo2;
            System.out.println("El dinero al final es: " + salida + " en " + años + " años\n");
            break;

            case 3:
            System.out.println("Ingrese el dinero a depositar: ");
            dinero = entrada.nextDouble();
            System.out.println("Ingrese la cantidad de meses: ");
            System.out.println("Solo se puede calcular en 3 o 6 meses");
            meses = entrada.nextInt();
            if (meses == 3){
                calculo2 = dinero;
                while (ciclo < meses){
                    porcentaje = (dinero * 0.012);
                    calculo2 = porcentaje + calculo2;
                    ciclo = ciclo + 1;
                }
                salida = (int) calculo2;
                System.out.println("El dinero al final es: " + salida + " en " + meses + " meses\n");
            if (meses == 6){
                calculo2 = dinero;
                while (ciclo < meses){
                    porcentaje = (dinero * 0.012);
                    calculo2 = porcentaje + calculo2;
                    ciclo = ciclo + 1;
                }
                salida = (int) calculo2;
                System.out.println("El dinero al final es: " + salida + " en " + meses + " meses\n");
            }
            break;
            }
        entrada.close();
        }
    }
}
