public class Hospital{
    String nomeHospital;
    
    public Hospital(String nomeHospital){
        this.nomeHospital = nomeHospital;
    }
    
    public String atenderPaciente(Paciente p){
        return p.imprimirValores();
    }
}