type t = {
  position: Vec.t,
  direction: Vec.t,
  radius: float,
  speed: float
};

let rect (ball: t) :Rect.t => {
  let size: Vec.t = {x: ball.radius *. 2., y: ball.radius *. 2.};
  let position: Vec.t = {x: ball.position.x -. ball.radius, y: ball.position.y -. ball.radius};
  {position, size}
};

let draw (ctx: Canvas.context) (ball: t) => {
  Canvas.fillStyle ctx "rgba(0, 0, 0, 1)";
  Canvas.beginPath ctx;
  Canvas.arc ctx ball.position.x ball.position.y ball.radius 0. (2. *. Utils.mathPI) false;
  Canvas.fill ctx
};

let fixMovement pos dir radius canvasSize =>
  switch pos {
  | p when p -. radius < 0. => (radius, dir *. (-1.))
  | p when p +. radius > canvasSize => (canvasSize -. radius, dir *. (-1.))
  | _ => (pos, dir)
  };

let fixMovements (ball: t) canvasSize :t => {
  let (newX, newDx) = fixMovement ball.position.x ball.direction.x ball.radius canvasSize;
  let (newY, newDy) = fixMovement ball.position.y ball.direction.y ball.radius canvasSize;
  {...ball, position: {x: newX, y: newY}, direction: {x: newDx, y: newDy}}
};

let update dt canvasSize (ball: t) => {
  let newX = ball.position.x +. ball.speed *. ball.direction.x *. dt /. 1000.;
  let newY = ball.position.y +. ball.speed *. ball.direction.y *. dt /. 1000.;
  let ball = {...ball, position: {x: newX, y: newY}};
  fixMovements ball canvasSize
};
