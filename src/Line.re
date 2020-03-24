open Point;

type line = {
  start: point,
  stop: point,
};

let create: (point, point) => line = (start, stop) => {start, stop};

let start: line => point = line => line.start;

let stop: line => point = line => line.stop;