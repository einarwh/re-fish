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
    PolygonShape(Polygon.create(pts))
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
    PolygonShape(Polygon.create(pts))
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
    PolygonShape(Polygon.create(pts))
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
    PolygonShape(Polygon.create(pts))
};

let n : list(shape) = [ nShape ];

/*** D ***/

let dShape1 : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.55, 0.20),
          create(0.70, 0.35),
          create(0.70, 0.65),
          create(0.55, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts))
};

let dShape2 : shape = {
    let pts = 
        [ create(0.40, 0.30), 
          create(0.52, 0.30),
          create(0.60, 0.38),
          create(0.60, 0.62),
          create(0.52, 0.70),
          create(0.40, 0.70) ];
    PolygonShape(Polygon.create(pts))
};

let d : list(shape) = [ dShape1, dShape2 ];

/*** R ***/

let rShape1 : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.40, 0.20),
          create(0.40, 0.45),
          create(0.45, 0.45),
          create(0.60, 0.20),
          create(0.70, 0.20),
          create(0.55, 0.45),
          create(0.70, 0.45),
          create(0.70, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts))
};

let rShape2 : shape = {
    let pts = 
        [ create(0.40, 0.55), 
          create(0.60, 0.55),
          create(0.60, 0.70),
          create(0.40, 0.70) ];
    PolygonShape(Polygon.create(pts))
};

let r : list(shape) = [ rShape1, rShape2 ];

/*** S ***/

let sShape : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.70, 0.20),
          create(0.70, 0.55),
          create(0.40, 0.55),
          create(0.40, 0.70),
          create(0.70, 0.70),
          create(0.70, 0.80),
          create(0.30, 0.80),
          create(0.30, 0.45),
          create(0.60, 0.45),
          create(0.60, 0.30), 
          create(0.30, 0.30) ];
    PolygonShape(Polygon.create(pts))
};

let s : list(shape) = [ sShape ];

/*** O ***/

let oShape1 : shape = {
    let pts = 
        [ create(0.30, 0.20), 
          create(0.70, 0.20),
          create(0.70, 0.80),
          create(0.30, 0.80) ];
    PolygonShape(Polygon.create(pts))
};

let oShape2 : shape = {
    let pts = 
        [ create(0.40, 0.30), 
          create(0.60, 0.30),
          create(0.60, 0.70),
          create(0.40, 0.70) ];
    PolygonShape(Polygon.create(pts))
};

let o : list(shape) = [ oShape1, oShape2 ];
