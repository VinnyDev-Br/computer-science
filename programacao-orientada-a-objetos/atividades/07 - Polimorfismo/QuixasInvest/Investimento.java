public abstract class Investimento {
    protected String nome;
    protected String dataCompra;
    protected double valorInvestido;

    public Investimento(String nome, String dataCompra, double valorInvestido) {
        this.nome = nome;
        this.dataCompra = dataCompra;
        this.valorInvestido = valorInvestido;
    }

    public abstract double calcularRetorno(int dias);
}