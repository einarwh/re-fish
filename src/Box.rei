
open Vector;

type box;

let create: (vector, vector, vector) => box;

let turn: box => box;

let flip: box => box;

let toss: box => box;

let splitVertically : (float, box) => (box, box);

let splitHorizontally : (float, box) => (box, box);
