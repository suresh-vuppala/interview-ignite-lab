import java.util.*;
class Solution {
    public int maxEnvelopes(int[][] env) {
        Arrays.sort(env,(a,b)->a[0]==b[0]?b[1]-a[1]:a[0]-b[0]);
        List<Integer> tails=new ArrayList<>();
        for(int[] e:env){int pos=Collections.binarySearch(tails,e[1]);
            if(pos<0)pos=-(pos+1);if(pos==tails.size())tails.add(e[1]);else tails.set(pos,e[1]);}
        return tails.size();
    }
}