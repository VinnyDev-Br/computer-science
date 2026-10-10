public class VendaLocal extends Venda implements Transacionavel{
    public static final double impostoMunicipal = 0.05;
    
    public VendaLocal(double valorBase, String data){
        super(valorBase, data);
    }
    
    
    public double calcularValorFinal(){
        return this.valorBase + (this.valorBase * impostoMunicipal);
    }
    
    @Override
    public String toString(){
        return this.data +", "+ this.valorBase;
    }

}