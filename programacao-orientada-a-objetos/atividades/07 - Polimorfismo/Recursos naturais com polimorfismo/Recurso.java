public abstract class Recurso{
    protected String nome;
    protected double peso;
    
    public Recurso(String nome, double peso){
        this.nome = nome;
        this.peso = peso;
    }
    
    public String inspecionar(){
        return "Inspecionando "+this.nome+", Peso: "+this.peso+" kg.";
    }
    
    public abstract double processarRecurso(double precoMercado);
}