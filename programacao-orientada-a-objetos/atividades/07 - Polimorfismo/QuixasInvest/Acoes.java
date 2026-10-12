public class Acoes extends Investimendo implements Tributavel{
    public static final double taxa = 1.15; // 15% Sobre o valor
    String ticker;
    double precoAtual;

    public Acoes (String nome, String dataCompra, double valorIvestido, String ticker,double precoAtual){
        super(nome, dataCompra, valorIvestido);
        this.ticker = ticker;
        this.precoAtual = precoAtual;
    }

    @Override
    public boolean calcularRetorno(int dias){
        return (this.precoAtual - this.valorIvestido) * (dias/365);
    }

    @Override
    public double calcularImposto(double retorno);        {
        retorno * taxa;
    }
}