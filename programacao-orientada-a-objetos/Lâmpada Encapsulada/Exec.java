public class Exec {
    public static void main(String[] args) {
        Lampada l1 = new Lampada();
        //Faça uma chamada ao método de mudar o estado da lâmpada aqui.
        l1.mudarEstado();
        //Faça uma chamada ao método de mudar o estado da lâmpada aqui.
        l1.mudarEstado();
        //Faça uma chamada ao método de mudar o estado da lâmpada aqui.
        l1.mudarEstado();
        System.out.println(l1.getEstado()); // Altere o nome do atributo para ficar igual ao de sua classe, caso necessário
        System.out.println(l1.getContador()); // Altere o nome do atributo para ficar igual ao de sua classe, caso necessário
    }
}