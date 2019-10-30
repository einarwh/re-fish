open Point;

type line;
let create : (point, point) => line;
let start : line => point;
let stop : line => point;
