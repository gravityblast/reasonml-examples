let fixBallMovement pos dir radius canvasSize =>
  switch pos {
  | p when p -. radius < 0. => (radius, dir *. (-1.))
  | p when p +. radius > canvasSize => (canvasSize -. radius, dir *. (-1.))
  | _ => (pos, dir)
  };

let fixBallMovements (ball: Ball.t) canvasSize :Ball.t => {
  let (newX, newDx) = fixBallMovement ball.position.x ball.direction.x ball.radius canvasSize;
  let (newY, newDy) = fixBallMovement ball.position.y ball.direction.y ball.radius canvasSize;
  {...ball, position: {x: newX, y: newY}, direction: {x: newDx, y: newDy}}
};

let updateBallPosition dt (ball: Ball.t) canvasSize => {
  let newX = ball.position.x +. ball.speed *. ball.direction.x *. dt /. 1000.;
  let newY = ball.position.y +. ball.speed *. ball.direction.y *. dt /. 1000.;
  let ball = {...ball, position: {x: newX, y: newY}};
  fixBallMovements ball canvasSize
};

let updatePositions (dt: float) (model: Model.t) :Model.t => {
  let ball = updateBallPosition dt model.ball model.canvasSize;
  {...model, ball}
};

let update dt (model: Model.t) => model |> updatePositions dt;

let draw (ctx: Canvas.context) (model: Model.t) => {
  let rect: Rect.t = {position: {x: 0., y: 0.}, size: {x: model.canvasSize, y: model.canvasSize}};
  Canvas.clear ctx rect;
  Ball.draw ctx model.ball
};
