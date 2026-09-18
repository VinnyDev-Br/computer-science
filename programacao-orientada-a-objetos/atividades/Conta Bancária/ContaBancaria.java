public class ContaBancaria{
    Correntista correntista;
    double saldo;
    boolean contaEhEspecial;
    
    public ContaBancaria(){
        
    }
    
    public ContaBancaria(Correntista correntista, double saldo, boolean contaEhEspecial){
        this.correntista = correntista;
        this.saldo = saldo;
        this.contaEhEspecial = false;
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
        return "nome: " + this.correntista.nome + "\n" + "saldo: " + this.saldo + "\n" +
        "ehEspecial: " + ((this.contaEhEspecial) ? "sim":"nao");
    
    }
}