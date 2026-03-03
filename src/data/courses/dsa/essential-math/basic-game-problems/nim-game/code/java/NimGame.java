public class NimGame {
    boolean nimGame(int[] piles) { int xor=0; for(int p:piles) xor^=p; return xor!=0; }
    boolean canWinStones(int n) { return n%3!=0; }
    public static void main(String[] a) { NimGame g=new NimGame(); System.out.println("Nim [3,4,5]: "+g.nimGame(new int[]{3,4,5})); System.out.println("Can win with 4 stones: "+g.canWinStones(4)); }
}