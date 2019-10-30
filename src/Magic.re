let createMapper : (Box.box, Point.point) => Point.point = 
    (box, pt) => {
        let a = Box.a(box);
        let b = Box.b(box);
        let c = Box.c(box);
        let px = Point.x(pt);
        let py = Point.y(pt);
        let v = Vector.add(a, Vector.add(Vector.scale(px, b), Vector.scale(py, c)));
        Point.create(Vector.dx(v), Vector.dy(v));
    };

let mapBezier : (Point.point => Point.point, Bezier.bezier) => Bezier.bezier = 
    (mapper, bezier) => {
        let cp1 = Bezier.controlPoint1(bezier);
        let cp2 = Bezier.controlPoint2(bezier);
        let ep = Bezier.endPoint(bezier);
        Bezier.create(mapper(cp1), mapper(cp2), mapper(ep))
    }

let mapShape : (Point.point => Point.point, Shape.shape) => Shape.shape =
    (mapper, shape) => {
        switch (shape) {
        | Shape.LineShape(line) => {
            let start = Line.start(line);
            let stop = Line.stop(line);
            let line' = Line.create(mapper(start), mapper(stop));
            Shape.LineShape(line')
        }
        | Shape.PolygonShape(polygon) => {
            let points = Polygon.points(polygon);
            let polygon' = Polygon.create(List.map(p => mapper(p), points));
            Shape.PolygonShape(polygon')
        } 
        | Shape.PolylineShape(polyline) => {
            let points = Polyline.points(polyline);
            let polyline' = Polyline.create(List.map(p => mapper(p), points));
            Shape.PolylineShape(polyline')
        } 
        | Shape.CurveShape(curve) => {
            let p1 = Curve.point1(curve);
            let p2 = Curve.point2(curve);
            let p3 = Curve.point3(curve);
            let p4 = Curve.point4(curve);
            let curve' = Curve.create(mapper(p1), mapper(p2), mapper(p3), mapper(p4));
            Shape.CurveShape(curve')
        }
        | Shape.PathShape(start, beziers) => {
            let mapBezier : Bezier.bezier => Bezier.bezier = 
                bz => {
                    let cp1 = Bezier.controlPoint1(bz);
                    let cp2 = Bezier.controlPoint2(bz);
                    let ep = Bezier.endPoint(bz);
                    Bezier.create(mapper(cp1), mapper(cp2), mapper(ep))
                };
            let start' = mapper(start);
            let beziers' = List.map(mapBezier, beziers);
            Shape.PathShape(start', beziers')
        }
        }
    };

let createPicture : list(Shape.shape) => Picture.picture =
    shapes => 
        box => {
            let mapper = createMapper(box);
            List.map(mapShape(mapper), shapes)
        };
