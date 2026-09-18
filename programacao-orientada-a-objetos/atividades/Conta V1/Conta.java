public class Conta {
    int numero;
    String titular;
    float saldo;
    
    public Conta(){
        
    }
    
    public Conta(int numero, String titular){
        this.numero = numero;
        this.titular = titular;
        this.saldo = 0;
    }
    
    public String toString(){
        return this.numero + " " + this.titular + " " + this.saldo; 
    }
    
    void depositar(){
        this.saldo += 100;
    }
    
    void consultar(){
        System.out.println("Saldo: " + this.saldo);
    }
    
    void fecha(){
        System.out.println("Conta " + this.numero + " encerrada");
    }
    
}