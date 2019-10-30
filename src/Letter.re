open Point;
open Shape;

let fShape : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.40, 0.20),
          create(0.40, 0.45),
          create(0.60, 0.45),
          create(0.60, 0.55),
          create(0.40, 0.55),
          create(0.40, 0.70),
          create(0.70, 0.70),
          create(0.70, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts));
};

let fLetter : list(shape) = [ fShape ];
