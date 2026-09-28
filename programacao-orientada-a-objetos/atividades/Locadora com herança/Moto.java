public class Moto extends Veiculo{
    
    public Moto(String placa){
        super(placa);
    }
    
    @Override
    public boolean alugar(String nome, int idade){
        if (idade < 18 || idade > 50) { return false; }
        if (!disponivel) { return false; }
        
        disponivel = false;
        idadeLocatario = idade;
        nomeLocatario = nome;
        
        return true;
    }
    
    @Override
    public String toString() {
            String disponibilidade = disponivel ? "sim" : "nao";
            String locatario = disponivel ? "(empty)" : nomeLocatario + ":" + idadeLocatario;
    
            return "Moto: Placa: " + placa
                    + ", Disponivel: " + disponibilidade
                    + ", Locatario: " + locatario;
        }
}