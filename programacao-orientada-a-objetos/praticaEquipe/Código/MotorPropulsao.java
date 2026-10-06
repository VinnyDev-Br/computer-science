
public class MotorPropulsao{
    private String idMotor;
    private int potenciaAtual;
    private boolean superAquecido;

    public MotorPropulsao(String idMotor){
        this.idMotor = idMotor;
        this.potenciaAtual = 0;
        this.superAquecido = false;
    }

    public void setIdMotor(String id){
        this.idMotor = id;
    }
    public String getIdMotor(){
        return this.idMotor;
    }

    public int getPotenciaAtual(){
        return this.potenciaAtual;
    }

    public void setPotenciaAtual(int value){
        new_pot = this.potenciaAtual + value;

        if (new_pot > 0 && new_pot < 100){
            this.potenciaAtual = new_pot;
        }
        else if (new_pot < 0){
            this.potenciaAtual = 0;
        }
        else if (new_pot > 100){
            this.potenciaAtual = 100;
        }
    }

    public boolean isSuperAquecido(){
        return this.superAquecido;
    }
    public String toString(){
        return "Motor: " +idMotor +" - Potência: " +potenciaAtual+ "% - Alerta: " + superAquecido;
    }

    public boolean equals(MotorPropulsao a){
        return this.idMotor.equals(a.getIdMotor());
    }
    public void acelerar(TanqueCombustivel t){
        if(isSuperAquecido()){
            System.out.println("Erro: Motor superaquecido. Aceleração bloqueada!");
        } else {
            if (t.getVolumeAtual() >= TanqueCombustivel.CONSUMO_PADRAO) {
                t.consumir();
                setPotenciaAtual(20);
            }
        }
    }

    public void acelerar(TanqueCombustivel t, int incremento) {
        if(isSuperAquecido()){
            System.out.println("Erro: Motor superaquecido. Aceleração bloqueada!");
        } else {
            if (t.getVolumeAtual() >= incremento * 0.75 ) {
                t.consumir(incremento * 0.75 );
                t.setPotenciaAtual(incremento);
                
            }
        }
    }

    public void avaliarSuperaquecimento(){
        this.superAquecido = true;
        this.potenciaAtual *= 0.5;
    }

    public void acionarResfriamentoEmergencia(){
        this.potenciaAtual = 0;
        this.superAquecido = false;
        System.out.println("Resfriamento Concluído. Motor Pronto.");
    }
}
