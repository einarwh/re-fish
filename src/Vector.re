type vector = {
    x: float,
    y: float
};

let create : (float, float) => vector = 
    (x, y) => { x: x, y: y }

let add = (v1 : vector, v2 : vector) : vector =>
    { x: v1.x +. v2.x,
      y: v1.y +. v2.y }

let sub = (v1 : vector, v2 : vector) : vector => 
    { x: v1.x -. v2.x,
      y: v1.y -. v2.y }

let neg = (v : vector) : vector =>
    { x: ~-.v.x, y: ~-.v.y}

let scale = (f : float, v : vector) : vector =>
    { x: f *. v.x,
      y: f *. v.y }

let length = (v : vector) : float =>
    hypot(v.x, v.y)

let dx : vector => float = v => v.x;

let dy : vector => float = v => v.y;

