let (>>) = (f, g, x) => g(f(x));

let id = x => x;

let rec times = (n, fn) =>
  if (n > 0) {
    fn >> times(n - 1, fn);
  } else {
    id;
  };