
let mapper : Box.box -> Point -> Point = 
    (box, pt) => {
        let a = Box.a(box);
        let b = Box.b(box);
        let c = Box.c(box);
        let px = Point.x(pt);
        let py = Point.y(pt);
        let v = Vector.add(a, Vector.add(Vector.scale(px, b), Vector.scale(py, c)));
        Point.create(Vector.dx(v), Vector.dy(v));
    };

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