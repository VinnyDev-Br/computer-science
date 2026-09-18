public class ContaBancaria{
    private Correntista correntista;
    private double saldo;
    private boolean contaEhEspecial;
    
    public ContaBancaria(){
        
    }
    
    public ContaBancaria(Correntista correntista, double saldo, boolean contaEhEspecial){
        this.correntista = correntista;
        this.saldo = saldo;
        this.contaEhEspecial = contaEhEspecial;
    }
    
    public void depositar(double value){
        this.saldo += value;
    }
    
    public boolean sacar(double value){
        if (this.contaEhEspecial){
            this.saldo -= value;
            return true;
        }
        
        if (this.saldo >= value){
            this.saldo -= value;
            return true;
        }
        
        return false;
    }
    
    public String toString(){
        return "nome: " + this.correntista.getNome() + "\n" + "saldo: " + this.saldo + "\n" +
        "ehEspecial: " + ((getEhEspecial()) ? "sim":"nao");
    
    }
    
    
    public double getSaldo(){
        return this.saldo;
    }
    
    public boolean getEhEspecial(){
        return this.contaEhEspecial;
    }
    
    public Correntista getCorrentista(){
        return this.correntista;
    }
}