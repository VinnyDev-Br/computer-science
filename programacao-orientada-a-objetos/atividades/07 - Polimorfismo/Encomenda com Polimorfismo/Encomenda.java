public abstract class Encomenda implements Rastreavel{
    String codigo;
    double peso;
    
    public Encomenda(String codigo, double peso){
        this.codigo = codigo;
        this.peso = peso;
    }
    
    public abstract double calcularCustoEnvio();
    
    public String toString(){
        return this.codigo +", " + this.peso;
    }
    
}