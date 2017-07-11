let updatePositions (dt: float) (model: Model.t) :Model.t => {
  let ball = Ball.update dt model.ball model.canvasSize;
  {...model, ball}
};

let update dt (model: Model.t) => model |> updatePositions dt;

let draw (ctx: Canvas.context) (model: Model.t) => {
  let rect: Rect.t = {position: {x: 0., y: 0.}, size: {x: model.canvasSize, y: model.canvasSize}};
  Canvas.clear ctx rect;
  Ball.draw ctx model.ball
};
