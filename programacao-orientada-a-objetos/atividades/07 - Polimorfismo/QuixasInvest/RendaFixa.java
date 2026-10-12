public class RendaFixa extends Investimento {
    private double taxaCDI;

    public RendaFixa(String nome, String dataCompra, double valorInvestido, double taxaCDI) {
        super(nome, dataCompra, valorInvestido);
        this.taxaCDI = taxaCDI;
    }

    @Override
    public double calcularRetorno(int dias) {
        return this.valorInvestido * (this.taxaCDI / 100) * (dias / 365.0);
    }
}