type context;

external getContext : Dom.element => string => context = "getContext" [@@bs.send];

external fillRect : context => float => float => float => float => unit = "fillRect" [@@bs.send];

external clearRect : context => float => float => float => float => unit = "clearRect" [@@bs.send];

external strokeRect : context => float => float => float => float => unit =
  "strokeRect" [@@bs.send];

external beginPath : context => unit = "beginPath" [@@bs.send];

external closePath : context => unit = "closePath" [@@bs.send];

external fill : context => unit = "fill" [@@bs.send];

external fillStyle : context => string => unit = "fillStyle" [@@bs.set];

external moveTo : context => float => float => unit = "moveTo" [@@bs.send];

external lineTo : context => float => float => unit = "lineTo" [@@bs.send];

external arc : context => float => float => float => float => float => bool => unit =
  "arc" [@@bs.send];

external stroke : context => unit = "stroke" [@@bs.send];

let drawBall (ctx: context) (ball: Model.ball) => {
  fillStyle ctx "rgba(0, 0, 0, 1)";
  beginPath ctx;
  arc ctx ball.position.x ball.position.y ball.radius 0. (2. *. Utils.mathPI) false;
  fill ctx
};

let clear (ctx: context) (model: Model.t) :unit =>
  clearRect ctx 0. 0. model.canvasSize model.canvasSize;

let draw (ctx: context) (model: Model.t) => {
  clear ctx model;
  drawBall ctx model.ball
};
