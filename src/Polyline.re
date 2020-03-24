open Point;

type polyline = list(point);

let create: list(point) => polyline = points => points;

let points: polyline => list(point) = polyline => polyline;