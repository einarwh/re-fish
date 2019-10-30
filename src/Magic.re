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

/**
 * | LineShape(Line.line) 
    | PolygonShape(Polygon.polygon)
    | PolylineShape(Polyline.polyline)
    | CurveShape(Curve.curve)
    | PathShape(point, list(Bezier.bezier))

 */

/*module Fitting exposing (createPicture)

import Vector exposing (Vector, add, scale, length) 
import Box exposing (Box)
import Shape exposing (..)
import Style exposing (..)
import Picture exposing (Picture)

mapper : Box -> Vector -> Vector 
mapper { a, b, c } { x, y } =
  add a (add (scale x b) (scale y c))

getStrokeWidth : Box -> Float
getStrokeWidth { b, c } =
  let 
    s = max (length b) (length c) 
  in
    s / 80.0

getStyle : Box -> Style
getStyle box = 
  let sw = getStrokeWidth box in
  { stroke = Just { strokeWidth = sw
                  , strokeColor = Black } 
  , fill = Nothing }

mapShape : (Vector -> Vector) -> Shape -> Shape 
mapShape m shape = 
  case shape of  
    Polygon { points } -> Polygon { points = List.map m points }
   
    Polyline { pts } -> Polyline { pts = List.map m pts }

    Curve { point1, point2, point3, point4 } ->
      Curve { point1 = m point1 
            , point2 = m point2 
            , point3 = m point3 
            , point4 = m point4 } 

    x -> x

createPicture : List Shape -> Picture
createPicture shapes box = 
  let 
    m = mapper box
    style = getStyle box
  in 
    shapes |> List.map (mapShape m) |> List.map (\s -> (s, style))
*/