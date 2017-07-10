type position = {
  x: float,
  y: float
};

type direction = {
  x: float,
  y: float
};

type ball = {
  position,
  direction,
  radius: float,
  speed: float
};

type t = {
  ball,
  canvasSize: float
};
