open Point;

type shape = 
    | LineShape(Line.line) 
    | PolygonShape(Polygon.polygon)
    | PolylineShape(Polyline.polyline)
    | CurveShape(Curve.curve)
    | PathShape(point, list(Bezier.bezier))

let transpose : (point => point) => shape => shape = 
    (mapper, shape) => {
        switch (shape) {
        | LineShape(line) => {
            let start = Line.start(line);
            let stop = Line.stop(line);
            let line' = Line.create(mapper(start), mapper(stop));
            LineShape(line')
        }
        | PolygonShape(polygon) => {
            let points = Polygon.points(polygon);
            let polygon' = Polygon.create(List.map(p => mapper(p), points));
            PolygonShape(polygon')
        } 
        | PolylineShape(polyline) => {
            let points = Polyline.points(polyline);
            let polyline' = Polyline.create(List.map(p => mapper(p), points));
            PolylineShape(polyline')
        } 
        | CurveShape(curve) => {
            let p1 = Curve.point1(curve);
            let p2 = Curve.point2(curve);
            let p3 = Curve.point3(curve);
            let p4 = Curve.point4(curve);
            let curve' = Curve.create(mapper(p1), mapper(p2), mapper(p3), mapper(p4));
            CurveShape(curve')
        }
        | PathShape(start, beziers) => {
            let mapBezier : Bezier.bezier => Bezier.bezier = 
                bz => {
                    let cp1 = Bezier.controlPoint1(bz);
                    let cp2 = Bezier.controlPoint2(bz);
                    let ep = Bezier.endPoint(bz);
                    Bezier.create(mapper(cp1), mapper(cp2), mapper(ep))
                };
            let start' = mapper(start);
            let beziers' = List.map(mapBezier, beziers);
            PathShape(start', beziers')
        }
        }
    };
