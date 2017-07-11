let update (dt: float) (model: Model.t) :Model.t => {
  let ball = Ball.update dt model.ball model.canvasSize;
  {...model, ball}
};

let draw (ctx: Canvas.context) (model: Model.t) => {
  let rect: Rect.t = {position: {x: 0., y: 0.}, size: {x: model.canvasSize, y: model.canvasSize}};
  Canvas.clear ctx rect;
  Ball.draw ctx model.ball
};

let start (ctx: Canvas.context) (m: Model.t) :unit => {
  let lastFrameTime = ref (Utils.now ());
  let model = ref m;
  let rec loop () => {
    let now = Utils.now ();
    let elapsed = Utils.getDelta !lastFrameTime now;
    let dt = elapsed > 50. ? 50. : elapsed;
    model := update dt !model;
    draw ctx !model;
    lastFrameTime := now;
    Document.requestAnimationFrame loop
  };
  loop ()
};
