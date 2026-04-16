// DESIGN: Train Platform — LLD (Java) | Strategy + Sweep Algorithm
import java.util.*;
class Train { String id,name; int arrival,departure;
    Train(String id,String name,int arr,int dep){this.id=id;this.name=name;arrival=arr;departure=dep;}
    String getName(){return name;} int getArrival(){return arrival;} int getDeparture(){return departure;}
}
class Platform { int id; Train current;
    Platform(int id){this.id=id;} boolean isAvailable(int time){return current==null||current.getDeparture()<=time;}
    void assign(Train t){current=t;} void release(){current=null;}
}
interface AllocStrategy { Platform allocate(List<Platform> platforms, Train train); }
class FirstAvailable implements AllocStrategy {
    public Platform allocate(List<Platform> p, Train t) {
        for(Platform pl:p) if(pl.isAvailable(t.getArrival())) return pl; return null;
    }
}
class Station {
    List<Platform> platforms=new ArrayList<>(); AllocStrategy strategy;
    Station(int n,AllocStrategy s){strategy=s;for(int i=1;i<=n;i++)platforms.add(new Platform(i));}
    void schedule(Train t) {
        for(Platform p:platforms) if(p.current!=null&&p.current.getDeparture()<=t.getArrival()) p.release();
        Platform p=strategy.allocate(platforms,t);
        if(p!=null){p.assign(t);System.out.println("  "+t.getName()+"->Platform "+p.id);}
        else System.out.println("  [ERROR] No platform for "+t.getName());
    }
    static int minPlatforms(List<Train> trains) {
        int[] arr=trains.stream().mapToInt(Train::getArrival).sorted().toArray();
        int[] dep=trains.stream().mapToInt(Train::getDeparture).sorted().toArray();
        int p=0,max=0,i=0,j=0;
        while(i<arr.length){if(arr[i]<dep[j]){p++;i++;}else{p--;j++;}max=Math.max(max,p);}
        return max;
    }
}
public class TrainPlatformSystem {
    public static void main(String[] args) {
        System.out.println("=== Train Platform — Java ===");
        Station st=new Station(3,new FirstAvailable());
        Train t1=new Train("T1","Express",540,600),t2=new Train("T2","Local",550,620),
              t3=new Train("T3","Fast",570,630),t4=new Train("T4","Slow",610,660);
        st.schedule(t1);st.schedule(t2);st.schedule(t3);st.schedule(t4);
        System.out.println("Min platforms: "+Station.minPlatforms(List.of(t1,t2,t3,t4)));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Strategy(allocation), Sweep algorithm O(NlogN) for min platforms
