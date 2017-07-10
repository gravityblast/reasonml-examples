type position = (float, float);

type direction = (float, float);

type model = {
  position,
  direction,
  radius: float,
  speed: float,
  canvasSize: float
};

let drawPlayer (ctx: Canvas.context) ({position: (x, y), radius}: model) => {
  Canvas.fillStyle ctx "rgba(0, 0, 0, 1)";
  Canvas.beginPath ctx;
  Canvas.arc ctx x y radius 0. (2. *. Utils.mathPI) false;
  Canvas.fill ctx
};

let draw (ctx: Canvas.context) (model: model) => {
  Canvas.clearRect ctx 0. 0. model.canvasSize model.canvasSize;
  drawPlayer ctx model
};

let updatePosition (dt : float) ({position: (x, y), direction: (dx, dy)} as model : model) : model => {
  let newX = x +. model.speed *. dx *. dt /. 1000.;
  let newY = y +. model.speed *. dy *. dt /. 1000.;
  {...model, position: (newX, newY)};
};

let fixMovement (pos : float) (dir : float) (radius : float) (canvasSize : float) => {
  switch (pos) {
    | p when p -. radius < 0. => (radius, dir *. -1.)
    | p when p +. radius > canvasSize => (canvasSize -. radius, dir *. -1.)
    | _ => (pos, dir)
  };
};

let fixMovements ({position: (x, y), direction: (dx, dy), radius, canvasSize} as model : model) : model => {
  let (newX, newDx) = fixMovement x dx radius canvasSize;
  let (newY, newDy) = fixMovement y dy radius canvasSize;
  {...model, position: (newX, newY), direction: (newDx, newDy)};
};

let update dt (model: model) => {
  model
    |> updatePosition dt
    |> fixMovements;
};

let start (ctx: Canvas.context) (model: model) => {
  let lastFrameTime = ref (Utils.now ());
  let m = ref model;

  let rec loop () => {
    let now = Utils.now ();
    let elapsed = Utils.getDelta !lastFrameTime now;
    let dt = elapsed > 50. ? 50. : elapsed;
    m := update dt !m;
    draw ctx !m;
    lastFrameTime := now;
    Document.requestAnimationFrame loop;
  };

  loop ()
};

let canvas = Document.getElementById Document.dom "canvas";

let ctx = Canvas.getContext canvas "2d";

let model = {position: (10., 10.), direction: (0.8, 0.5), radius: 10., speed: 300., canvasSize: 500.};

start ctx model;
