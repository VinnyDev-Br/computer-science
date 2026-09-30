public class Exec {
    public static void main(String[] args) {

        Veiculo v1 = new Veiculo("Ford", "F400", 2020);
        Carro c1 = new Carro("Toyota", "Corolla", 2024, 4, "Flex");
        Moto m1 = new Moto("Honda", "CB500", 2023, 500, true);

        //chame o método mover para v1
        System.out.println(v1.mover());
        //chame o método mover para c1
        System.out.println(c1.mover());
        //chame o método mover para m1
        System.out.println(m1.mover());
        // Chame o método imprimirValores de c1
        System.out.println(c1.imprimirValores());
        // Chame o método imprimirValores de m1
        System.out.println(m1.imprimirValores());

    }
}