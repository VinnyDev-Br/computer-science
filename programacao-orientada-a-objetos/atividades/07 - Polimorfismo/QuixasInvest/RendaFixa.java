public class RendaFixa extends Investimendo{
    String taxaCDI;

    public RendaFixa(String nome, String dataCompra, double valorIvestido, String taxaCDI){
        super(nome, dataCompra, valorIvestido);
        this.taxaCDI = taxaCDI;
    }

    @Override
    public boolean calcularRetorno(int dias){
        return this.valorIvestido * (this.taxaCDI/100) * (dias/365);
    }       
}