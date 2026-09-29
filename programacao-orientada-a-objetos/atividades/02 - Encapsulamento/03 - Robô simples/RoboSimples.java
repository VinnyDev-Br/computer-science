public class RoboSimples{
    private String nome;
    private int x;
    private int y;
    private char direcao;
    
    public RoboSimples(String nome, int x, int y, char direcao){
        this.nome = nome;
        this.x = x;
        this.y = y;
        this.direcao = direcao;
    }
    
    public RoboSimples(String nome){
        this.nome = nome;
        this.direcao = 'N';
        this.x = 0;
        this.y = 0;
    }
    
    public RoboSimples(){
        this.direcao = 'N';
        this.x = 0;
        this.y = 0;
    }
    
    void mover(){
        switch (direcao){
            case 'N':
                this.y++;
                break;
            case 'S': 
                this.y--;
                break;
            case 'L':
                this.x++;
                break;
            case 'O':
                this.x--;
                break;
        }
    }
    
    void mover(int passos){
        switch (direcao){
            case 'N':
                this.y += passos;
                break;
            case 'S': 
                this.y -= passos;
                break;
            case 'L':
                this.x += passos;
                break;
            case 'O':
                this.x -= passos;
                break;
        }    
}

    public void mudarDirecao(char novaDirecao){
        this.direcao = novaDirecao;
    }
   
    public String toString(){
        String saida = "nome: "+(this.nome == null ? "" : nome)+"\n" +
	                    "x: " + x + "\n" +
		                "y: " + y + "\n" +
 		                "direcao: " + direcao + "\n";
        return(saida);
    }

}