let v1 = Vector.create(1., 2.);
let v2 = Vector.create(2., 3.5);
let v3 = Vector.add(v1, v2);
let v4 = Vector.sub(v2, v1);

let b1 = Box.create(v1, v2, v3);

Js.log(v1);
Js.log(v2);
Js.log(v3);
Js.log(v4);
Js.log(Vector.scale(5., v1));
Js.log(Vector.neg(v1));
Js.log(b1);
Js.log(Box.turn(b1));

Js.log(Letter.f);

