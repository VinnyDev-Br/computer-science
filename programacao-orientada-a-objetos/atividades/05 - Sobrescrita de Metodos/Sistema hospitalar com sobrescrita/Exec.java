public class Exec {
    public static void main(String args[]) {
        // Criação de instâncias concretas
        Pessoa p1 = new Pessoa("Jose", "Rua A", 25, "123", 'M');
        
        Paciente pac1 = new Paciente("Maria", "Rua B", 40, "456", 'F', "Gripe", "Paracetamol");
        
        Medico med1 = new Medico("Dr. Silva", "Av C", 55, "789", 'M', "12345", 15000.00, "Cardiologia");

        Hospital h1 = new Hospital("Hospital Central");

        System.out.println("--- DADOS ---");
        System.out.println(p1.imprimirValores());
        System.out.println(pac1.sentirDor());
        System.out.println(med1.darPlantao());

        System.out.println("\n--- ATENDIMENTO POLIMORFICO ---");
        System.out.println(h1.atenderPaciente(pac1));
    }
}