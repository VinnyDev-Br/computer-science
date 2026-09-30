public class Exec {
    public static void main(String[] args) {

        Entrega e1 = new Entrega("E01", "", 0.0);

        EntregaExpressa e2 = new EntregaExpressa(
                "E02", "Quixada", 1.5, 2, 15.0);

        EntregaEconomica e3 = new EntregaEconomica(
                "E03", "Sobral", 3.0, "Transportadora X", 7);

       //chame o calcularFrete para a instância e1
       System.out.println(e1.calcularFrete());
       //chame o calcularFrete para a instância e2
       System.out.println(e2.calcularFrete());
        //chame o calcularFrete para a instância e3
       System.out.println(e3.calcularFrete());

        //chame o imprimirValores para a instância e2
       System.out.println(e2.imprimirValores());
        //chame o imprimirValores para a instância e3
       System.out.println(e3.imprimirValores());

    }
}