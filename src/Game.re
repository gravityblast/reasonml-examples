let checkBallCollision (paddle: Paddle.t) (ball: Ball.t) :Ball.t =>
  if (Collision.isCollidingWith (Ball.rect ball) (Paddle.rect paddle)) {
    {...ball, direction: {x: ball.direction.x *. (-1.), y: ball.direction.y *. (-1.)}}
  } else {
    ball
  };

let updatePaddleDirection (model: Model.t) => {
  let x =
    switch model.input {
    | {left: true, right: false} => (-1.)
    | {left: false, right: true} => 1.
    | _ => 0.
    };
  let paddle: Paddle.t = {...model.paddle, direction: {...model.paddle.direction, x}};
  {...model, paddle}
};

let update (dt: float) (model: Model.t) :Model.t => {
  let model = updatePaddleDirection model;
  let ball = model.ball |> Ball.update dt model.canvasSize |> checkBallCollision model.paddle;
  let paddle = Paddle.update dt model.canvasSize model.paddle;
  {...model, ball, paddle}
};

let draw (ctx: Canvas.context) (model: Model.t) => {
  let rect: Rect.t = {position: {x: 0., y: 0.}, size: {x: model.canvasSize, y: model.canvasSize}};
  Canvas.clear ctx rect;
  Ball.draw ctx model.ball;
  Paddle.draw ctx model.paddle
};

let start (ctx: Canvas.context) (m: Model.t) :unit => {
  let lastFrameTime = ref (Utils.now ());
  let model = ref m;
  let keyDownHandler event => {
    let input = Input.keyDown (!model).input event;
    model := {...!model, input}
  };
  let keyUpHandler event => {
    let input = Input.keyUp (!model).input event;
    model := {...!model, input}
  };
  let rec loop () => {
    let now = Utils.now ();
    let elapsed = Utils.getDelta !lastFrameTime now;
    let dt = elapsed > 50. ? 50. : elapsed;
    model := update dt !model;
    draw ctx !model;
    lastFrameTime := now;
    Document.requestAnimationFrame loop
  };
  let () = Document.addEventListener "keydown" keyDownHandler;
  let () = Document.addEventListener "keyup" keyUpHandler;
  loop ()
};
