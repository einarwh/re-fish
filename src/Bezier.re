open Point;

type bezier = { 
    controlPoint1 : point, 
    controlPoint2 : point,
    endPoint : point
};

let create : (point, point, point) => bezier =
    (cp1, cp2, ep) => {
        controlPoint1: cp1,
        controlPoint2: cp2, 
        endPoint: ep
    };

let controlPoint1 : bezier => point = bz => bz.controlPoint1;

let controlPoint2 : bezier => point = bz => bz.controlPoint2;

let endPoint : bezier => point = bz => bz.endPoint;
