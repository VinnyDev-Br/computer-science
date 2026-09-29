public class Carro extends Veiculo{
    int capacidadePortaMalas;

    public Carro(String placa) {
        super(placa);
    }
    
    @Override
    public String toString() {
            String disponibilidade = disponivel ? "sim" : "nao";
            String locatario = disponivel ? "(empty)" : nomeLocatario + ":" + idadeLocatario;
    
            return "Carro: Placa: " + placa
                    + ", Disponivel: " + disponibilidade
                    + ", Locatario: " + locatario;
        }
}