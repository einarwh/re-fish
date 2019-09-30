open Vector;

type bezier;
let create : (vector, vector, vector) => bezier;
let controlPoint1 : bezier => vector;
let controlPoint2 : bezier => vector;
let endPoint : bezier => vector;
