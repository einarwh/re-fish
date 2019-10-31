type lineAttributes = { 
    x1: string, 
    y1: string,
    x2: string,
    y2: string,
    stroke : string 
};

type polygonAttributes = {
    points: string,
    stroke: string,
    strokeWidth: string
};

type polylineAttributes = {
    points: string,
    stroke: string,
    strokeWidth: string
};

type pathAttributes = {
    d: string,
    stroke: string,
    strokeWidth: string
};

type element = 
    | LineElement(lineAttributes) 
    | PolygonElement(polygonAttributes)
    | PolylineElement(polylineAttributes)
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

let toColorString : Style.color => string = 
    color => {
        switch (color) {
        | Black => "black"
        | Grey => "grey"
        | White => "white"
        }
    };

let toStrokeWidthString : float => string = 
    width => Printf.sprintf("%.2f", width);

let toDString : Point.point => Point.point => Point.point => Point.point => string = 
    (sp, cp1, cp2, ep) => {
        let toStr : Point.point => string = 
            pt => {
                let x = Point.x(pt);
                let y = Point.y(pt);
                Printf.sprintf("%.2f %.2f", x, y)        
            };
        let sps = toStr(sp);
        let cp1s = toStr(cp1);
        let cp2s = toStr(cp2);
        let eps = toStr(ep);
        "M" ++ sps ++ " C " ++ cp1s ++ ", " ++ cp2s ++ ", " ++ eps
    };

let toElement : StyledShape.styledShape => element =
    styledShape => {
        let (shape, style) = styledShape;
        let strokeWidth = toStrokeWidthString(style.strokeWidth);
        let strokeColor = toColorString(style.strokeColor);
        switch shape {
        | Shape.LineShape(line) => {
            LineElement({
                x1: "0",
                y1: "0",
                x2: "0",
                y2: "0",
                stroke: "pink"
            })
        } 
        | Shape.PolygonShape(polygon) => {
            let points = Polygon.points(polygon);
            let pointsStr = toPointsString(points);
            PolygonElement({
                points: pointsStr,
                stroke: strokeColor,
                strokeWidth: strokeWidth
            })
        }
        | Shape.PolylineShape(polyline) => {
            let points = Polyline.points(polyline);
            let pointsStr = toPointsString(points);
            PolylineElement({
                points: pointsStr,
                stroke: strokeColor,
                strokeWidth: strokeWidth
            })
        }
        | Shape.CurveShape(curve) => {
            let sp = Curve.point1(curve);
            let cp1 = Curve.point2(curve);
            let cp2 = Curve.point3(curve);
            let ep = Curve.point4(curve);
            let d = toDString(sp, cp1, cp2, ep);
            PathElement({
                d: d,
                stroke: strokeColor,
                strokeWidth: strokeWidth
            })
        } 
        | Shape.PathShape(start, beziers) => {
            let d = "M 0,0"
            PathElement({
                d: d,
                stroke: strokeColor,
                strokeWidth: strokeWidth
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

let selectPathAttributes : element => option(pathAttributes) = 
    el => {
        switch (el) {
        | PathElement(attrs) => Some(attrs)
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

let paths : list(element) => list(pathAttributes) = 
    elements => 
        choose(selectPathAttributes, elements); 
