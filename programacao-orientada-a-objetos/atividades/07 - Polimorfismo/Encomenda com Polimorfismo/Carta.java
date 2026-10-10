public class Carta extends Encomenda implements Rastreavel{
    boolean urgente;
    
    public Carta(String codigo, double peso, boolean urgente){
        super(codigo, peso);
        this.urgente = urgente;
    }
    
    public double calcularCustoEnvio(){
        if (this.urgente){
            return (this.peso * 5.0) * 1.2;
        }
        
        return this.peso * 5.0;
    }
    
    public String getStatus(){
        if (this.urgente){
            return "Em trânsito urgente";
        }
        return "Aguardando classificação";    
    }
    
    @Override
    public String toString(){
        return "[Código]: "+this.codigo+", Peso: " + this.peso;
    }
}