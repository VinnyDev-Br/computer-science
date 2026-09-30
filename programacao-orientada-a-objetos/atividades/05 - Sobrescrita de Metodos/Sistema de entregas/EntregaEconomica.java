public class EntregaEconomica extends Entrega{
    String t;
    int dias;
    
    public EntregaEconomica(String codigo, String destino, double peso, String t, int dias){
        super(codigo, destino, peso);
        this.t = t;
        this.dias = dias;   
    }
    
    public String calcularFrete(){
        return "Entrega economica "+this.codigo+" possui frete reduzido.";
    }  
    
    public String imprimirValores(){
        return "Entrega: "+ this.codigo +", Destino: "+ this.destino+", Peso: "+ this.peso +", Transportadora: "+ this.t + ", Dias: "+this.dias;
    }
}