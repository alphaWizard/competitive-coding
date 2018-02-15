struct point {
     LL x,y ;
} C[100010];


/*return area of triangle */
LL areaTriangle(const point &a, const point &b, const point &c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

/*An user define function to calculate where a point p inside a convex hull or not */

bool inConvexPoly(int N, const point p) {

/*Input: C is an array with vertex x, y of a convex hull, points must be anticlock-wise, If it's clockwise then just reverse it. p is a point and we have to find does p inside polygon C or not*/

/*Most important part, finding two point using binay search such that point p may be lie inside the trianle
  made by those two points and point0 or point p may be lie inside the triangle which is
  made by point0, point_last, point_start */


LL start = 1, last = N - 1;
while(last - start > 1) {
    LL mid = (start + last) >> 1;
    if(areaTriangle(C[0], C[mid], p) < 0)   last = mid;
    else    start = mid;
}

/*Area of triangle form by point0, start point and last point*/
LL r0 = abs(areaTriangle(C[0], C[start], C[last]));


/*If point p is inside a triangle then the area of that triangle must be equal to
  the area ((point0, poin1, p) + (point0, point2, p) + (point1, point2, p))
  here point0 = C[0], point1 = C[start], point2 = C[last]*/

LL r1 = abs(areaTriangle(C[0], C[start], p));
LL r2 = abs(areaTriangle(C[0], C[last], p));
LL r3 = abs(areaTriangle(C[start], C[last], p));

/*Point p must not lie on any border line of the convex hull, So if the area is 0 then that three point lie on the
  same line */

LL r4 = areaTriangle(C[0], C[1], p);
LL r5 = areaTriangle(C[0], C[N - 1], p);

/*If the area of triangle form by point0, start and last point is equal to area
  from by triangle (point0, last, p) + (point0, start, p) + (last, start, p)
  and p don't lie on start-last line, point0-point1 line, point0-point[N - 1] line
  then the point p inside the convex hull */


 return (r0 == (r1 + r2 + r3) && r3 != 0 && r4 != 0 && r5 != 0);
}

