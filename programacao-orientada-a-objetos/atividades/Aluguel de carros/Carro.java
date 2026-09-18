public class Carro{
    String placa;
    boolean disponivel;
    Pessoa locatario;
    
    public Carro(){
        
    }
    
    public Carro(String placa){
        this.placa = placa;
        disponivel = true;
        Pessoa locatario = null;
    }
    
    public boolean alugar(Pessoa pessoa){
        if (disponivel == false || pessoa.idade < 18){
            return false;
        }
        
        disponivel = false;
        locatario = pessoa;
        Locadora.registrarAluguel();
        return true;
        
    }
    
    public boolean devolver(){
        if (disponivel == false){
            disponivel = true;
            locatario = null;
            Locadora.registrarDevolucao();
            return true;
        }
        
        
        return false;
    }
    
    public String toString(){
        if (disponivel)
            return "Placa: " + this.placa + ", Disponivel: sim, Locatario: (empty)";
            
        return  "Placa: " + this.placa + ", Disponivel: nao, Locatario: " + locatario.toString();   
    }
}