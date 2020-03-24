open Point;
open Shape;

let george: list(shape) = {
  let pts1 = [
    create(0.00, 0.55),
    create(0.15, 0.45),
    create(0.30, 0.55),
    create(0.40, 0.50),
    create(0.20, 0.00),
  ];
  let pts2 = [
    create(0.00, 0.80),
    create(0.15, 0.60),
    create(0.30, 0.65),
    create(0.40, 0.65),
    create(0.35, 0.80),
    create(0.40, 1.00),
  ];
  let pts3 = [
    create(0.60, 1.00),
    create(0.65, 0.80),
    create(0.60, 0.65),
    create(0.80, 0.65),
    create(1.00, 0.45),
  ];
  let pts4 = [create(1.00, 0.20), create(0.60, 0.50), create(0.80, 0.00)];
  let pts5 = [create(0.40, 0.00), create(0.50, 0.30), create(0.60, 0.00)];
  let createPolyline: list(point) => shape =
    pts => PolylineShape(Polyline.create(pts));
  let polylines = [
    createPolyline(pts1),
    createPolyline(pts2),
    createPolyline(pts3),
    createPolyline(pts4),
    createPolyline(pts5),
  ];
  polylines;
};