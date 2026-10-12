public class Investimendo{
    protected String nome;
    protected String dataCompra;
    protected double valorIvestido;

    public Investimento(String nome, String dataCompra, double valorIvestido){
        this.nome = nome;
        this.dataCompra = dataCompra;
        this.valorIvestido = valorIvestido;
    }

    public abstract double calcularRetorno(int dias);

}