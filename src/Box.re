
open Vector;

type box = {
    a: vector,
    b: vector,
    c: vector
};

let create : (vector, vector, vector) => box = 
    (a, b, c) => { a: a, b: b, c: c }

let turn : box => box = 
    ({ a, b, c }) => 
        { a: add(a, b),
          b: c,
          c: neg(b) }

let flip : box => box = 
    ({ a, b, c }) => 
        { a: add(a, b),
          b: neg(b),
          c: c }

let toss : box => box = 
    ({ a, b, c }) =>
        { a: add(a, scale(0.5, (add(b, c)))),
          b: scale(0.5, add(b, c)),
          c: scale(0.5, sub(c, b)) };

let moveVertically : (float, box) => box =
    (f, { a, b, c }) => 
        { a: add(a, scale(f, c)),
          b: b,
          c: c }
        
let scaleVertically : (float, box) => box =
    (f, { a, b, c }) => 
        { a: a, 
          b: b, 
          c: scale(f, c) }

let splitVertically : (float, box) => (box, box) =
    (f, box) => {
        let g = 1. -. f;
        let top = box |> moveVertically(g) |> scaleVertically(f);
        let bot = box |> scaleVertically(g);
        (top, bot);
    }

let moveHorizontally : (float, box) => box =
    (f, { a, b, c }) => 
        { a: add(a, scale(f, b)),
          b: b,
          c: c }
        
let scaleHorizontally : (float, box) => box =
    (f, { a, b, c }) => 
        { a: a, 
          b: scale(f, b), 
          c: c }

let splitHorizontally : (float, box) => (box, box) =
    (f, box) => {
        let g = 1. -. f;
        let left = box |> scaleHorizontally(f)
        let right = box |> moveHorizontally(f) |> scaleHorizontally(g);
        (left, right);
    }

let a : box => vector = 
    box => box.a;

let b : box => vector = 
    box => box.b;

let c : box => vector = 
    box => box.c;
