open Point;
open Shape;

/*** F ***/

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

let f : list(shape) = [ fShape ];

/*** H ***/

let hShape : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.40, 0.20),
          create(0.40, 0.45),
          create(0.60, 0.45),
          create(0.60, 0.20),
          create(0.70, 0.20),
          create(0.70, 0.80),
          create(0.60, 0.80),
          create(0.60, 0.55),
          create(0.40, 0.55),
          create(0.40, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts));
};

let h : list(shape) = [ hShape ];

/*** E ***/

let eShape : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.70, 0.20),
          create(0.70, 0.30),
          create(0.40, 0.30),
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

let e : list(shape) = [ eShape ];

/*** N ***/

let nShape : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.40, 0.20),
          create(0.40, 0.60),
          create(0.60, 0.20),
          create(0.70, 0.20),
          create(0.70, 0.80),
          create(0.60, 0.80),
          create(0.60, 0.40),
          create(0.40, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts));
};

let n : list(shape) = [ nShape ];
