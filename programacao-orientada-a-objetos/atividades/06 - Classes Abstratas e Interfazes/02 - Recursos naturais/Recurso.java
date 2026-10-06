public abstract class Recurso{
    String nome;
    double peso;
    
    Recurso(String nome, double peso){
        this.nome = nome;
        this.peso = peso;
    }
    
    public void inspecionar(){
        System.out.println("Inspecionando "+this.nome +", Peso: "+ this.peso +" kg.");
    }
    
}