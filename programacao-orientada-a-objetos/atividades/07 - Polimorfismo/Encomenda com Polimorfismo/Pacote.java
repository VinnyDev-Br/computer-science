public class Pacote extends Encomenda implements Rastreavel{
    double l, c, p;
    
    public Pacote(String codigo, double peso, double l, double c, double p){
        super(codigo, peso);
        this.l = l;
        this.c = c;
        this.p = p;
    }
    
    public double calcularCustoEnvio(){
        if (this.l > 10 || this.c > 10|| this.p > 10){
            return this.peso * 12.0 * 1.18;
        }
        
        return this.peso * 12.0;
    }
    
    public String getStatus(){
        return "Entregue ao destinatário";
    }
    
    @Override
    public String toString(){
        return "[Código]: "+this.codigo+", Peso: " + this.peso;
    }
}