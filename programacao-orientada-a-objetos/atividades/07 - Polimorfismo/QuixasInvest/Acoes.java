public class Acoes extends Investimento implements Tributavel{
    public static final double taxa = 0.15; // 15% Sobre o valor
    String ticker;
    double precoAtual;

    public Acoes (String nome, String dataCompra, double valorInvestido, String ticker,double precoAtual){
        super(nome, dataCompra, valorInvestido);
        this.ticker = ticker;
        this.precoAtual = precoAtual;
    }

    @Override
    public boolean calcularRetorno(int dias){
        return (this.precoAtual - this.valorInvestido) * (dias/365);
    }

    @Override
    public double calcularImposto(double retorno){
        return retorno * (1+taxa);
    }
}