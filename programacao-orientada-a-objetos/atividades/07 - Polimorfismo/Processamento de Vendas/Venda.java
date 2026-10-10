public abstract class Venda{
    double valorBase;
    String data;
    
    public Venda(double valorBase, String data){
        this.valorBase = valorBase;
        this.data = data;
    }
    
    public abstract double calcularValorFinal();
    
    public String toString(){
        return this.data +", "+ this.valorBase;
    }
}