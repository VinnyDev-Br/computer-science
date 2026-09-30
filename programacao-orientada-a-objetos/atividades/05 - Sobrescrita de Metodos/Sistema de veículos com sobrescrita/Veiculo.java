public class Veiculo{
    String marca;
    String modelo;
    int ano;
    
    public Veiculo(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }
    
    public String mover(){
        return "Veiculo " + this.modelo + " está se movendo.";
    }
    
    public String imprimirValores(){
        return "Veiculo: " + this.marca + ", "+ this.modelo +", Ano: " + this.ano;
    }
}