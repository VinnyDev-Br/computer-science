public class Exec {
    public static void main(String args[]) {
        // Assume PI = 3.14159, conforme questões anteriores.
        
        // Criação das instâncias
        Circulo c = new Circulo(5.0, "Vermelho"); // Raio 5.0
        Retangulo r = new Retangulo(4.0, 6.0, "Azul"); // L 4.0, A 6.0
        
        System.out.println("--- DADOS DAS FIGURAS ---");
        // Herança: Chama o método concreto que, por sua vez, chama os abstratos.
        System.out.println(c.apresentarDados());
        System.out.println(r.apresentarDados());

        System.out.println("\n--- TESTE INTERFACE ---");
        // Interface: Chama o método de renderização.
        System.out.println(c.desenhar());
        System.out.println(r.desenhar());
    }
}