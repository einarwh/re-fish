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

let toPointString : Point.point => string = 
    pt => {
        let x = Point.x(pt);
        let y = Point.y(pt);
        Printf.sprintf("%.2f,%.2f", x, y)
    };

let toPointsString : list(Point.point) => string = 
    points => {
        let strs = List.map(toPointString, points);
        String.concat(" ", strs)
    };

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
            let pointsStr = toPointsString(points);
            PolygonElement({
                points: pointsStr,
                stroke: "black"
            })
        }
        | Shape.PolylineShape(polyline) => {
            let points = Polyline.points(polyline);
            let pointsStr = toPointsString(points);
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
    };

let selectLineAttributes : element => option(lineAttributes) = 
    el => {
        switch (el) {
        | LineElement(attrs) => Some(attrs)
        | _ => None
        }
    };

let selectPolygonAttributes : element => option(polygonAttributes) = 
    el => {
        switch (el) {
        | PolygonElement(attrs) => Some(attrs)
        | _ => None
        }
    };

let selectPolylineAttributes : element => option(polylineAttributes) = 
    el => {
        switch (el) {
        | PolylineElement(attrs) => Some(attrs)
        | _ => None
        }
    };

let choose : ('a => option('b)) => list('a) => list('b) = 
    (chooser, values) => {
        let mapped = List.map(chooser, values);
        let justChosen = List.filter(Belt.Option.isSome, mapped);
        let unwrapped = List.map(Belt.Option.getExn, justChosen);
        unwrapped
    };

let lines : list(element) => list(lineAttributes) = 
    elements => 
        choose(selectLineAttributes, elements); 

let polygons : list(element) => list(polygonAttributes) = 
    elements => 
        choose(selectPolygonAttributes, elements); 

let polylines : list(element) => list(polylineAttributes) = 
    elements => 
        choose(selectPolylineAttributes, elements); 
