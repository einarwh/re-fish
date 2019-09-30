open Vector;

type shape = 
    | LineShape(Line.line) 
    | PolygonShape(Polygon.polygon)
    | PolylineShape(Polyline.polyline)
    | CurveShape(Curve.curve)
    | PathShape(vector, list(Bezier.bezier))
