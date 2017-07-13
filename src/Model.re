type t = {
  ball: Ball.t,
  paddle: Paddle.t,
  canvasSize: float,
  input: Input.t
};

let make () :t => {
  ball: {position: {x: 10., y: 10.}, direction: {x: 0.8, y: 0.5}, radius: 10., speed: 500.},
  paddle: {
    position: {x: 250., y: 450.},
    direction: {x: 0., y: 0.},
    size: {x: 100., y: 20.},
    speed: 500.
  },
  input: Input.make (),
  canvasSize: 500.
};
