public class VendaInternacional extends Venda implements Transacionavel{
    public static final double taxaConversao = 0.25;
    
    public VendaInternacional(double valorBase, String data){
        super(valorBase, data);
    }
    
    @Override
    public double calcularValorFinal(){
        return this.valorBase * taxaConversao;
    }
    
    @Override
    public String toString(){
        return this.data +", "+ this.valorBase;
    }
}