public class EntregaExpressa extends Entrega{
    int prazo;
    double taxa;
    
    public EntregaExpressa(String codigo, String destino, double peso, int prazo, double taxa){
        super(codigo, destino, peso);
        this.prazo = prazo;
        this.taxa = taxa;
    }
    
    public String calcularFrete(){
        return "Entrega expressa "+this.codigo+" possui frete com taxa adicional.";
    }   
    
    public String imprimirValores(){
        return "Entrega: "+ this.codigo +", Destino: "+ this.destino+", Peso: "+ this.peso +", Prazo: "+ this.prazo + ", Taxa: "+this.taxa;
    }
}