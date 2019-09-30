open Vector;

type curve = { 
    point1 : vector, 
    point2 : vector,
    point3 : vector,
    point4 : vector
};

let create : (vector, vector, vector, vector) => curve =
    (p1, p2, p3, p4) => {
        point1: p1,
        point2: p2, 
        point3: p3,
        point4: p4
    };

let point1 : curve => vector = c => c.point1;

let point2 : curve => vector = c => c.point2;

let point3 : curve => vector = c => c.point3;

let point4 : curve => vector = c => c.point4;
