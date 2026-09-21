public Class CanhaoLaser{
    private String idCanhao;
    private double cargaArma;
    private boolean prontoParaDisparo;

    public CanhaoLaser(String idCanhao){
        this.idCanhao = idCanhao;
        this.cargaArma = 0;
        this.prontoParaDisparo = false;
    }

    public String getIdCanhao(){
        return this.idCanhao;
    }

    public double getCargaArma(){
        return this.cargaArma;
    } 

    public void setCargaArma(double value){
        this.cargaArma = value;
    }

    public boolean isProntoParaDisparo(){
        return this.prontoParaDisparo;
    }

    public void setProntoParaDisparo(boolean status){
        this.prontoParaDisparo = status;
    }

    public String toString(){
        return this.idCanhao +", "+ this.cargaArma + ", "+ this.prontoParaDisparo;
    }

    public boolean equal(CanhaoLaser c){
        return (this.idCanhao.equals(c.idCanhao)) ? true : false;
    }

    public void carregarArma(TanqueCombustivel t){
        if (t.verificarVazamento()){
            System.out.println("Combustível instável, carregamento abortado!");
            return;
        }

        t.consumir(10.0);

        this.cargaArma += 20;

        if (this.cargaArma > 50){
            this.prontoParaDisparo = true;
        }
    }

    public void atirar(MotorPropulsao m){
        if (m.isSuperaquecido()){
            System.out.println("Combustível instável, disparo abortado!");
            return;
        }

        if (this.prontoParaDisparo){
            System.out.prinln("PEW! Asteroide destruído");
            this.cargaArma -= 50;

            if (this.cargaArma < 50){
                    desarmar();
            }
        }
    }

    public void atirar(MotorPropulsao m, int qtd){

        if (m.isSuperaquecido()){
            System.out.println("Combustível instável, disparo abortado!");
            return;
        }  

        for (int i = 0; i < qtd; i++){

            if (this.prontoParaDisparo){
                System.out.prinln("PEW! Asteroide destruído");
                this.cargaArma -= 50;
                if (this.cargaArma < 50){
                    desarmar();
                    break;
                }
            }
        }  
    }

    public void desarmar(){
        this.cargaArma = 0;
        this.isProntoParaDisparo = false;
    }
}



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
        if(potenciaAtual > 0 && potenciaAtual < 100){
            this.potenciaAtual = value;
        }
    }
    public boolean isSuperAquecido(){
        if(superAquecido == true){
            return true;
        }else{
            return false;
        }
        public String toString(){
            return "Motor: " +idMotor +" - Potência: " +potenciaAtual+ "% - Alerta: " +superaquecido;
        }

        public equals(MotorPropulsao a){
            if(this.idMotor.equals(a.getIdMotor())){
                return true;
            }
        }
        public void acelerar(TanqueCombustivel t){
            if(isSuperAquecido()){
                System.out.println"Erro: Motor superaquecido. Aceleração bloqueada!";
                return;
            }
            
        }
        

    }
}


