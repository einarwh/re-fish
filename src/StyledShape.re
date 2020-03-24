type styledShape = (Shape.shape, Style.style);

let transpose: (Point.point => Point.point, styledShape) => styledShape =
  (mapper, styled) => {
    let (shape, style) = styled;
    let mapped = Shape.transpose(mapper, shape);
    (mapped, style);
  };