type point = {
    x: float,
    y: float
};

let create : (float, float) => point = 
    (x, y) => { x: x, y: y };

let displace : (point, Vector.vector) => point = 
    (p, v) => { 
        x: p.x +. Vector.dx(v), 
        y: p.y +. Vector.dy(v)
    };

let x : point => float = p => p.x;

let y : point => float = p => p.y;

