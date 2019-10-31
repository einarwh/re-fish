let createMapper : float => Point.point => Point.point = 
    (height, pt) => {
        let px = Point.x(pt);
        let py = Point.y(pt);
        let py' = height -. py;
        Point.create(px, py');
    };

let mirror : float => list(Shape.shape) => list(Shape.shape) =
    (height, shapes) => {
        let mapper = createMapper(height);
        List.map(Shape.transpose(mapper), shapes)
    };
