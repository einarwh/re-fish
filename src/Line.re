open Vector;

type line = { start: vector, stop: vector }

let create : (vector, vector) => line =
    (start, stop) => { start: start, stop: stop };

let start : line => vector =
    (line) => line.start;

let stop : line => vector = 
    (line) => line.stop;
