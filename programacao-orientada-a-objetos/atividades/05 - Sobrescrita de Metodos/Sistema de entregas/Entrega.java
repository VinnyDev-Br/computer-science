public class Entrega{
    String codigo;
    String destino;
    double peso;
    
    public Entrega(String codigo, String destino, double peso){
        this.codigo = codigo; 
        this.destino = destino;
        this.peso = peso;
    }
    
    public String calcularFrete(){
        return "Entrega "+this.codigo+" possui frete padrão.";
    }
    
    public String imprimirValores(){
        return "Entrega: "+ this.codigo +", Destino: "+ this.destino+", Peso: "+ this.peso;
    }
}