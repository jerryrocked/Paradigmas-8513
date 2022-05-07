package actividad3;



import javax.swing.*;
import java.awt.*;  
import java.awt.event.*;
     
public class ventana extends JFrame {
    JPanel panel;
    public JRadioButton Cuent_ahorro,Cuent_corriente,Cuent_3_meses,Cuent_6_meses;
    public JLabel Bienvenida,text1,text2,text3;
    private JTextField cajatexto;
    private float porcentaje;
    private int inversion,ganancia;
    
    ventana(){
        setSize(800,500); // tamaño de la ventana
        setLocationRelativeTo(null);
        this.getContentPane().setBackground(Color.GRAY);
        ini_component();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    private void ini_component(){
        panel = new JPanel();
        panel.setLayout(null);
        botones();
        textos();
        monto();
        this.getContentPane().add(panel);
        
    }   
  
    private void botones(){
        // creacion de botones
        Cuent_ahorro = new JRadioButton("Cuenta de ahorro",false);
        Cuent_corriente = new JRadioButton("Cuenta corriente",false);
        Cuent_3_meses = new JRadioButton("Cuenta a plazo 3 meses",false);
        Cuent_6_meses = new JRadioButton("Cuenta a plazo 6 meses",false);
        
        // caracteristicas boton Cuent_ahorro
        Cuent_ahorro.setFont(new Font("Tahoma", 1, 15));
        Cuent_ahorro.setBounds(235,80,275,30);
        Cuent_ahorro.setForeground(Color.BLACK);
        
        // caracteristicas boton Cuent_corriente
        Cuent_corriente.setFont(new Font("Tahoma", 1, 15));
        Cuent_corriente.setBounds(235,130,275, 30);
        Cuent_corriente.setForeground(Color.RED);
        
        // caracteristicas boton Cuent_3_meses
        Cuent_3_meses.setFont(new Font("Tahoma", 1, 15));
        Cuent_3_meses.setBounds(235,180,275, 30);
        Cuent_3_meses.setForeground( Color.GREEN);
        
        // caracteristicas boton Cuent_6_meses
        Cuent_6_meses.setFont(new Font("Tahoma", 1, 15));
        Cuent_6_meses.setBounds(235,230,275, 30);
        Cuent_6_meses.setForeground(Color.BLUE);
        
        // hacemos los botones de seleccion unica;
        ButtonGroup gruporadioboton = new ButtonGroup();
        gruporadioboton.add(Cuent_ahorro);
        gruporadioboton.add(Cuent_corriente);
        gruporadioboton.add(Cuent_3_meses);
        gruporadioboton.add(Cuent_6_meses);
            
        // creamos los eventos de los botones
        // evento boton cuenta ahorro
        ActionListener CA=(ActionEvent e) -> {
            // indicamos que debe hacer el evento
            try{
                porcentaje = 0.01f;
                inversion = Integer.parseInt(cajatexto.getText());
                ganancia = (int) (inversion * porcentaje);
                text3.setText("La ganancia anual será de: "+ganancia);
            }
            catch(NumberFormatException ex){
                text3.setText("Error al ingresar datos");
            }
        } // creacion del evento en si
        ;
        Cuent_ahorro.addActionListener(CA); // agregamos este evento al boton, si este se activa, se activa el evento
        
        // evento boton cuenta corriente
        ActionListener CC=(ActionEvent e) -> {
            // indicamos que debe hacer el evento
            try{
                porcentaje = 0.005f;
                inversion = Integer.parseInt(cajatexto.getText());
                ganancia = (int) (inversion * porcentaje);
                text3.setText("La ganancia anual será de: "+ganancia);
            }
            catch(NumberFormatException ex){
                text3.setText("Error al ingresar datos");
            }
        } // creacion del evento en si
        ;
        Cuent_corriente.addActionListener(CC); // agregamos este evento al boton, si este se activa, se activa el evento
        
        // evento boton cuenta a plazo 3 meses
        ActionListener CAP3=(ActionEvent e) -> {
            // indicamos que debe hacer el evento
            try{
                porcentaje = 0.012f;
                inversion = Integer.parseInt(cajatexto.getText());
                ganancia = (int) (inversion * porcentaje) * 3;
                text3.setText("La ganancia en 3 meses será de: "+ganancia);
            }
            catch(NumberFormatException ex){
                text3.setText("Error al ingresar datos");
            }
        } // creacion del evento en si
        ;
        Cuent_3_meses.addActionListener(CAP3); // agregamos este evento al boton, si este se activa, se activa el evento
        
        // evento boton cuenta a plazo 6 meses
        ActionListener CAP6=(ActionEvent e) -> {
            // indicamos que debe hacer el evento
            try{
                porcentaje = 0.012f;
                inversion = Integer.parseInt(cajatexto.getText());
                ganancia = (int) (inversion * porcentaje) * 6;
                text3.setText("La ganancia en 6 meses será de: "+ganancia);
            }
            catch(NumberFormatException ex){
                text3.setText("Error al ingresar datos");
            }
        } // creacion del evento en si
        ;
        Cuent_6_meses.addActionListener(CAP6); // agregamos este evento al boton, si este se activa, se activa el evento
        
        // agregamos los botones al panel
        panel.add(Cuent_ahorro);
        panel.add(Cuent_corriente);
        panel.add(Cuent_3_meses);
        panel.add(Cuent_6_meses);
        
        
    }
    
    private void textos(){
        // creacion de los textos
        Bienvenida = new JLabel("Bienvenido al Banco XYZ");
        text1 = new JLabel("Escoja una opcion para abrir una cuenta:");
        text2 = new JLabel("Cantidad de dinero a invertir:");
        text3 = new JLabel();
        
        // caracteristicas del texto Bienvenida
        Bienvenida.setFont(new Font("Tahoma", 1, 20));
        Bienvenida.setBounds(240,10,275,30);
        Bienvenida.setForeground(Color.BLACK);
        
        // caracteristicas del texto text1
        text1.setFont(new Font("arial", 1, 18));
        text1.setBounds(200,45,500,30);
        text1.setForeground(Color.BLACK);
        
        // caracteristicas del texto text2
        text2.setFont(new Font("arial", 1, 13));
        text2.setBounds(35,275,500,30);
        text2.setForeground(Color.BLACK);
        
        // caracteristicas del texto text3
        text3.setFont(new Font("Tahoma", 1, 18));
        text3.setBounds(220,370,500,30);
        text3.setForeground(Color.BLACK);
        
        panel.add(Bienvenida);
        panel.add(text1);
        panel.add(text2);
        panel.add(text3);
    }
    
    private void monto(){
        // creamos la caja del texto
        cajatexto = new JTextField();
        cajatexto.setBounds(235,275,275,30);
        panel.add(cajatexto);
    }
    public static void main(String[] args) {
        JFrame nuevo = new JFrame("BANCO XYZ");
        ventana v1 = new ventana();
        v1.setVisible(true);
        
    }
}

//    class FondoPanel extends JPanel
//    {
//        private Image imagen;
//        
//        @Override
//        public void paint (Graphics g)
//        {
//            imagen = new ImageIcon(getClass().getResource("/imagenes/imagen.jpg")).getImage();
//            
//            g.drawImage(imagen, 0, 0, getWidth(), getHeight(),this);
//            
//            setOpaque(false);
//            super.paint(g);
//        }
//    }
//}