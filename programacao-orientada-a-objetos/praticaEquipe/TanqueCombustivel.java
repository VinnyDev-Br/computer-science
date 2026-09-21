public class TanqueCombustivel {
    private String tipoCombustivel;
    private double volumeAtual;
    private boolean vazamentoDetectado;
    static double CONSUMO_PADRAO = 15.0;

    TanqueCombustivel(String tipoCombustivel) {
        this.tipoCombustivel = tipoCombustivel;
        volumeAtual = 1000.0;
        vazamentoDetectado = false;
    }

    public String toString() {
        String vazamentoString = "não";
        if (vazamentoDetectado) {
            vazamentoString = "sim";
        }
        return "Tipo : " + tipoCombustivel + "\nVolume : " + volumeAtual + "\nHá vazamento : " + vazamentoString;
    }

    public String getTipoCombustivel() {
        return tipoCombustivel;
    }

    public double getVolumeAtual() {
        return volumeAtual;
    }

    public void setVolumeAtual(double volume) {
        volumeAtual = volume;
    }

    public boolean isVazamentoDetectado() {
        return vazamentoDetectado;
    }

    public void setVazamentoDetectado(boolean status) {
        vazamentoDetectado = status;
    }

    public boolean equals(TanqueCombustivel obj) {
        return (tipoCombustivel.equals(obj.getTipoCombustivel()));
    }

    public void injetarCombustivel(double qnt) {
        if (vazamentoDetectado) {
            volumeAtual += (qnt * 0.5);
        } else {
            volumeAtual += qnt;
        }
    }

    public void consumir(double qtd) {
        if (qtd > volumeAtual) {
            volumeAtual = 0;
            vazamentoDetectado = true;
        } else {
            volumeAtual -= qtd;
        }
    }

    public void consumir() {
        consumir(CONSUMO_PADRAO);
    }

    public boolean verificarVazamento() {
        return isVazamentoDetectado();
    }
}
