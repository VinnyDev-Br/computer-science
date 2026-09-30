public class Carro extends Veiculo{
    int portas;
    String combustivel;
    
    public Carro(String marca, String modelo, int ano, int portas, String combustivel){
        super(marca, modelo, ano);
        this.portas = portas;
        this.combustivel = combustivel;
    }
    
    public String buzinar(){
        return "Carro "+ this.modelo +" está se movendo pelas ruas.";
    }

    public String mover(){
        return "Carro " + this.modelo + " está se movendo pelas ruas.";
    }
    
    public String imprimirValores(){
        return super.imprimirValores() + ", Portas: " + this.portas + ", Combustivel: " + this.combustivel;
    }
    
}