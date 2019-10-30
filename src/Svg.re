type lineAttributes = { 
    x1: string, 
    y1: string,
    x2: string,
    y2: string,
    stroke : string 
};

type polygonAttributes = {
    points: string,
    stroke: string
};

type polylineAttributes = {
    points: string,
    stroke: string
};

type curveAttributes = {
    foo: string,
    stroke: string
};

type pathAttributes = {
    d: string,
    stroke: string
};

type element = 
    | LineElement(lineAttributes) 
    | PolygonElement(polygonAttributes)
    | PolylineElement(polylineAttributes)
    | CurveElement(curveAttributes)
    | PathElement(pathAttributes)

let toElement : Shape.shape => element =
    shape => {
        switch shape {
        | Shape.LineShape(line) => {
            LineElement({
                x1: "0",
                y1: "0",
                x2: "0",
                y2: "0",
                stroke: "black"
            })
        } 
        | Shape.PolygonShape(polygon) => {
            let points = Polygon.points(polygon);
            let pointsStr = "";
            PolygonElement({
                points: pointsStr,
                stroke: "black"
            })
        }
        | Shape.PolylineShape(polyline) => {
            let points = Polyline.points(polyline);
            let pointsStr = "";
            PolylineElement({
                points: pointsStr,
                stroke: "black"
            })
        }
        | Shape.CurveShape(curve) => {
            let flop = "";
            CurveElement({
                foo: flop,
                stroke: "black"
            })
        } 
        | Shape.PathShape(start, beziers) => {
            let d = "M 0,0"
            PathElement({
                d: d,
                stroke: "black"
            })
        } 
        }
    }