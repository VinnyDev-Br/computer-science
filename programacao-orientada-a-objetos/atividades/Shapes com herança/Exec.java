public class Exec {
    public static void main(String args[]) {
        // Assume que o Pi é 3.14159, conforme o enunciado
        
        System.out.println("--- INICIAL ---");
        
        // Criação das instâncias
        Circulo c = new Circulo(5.0);        // Area: 78.53975; Perim: 31.4159
        Quadrado q = new Quadrado(10.0);     // Area: 100.0;    Perim: 40.0
        Retangulo r = new Retangulo(4.0, 6.0); // Area: 24.0;   Perim: 20.0        Retangulo r = new Retangulo();
        // O toString() é chamado e usa os valores calculados no construtor.
        System.out.println(c);
        System.out.println(q);
        System.out.println(r);
    }
}