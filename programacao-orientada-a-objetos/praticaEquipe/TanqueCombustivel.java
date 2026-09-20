public Class TanqueCombustivel{
    private String tipoCombustivel;
    private double volumeAtual;
    private boolean vazamentoDetectado;
    public static double  CONSUMO_PADRAO = 15.0;


    public TanqueCombustivel(String tipo){
            this.tipoCombustivel = tipo;
            this.volumeAtual = 1000.0;
            this.vazamentoDetectado = false;
    }

    public String getTipoCombustivel(){

    }
} 