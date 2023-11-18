// Leetcode 2849

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // edge case
        if(sx==fx && sy==fy && t==1) return false;
        // check in same line or not
        // same x
        if(sx==fx) return (abs(sy-fy) <= t);
        // same y
        if(sy==fy) return (abs(sx-fx) <= t);
        // final to the north east of start
        if(fx-sx>=0 && fy-sy>=0){
            int dx = fx - sx, dy = fy - sy;
            if(sy + dx == fy) return dx <= t;
            if(sy + dx > fy) return (fx-sx <= t);
            if(sx + dy > fx) return (fy-sy <= t);
        }
        // final to the south east of start
        if(fx-sx>=0 && fy-sy<=0){
            int dx = fx - sx, dy = abs(fy - sy);
            if(sy - dx == fy) return dx <= t;
            if(sy - dx < fy) return (fx-sx <= t);
            if(sx + dy > fx) return (dy <= t);
        }
        // final to south west of start
        if(fx-sx<=0 && fy-sy<=0){
            int dx = abs(fx - sx), dy = abs(fy - sy);
            if(sy - dx == fy) return dx <= t;
            if(sy - dx < fy) return (dx <= t);
            if(sx - dy < fx) return (dy <= t);
        }
        // final to the north west of start
        if(fx-sx<=0 && fy-sy>=0){
            int dx = abs(fx - sx), dy = fy - sy;
            if(sy + dx == fy) return dx <= t;
            if(sy + dx > fy) return (dx <= t);
            if(sx - dy < fx) return (fy-sy <= t);
        }
        return false;
    }
};