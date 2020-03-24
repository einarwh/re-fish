open Point;

type curve = {
  point1: point,
  point2: point,
  point3: point,
  point4: point,
};

let create: (point, point, point, point) => curve =
  (p1, p2, p3, p4) => {point1: p1, point2: p2, point3: p3, point4: p4};

let point1: curve => point = c => c.point1;

let point2: curve => point = c => c.point2;

let point3: curve => point = c => c.point3;

let point4: curve => point = c => c.point4;