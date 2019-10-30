open Point;

type bezier;
let create : (point, point, point) => bezier;
let controlPoint1 : bezier => point;
let controlPoint2 : bezier => point;
let endPoint : bezier => point;
