type lineAttrs = {
    x1: string,
    y1: string,
    x2: string,
    y2: string,
    stroke: string
  };
  
[@react.component]
let make = (~size: string) => {
    let style = ReactDOMRe.Style.make(~width=size, ~height=size,());
    let box = Box.create(Vector.create(25., 25.), Vector.create(200., 0.), Vector.create(0., 200.));
    let fp = Magic.createPicture(Letter.f);
    let gp = Magic.createPicture(Figure.george);
    let qp = Picture.quartet(gp, gp |> Picture.flip |> Picture.turn |> Picture.turn, gp |> Picture.turn |> Picture.turn, gp |> Picture.flip);
    let qp' = qp |> Picture.turn |> Picture.turn;
    let fishp = Magic.createPicture(Fish.fish);
    let p = Picture.squareLimit(3, fishp);
    let rendered = fp(box);
    let elements = List.map(Svg.toElement, rendered);
    let lines = Array.of_list(Svg.lines(elements));
    let polygons = Array.of_list(Svg.polygons(elements));
    let polylines = Array.of_list(Svg.polylines(elements));
    let paths = Array.of_list(Svg.paths(elements));
    <svg
      style
      xmlns="http://www.w3.org/2000/svg">
      {lines->Belt.Array.map(le => <line x1=le.x1 y1=le.y1 x2=le.x2 y2=le.y2 stroke=le.stroke />)->React.array}
      {polygons->Belt.Array.map(el => <polygon points=el.points stroke=el.stroke fill="None" />)->React.array}
      {polylines->Belt.Array.map(el => <polyline points=el.points stroke=el.stroke fill="None" />)->React.array}
      {paths->Belt.Array.map(el => <path d=el.d stroke=el.stroke fill="None" />)->React.array}
    </svg>;
  };