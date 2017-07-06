type position = (float, float);

type direction = (float, float);

type state = {
  position,
  direction,
  size: float,
  speed: float
};

let drawPlayer (ctx: Canvas.context) ({position: (x, y), size}: state) => {
  Canvas.fillStyle ctx "rgba(50, 205, 50, 1)";
  Canvas.beginPath ctx;
  Canvas.arc ctx (floor x) (floor y) size 0. (2. *. Utils.mathPI) false;
  Canvas.fill ctx
};

let draw (ctx: Canvas.context) (state: state) => {
  Canvas.fillStyle ctx "rgba(255, 255, 255, 0.1)";
  Canvas.fillRect ctx 0. 0. 500. 500.;
  drawPlayer ctx state
};

let update dt (state: state) :state => {
  let {position: (x, y), direction: (dx, dy), size} = state;
  let newX =
    switch (x +. state.speed *. dx *. dt /. 1000.) {
    | x when x > 500. => 500.
    | x => x
    };
  let newY =
    switch (y +. state.speed *. dy *. dt /. 1000.) {
    | y when y > 500. => 500.
    | y => y
    };
  let newDx =
    if (newX +. size > 500. || newX < 0.) {
      dx *. (-1.)
    } else {
      dx
    };
  let newDy =
    if (newY +. size > 500. || newY < 0.) {
      dy *. (-1.)
    } else {
      dy
    };
  {...state, position: (newX, newY), direction: (newDx, newDy)}
};

let start (ctx: Canvas.context) (state: state) => {
  let lastFrameTime = ref (Utils.now ());
  let st = ref state;
  let rec loop () => {
    let now = Utils.now ();
    let elapsed = Utils.getDelta !lastFrameTime now;
    let dt = elapsed > 50. ? 50. : elapsed;
    st := update dt !st;
    draw ctx !st;
    lastFrameTime := now;
    Document.requestAnimationFrame loop
  };
  loop ()
};

let canvas = Document.getElementById Document.dom "canvas";

let ctx = Canvas.getContext canvas "2d";

let state = {position: (0., 0.), direction: (1., 0.2), size: 10., speed: 350.};

start ctx state;
