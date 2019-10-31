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

let getStrokeWidth : Box.box => float = 
    box => {
        let bv = Box.b(box);
        let cv = Box.c(box);
        let s = max(Vector.length(bv), Vector.length(cv));
        s /. 50.0
    };

let getStyle : Box.box => Style.style = 
    box => {
        strokeWidth: getStrokeWidth(box),
        strokeColor: Black
    };

let createPicture : list(Shape.shape) => Picture.picture =
    shapes => 
        box => {
            let mapper = createMapper(box);
            let style = getStyle(box);
            List.map(s => (Shape.transpose(mapper, s), style), shapes)
        };
