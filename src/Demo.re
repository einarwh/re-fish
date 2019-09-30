type animal = Cat(string) | Dog(string)

let speak = (animal) => 
    switch (animal) {
    | Cat(name) => name ++ " says meow"
    | Dog(name) => name ++ " says woof"
    }

module Vector = {
    type vector = {
        x: float,
        y: float
    };

    let create = (x : float, y : float) : vector => 
        { x: x, y: y }

    let add = (v1 : vector, v2 : vector) : vector =>
        { x: v1.x +. v2.x,
          y: v1.y +. v2.y }

    let sub = (v1 : vector, v2 : vector) : vector => 
        { x: v1.x -. v2.x,
          y: v1.y -. v2.y }

    let neg = (v : vector) : vector =>
        { x: ~-.v.x, y: ~-.v.y}

    let scale = (v : vector, f : float) : vector =>
        { x: f *. v.x,
          y: f *. v.y }

    let length = (v : vector) : float =>
        hypot(v.x, v.y)
}

let v1 = Vector.create(1., 2.);
let v2 = Vector.create(2., 3.5);
let v3 = Vector.add(v1, v2);
let v4 = Vector.sub(v2, v1);

Js.log(speak(Cat("Strofe")));
Js.log(speak(Dog("Kompis")));
Js.log(v3);
Js.log(v4);


