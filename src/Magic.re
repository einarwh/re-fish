let createMapper : Box.box => Point.point => Point.point = 
    (box, pt) => {
        let a = Box.a(box);
        let b = Box.b(box);
        let c = Box.c(box);
        let px = Point.x(pt);
        let py = Point.y(pt);
        let v = Vector.add(a, Vector.add(Vector.scale(px, b), Vector.scale(py, c)));
        Point.create(Vector.dx(v), Vector.dy(v));
    };

let createPicture : list(Shape.shape) => Picture.picture =
    shapes => 
        box => {
            let mapper = createMapper(box);
            List.map(Shape.transpose(mapper), shapes)
        };
