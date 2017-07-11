type t = {
  position: Vec.t,
  direction: Vec.t,
  radius: float,
  speed: float
};

let draw (ctx: Canvas.context) (ball: t) => {
  Canvas.fillStyle ctx "rgba(0, 0, 0, 1)";
  Canvas.beginPath ctx;
  Canvas.arc ctx ball.position.x ball.position.y ball.radius 0. (2. *. Utils.mathPI) false;
  Canvas.fill ctx
};
