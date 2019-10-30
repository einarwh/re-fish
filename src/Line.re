open Point;

type line = { start: point, stop: point }

let create : (point, point) => line =
    (start, stop) => { start: start, stop: stop };

let start : line => point =
    (line) => line.start;

let stop : line => point = 
    (line) => line.stop;
