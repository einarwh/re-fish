open Compose;
open Box;

type thing = int

type rendering = list(thing)

type picture = Box.box => rendering; 

let turn : picture => picture = 
    p => Box.turn >> p

let flip : picture => picture = 
    p => Box.flip >> p 

let toss : picture => picture = 
    p => Box.flip >> p 

let aboveRatio : (int, int, picture, picture) => picture = 
    (m, n, p1, p2) =>
        box => {
            let f = float(m) /. (float(m) +. float(n))
            let (top, bot) = splitVertically(f, box);
            List.append(p1(top), p2(bot));
        }

let above : (picture, picture) => picture = 
    aboveRatio(1, 1);

let besideRatio : (int, int, picture, picture) => picture = 
    (m, n, p1, p2) =>
        box => {
            let f = float(m) /. (float(m) +. float(n))
            let (left, right) = splitHorizontally(f, box);
            List.append(p1(left), p2(right));
        }

let beside : (picture, picture) => picture = 
    besideRatio(1, 1);

let quartet : (picture, picture, picture, picture) => picture = 
    (nw, ne, sw, se) =>
        above(beside(nw, ne), beside(sw, se));
