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




// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool doInstersect(Point p1,Point p2,Point p3,Point p4)
{
    int d1,d2,d3,d4;
    d1=orientation(p3,p4,p1);
    d2=orientation(p3,p4,p2);
    d3=orientation(p1,p2,p3);
    d4=orientation(p1,p2,p4);
    if(((d1==1&&d2==2)||(d1==2&&d2==1))&&((d3==1&&d4==2)||(d3==2&&d4==1)))
        return true;
    else if(d1==0 && onSegment(p3,p4,p1))
        return true;
    else if(d2==0 && onSegment(p3,p4,p2))
        return true;
    else if(d3==0 && onSegment(p1,p2,p3))
        return true;
    else if(d4==0 && onSegment(p1,p2,p4))
        return true;
    else 
        return false;
}
bool onSegment(Point p1, Point p2, Point p3)
{
    if(p3.x>=(min(p1.x,p2.x))&&(p3.x<=max(p1.x,p2.x))&&(p3.y>=min(p1.y,p2.y))&&(p3.y<=max(p1.y,p2.y)))
    {
        return true;
    }
    return false;
}
bool isInside(Point inner[MAX], int n, Point outer[MAX], int m)
{
    bool isInside=true;
    int prev_orientation,curr_orientation;
    for(int i=0;i<n;i++)
    {
        prev_orientation=orientation(inner[i],outer[0],outer[1]);
        for(int j=0;j<m;j++)
        {
            curr_orientation=orientation(inner[i],outer[j],outer[(j+1)%m]);
            if(curr_orientation!=prev_orientation)
                return false;
        }
    }
    return true;
}

