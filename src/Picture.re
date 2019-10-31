open Compose;

type styledShape = (Shape.shape, Style.style);

type rendering = list(StyledShape.styledShape);

type picture = Box.box => rendering; 

let blank : picture = _ => [];

let turn : picture => picture = 
    p => Box.turn >> p

let flip : picture => picture = 
    p => Box.flip >> p 

let toss : picture => picture = 
    p => Box.toss >> p 

let aboveRatio : (int, int, picture, picture) => picture = 
    (m, n, p1, p2) =>
        box => {
            let f = float(m) /. (float(m) +. float(n))
            let (top, bot) = Box.splitVertically(f, box);
            List.append(p1(top), p2(bot));
        }

let above : (picture, picture) => picture = 
    aboveRatio(1, 1);

let besideRatio : (int, int, picture, picture) => picture = 
    (m, n, p1, p2) =>
        box => {
            let f = float(m) /. (float(m) +. float(n))
            let (left, right) = Box.splitHorizontally(f, box);
            List.append(p1(left), p2(right));
        }

let beside : (picture, picture) => picture = 
    besideRatio(1, 1);

let quartet : (picture, picture, picture, picture) => picture = 
    (nw, ne, sw, se) =>
        above(beside(nw, ne), beside(sw, se));

let row : list(picture) => picture = 
    ps => box => [];

let col : list(picture) => picture = 
    ps => box => [];

let nonet : (picture, picture, picture, picture, picture, picture, picture, picture, picture) => picture = 
    (nw, nm, ne, mw, mm, me, sw, sm, se) => {
        let row : (picture, picture, picture) => picture = 
            (w, m, e) => besideRatio(1, 2, w, beside(m, e));
        let col : (picture, picture, picture) => picture = 
            (n, m, s) => aboveRatio(1, 2, n, above(m, s));
        col(row(nw, nm, ne), row(mw, mm, me), row(sw, sm, se))
    };

let over : (picture, picture) => picture = 
    (p1, p2) => 
        box => List.append(p1(box), p2(box));

let ttile : picture => picture = 
    p => {
        let pn = p |> toss |> flip;
        let pe = pn |> turn |> turn |> turn;
        p |> over(pn) |> over(pe)
    };

let utile : picture => picture = 
    p => {
        let pn = p |> toss |> flip;
        let pw = pn |> turn;
        let ps = pw |> turn;
        let pe = ps |> turn;
        pn |> over(pw) |> over(ps) |> over(pe)
    };

let rec side : int => picture => picture = 
    (n, p) => {
        if (n == 0) {
            blank
        }
        else {
            let s = side(n - 1, p);
            let t = ttile(p);
            quartet(s, s, turn(t), t);
        }
    }

let rec corner : int => picture => picture = 
    (n, p) => {
        if (n == 0) {
            blank
        }
        else {
            let c = corner(n - 1, p);
            let s = side(n - 1, p);
            quartet(c, s, turn(s), utile(p))
        }
    }

let squareLimit : int => picture => picture = 
    (n, p) => {
        let nw = corner(n, p);
        let sw = turn(nw);
        let se = turn(sw);
        let ne = turn(se);
        let nm = side(n, p);
        let mw = turn(nm);
        let sm = turn(mw);
        let me = turn(sm);
        let mm = utile(p);
        nonet(nw, nm, ne, mw, mm, me, sw, sm, se)
    }