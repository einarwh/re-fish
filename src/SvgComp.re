[@react.component]
let make = (~size) => {
  let style = ReactDOMRe.Style.make(~width=size, ~height=size, ());
  let box =
    Box.create(
      Vector.create(0., 0.),
      Vector.create(250., 0.),
      Vector.create(0., 250.),
    );
  let fishp = Magic.createPicture(Fish.fish);
  let p = Picture.squareLimit(3, fishp);
  let rendered = p(box);
  let mirrored = Mirror.mirror(250., rendered);
  let elements = List.map(Svg.toElement, mirrored);
  let lines = Svg.lines(elements);
  let polygons = Svg.polygons(elements);
  let polylines = Svg.polylines(elements);
  let paths = Svg.paths(elements);
  <svg style xmlns="http://www.w3.org/2000/svg">
    {lines
     ->Belt.List.map(le =>
         <line
           x1={le.x1}
           y1={le.y1}
           x2={le.x2}
           y2={le.y2}
           stroke={le.stroke}
         />
       )
     ->Array.of_list
     ->React.array}
    {polygons
     ->Belt.List.map(el =>
         <polygon
           points={el.points}
           stroke={el.stroke}
           strokeWidth={el.strokeWidth}
           fill="None"
         />
       )
     ->Array.of_list
     ->React.array}
    {polylines
     ->Belt.List.map(el =>
         <polyline
           points={el.points}
           stroke={el.stroke}
           strokeWidth={el.strokeWidth}
           fill="None"
         />
       )
     ->Array.of_list
     ->React.array}
    {paths
     ->Belt.List.map(el =>
         <path
           d={el.d}
           stroke={el.stroke}
           strokeWidth={el.strokeWidth}
           fill="None"
         />
       )
     ->Array.of_list
     ->React.array}
  </svg>;
};