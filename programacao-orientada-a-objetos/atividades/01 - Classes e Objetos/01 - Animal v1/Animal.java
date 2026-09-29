public class Animal {
    String especie;
    int idade;
    String barulho;

    
    public Animal() {
    }
    
    public Animal(String especie, String barulho) {
        this.especie = especie;
        this.barulho = barulho;
        this.idade = 0;
    }

    public String toString() {
        return especie + " " + idade + " " + barulho;
    }

    public void envelhecer() {
        this.idade++;
    }

    public void morrer() {
        System.out.println(especie + " morreu");
    }

    public void fazerbarulho() {
        System.out.println(barulho);
    }
}