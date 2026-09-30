public class Moto extends Veiculo{
    int cilindradas;
    boolean partidaEletrica;
    
    public Moto(String marca, String modelo, int ano, int cilindradas, boolean partidaEletrica){
        super(marca, modelo, ano);
        this.cilindradas = cilindradas;
        this.partidaEletrica = partidaEletrica;
    }
    
    public String empinar(){
        return "Moto "+ this.modelo +" está empinando.";
    }
    
    public String mover(){
        return "Moto "+ this.modelo +" está se movendo rapidamente.";
    }
    
    public String imprimirValores(){
        return super.imprimirValores() + ", Cilindradas: " + this.cilindradas + ", Partida Eletrica: " + this.partidaEletrica;
    }
}