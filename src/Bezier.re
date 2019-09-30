open Vector;

type bezier = { 
    controlPoint1 : vector, 
    controlPoint2 : vector,
    endPoint : vector
};

let create : (vector, vector, vector) => bezier =
    (cp1, cp2, ep) => {
        controlPoint1: cp1,
        controlPoint2: cp2, 
        endPoint: ep
    };

let controlPoint1 : bezier => vector = bz => bz.controlPoint1;

let controlPoint2 : bezier => vector = bz => bz.controlPoint2;

let endPoint : bezier => vector = bz => bz.endPoint;
