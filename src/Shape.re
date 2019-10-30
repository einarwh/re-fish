open Point;

type shape = 
    | LineShape(Line.line) 
    | PolygonShape(Polygon.polygon)
    | PolylineShape(Polyline.polyline)
    | CurveShape(Curve.curve)
    | PathShape(point, list(Bezier.bezier))
