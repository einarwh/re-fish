type point = {
    x: float,
    y: float
};

let create : (float, float) => point = 
    (x, y) => { x: x, y: y };

let displace : (point, Vector.vector) => point = 
    (p, v) => { 
        let vx : float = Vector.xdim(v);
        let vy : float = Vector.ydim(v);
        let px : float = p.x;
        let py : float = p.y;
        { x: px +. vx, y: py +. vy }
    };

let x : point => float = p => p.x;

let y : point => float = p => p.y;

