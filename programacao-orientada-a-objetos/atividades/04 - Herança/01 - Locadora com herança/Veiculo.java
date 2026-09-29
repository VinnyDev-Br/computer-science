public class Veiculo{
    String placa;
    boolean disponivel;
    String nomeLocatario;
    int idadeLocatario;
    
    public Veiculo(String placa){
        this.placa = placa;
        this.disponivel = true;
    }
    

 
    
    public boolean alugar(String nome, int idade){
        if (idade < 18) { return false; }
        if (!disponivel) { return false; }
        
        disponivel = false;
        
        nomeLocatario = nome;
        idadeLocatario = idade;
        
        return true;
    }
    
    public boolean devolver(){
        if (disponivel) { return false; }

        nomeLocatario = null;
        idadeLocatario = 0;        
        disponivel = true;
        
        return true;
    }
    
    public String toString() {
        String disponibilidade = disponivel ? "sim" : "nao";
        String locatario = disponivel ? "(empty)" : nomeLocatario + ":" + idadeLocatario;

        return "Veiculo: Placa: " + placa
                + ", Disponivel: " + disponibilidade
                + ", Locatario: " + locatario;
    }
}