public class Madeira extends Recurso implements Combustivel{
    
    String tipo;
    
    public Madeira(String nome, double peso, String tipo){
        super(nome, peso);
        this.tipo = tipo;
    }
    
    public double processarRecurso(double precoMercado){
        return this.peso * precoMercado * 2.5;
    }
    
    public String queimar(){
        return "Madeira "+this.tipo+ " está queimando lentamente. Gerando " + (this.peso * 4) + " de energia.";
    }
}