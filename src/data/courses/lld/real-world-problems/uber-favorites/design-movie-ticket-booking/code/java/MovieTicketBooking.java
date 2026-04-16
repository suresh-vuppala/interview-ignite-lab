// DESIGN: Movie Ticket Booking — LLD (Java) | Key: Seat locking (all-or-nothing)
import java.util.*;
enum SeatType { REGULAR, PREMIUM, VIP }
enum SeatStatus { AVAILABLE, LOCKED, BOOKED }
class Seat {
    int row,col; SeatType type; SeatStatus status=SeatStatus.AVAILABLE; String lockedBy;
    Seat(int r,int c,SeatType t){row=r;col=c;type=t;}
    boolean isAvailable(){return status==SeatStatus.AVAILABLE;}
    synchronized boolean lock(String uid){if(status!=SeatStatus.AVAILABLE)return false;status=SeatStatus.LOCKED;lockedBy=uid;return true;}
    synchronized boolean book(String uid){if(status!=SeatStatus.LOCKED||!uid.equals(lockedBy))return false;status=SeatStatus.BOOKED;return true;}
    void release(){status=SeatStatus.AVAILABLE;lockedBy=null;}
    double getPrice(){return type==SeatType.VIP?25:type==SeatType.PREMIUM?15:10;}
    String pos(){return "R"+row+"C"+col;}
}
class Movie { String title; Movie(String t){title=t;} }
class Show {
    Movie movie; Seat[][] seats;
    Show(Movie m,int rows,int cols){movie=m;seats=new Seat[rows][cols];
        for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) seats[r][c]=new Seat(r,c,r<2?SeatType.VIP:r<4?SeatType.PREMIUM:SeatType.REGULAR);}
    int available(){int c=0;for(Seat[] r:seats)for(Seat s:r)if(s.isAvailable())c++;return c;}
    boolean lockSeats(int[][] pos,String uid){
        List<Seat> locked=new ArrayList<>();
        for(int[] p:pos){if(!seats[p[0]][p[1]].lock(uid)){for(Seat s:locked)s.release();return false;}locked.add(seats[p[0]][p[1]]);}
        return true;
    }
    boolean confirmBooking(int[][] pos,String uid){for(int[] p:pos)if(!seats[p[0]][p[1]].book(uid))return false;return true;}
    double calcPrice(int[][] pos){double t=0;for(int[] p:pos)t+=seats[p[0]][p[1]].getPrice();return t;}
}
public class MovieTicketBooking {
    public static void main(String[] args) {
        System.out.println("=== Movie Ticket — Java ===");
        Show show=new Show(new Movie("Matrix"),8,10);
        System.out.println("Available: "+show.available());
        int[][] s1={{0,0},{0,1}};
        if(show.lockSeats(s1,"U1")){System.out.printf("Locked! $%.2f%n",show.calcPrice(s1));show.confirmBooking(s1,"U1");}
        if(!show.lockSeats(s1,"U2")) System.out.println("U2: seats taken!");
        int[][] s2={{5,0},{5,1}};
        if(show.lockSeats(s2,"U2")){show.confirmBooking(s2,"U2");System.out.printf("U2 booked: $%.2f%n",show.calcPrice(s2));}
        System.out.println("Remaining: "+show.available());
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: All-or-nothing seat lock (rollback on failure), VIP/Premium/Regular pricing
