type t = {
  position: Vec.t,
  direction: Vec.t,
  size: Vec.t,
  speed: float
};

let rect (paddle: t) :Rect.t => {position: paddle.position, size: paddle.size};

let draw (ctx: Canvas.context) (paddle: t) => {
  Canvas.fillStyle ctx "rgba(0, 0, 0, 1)";
  Canvas.fillRect
    ctx
    (paddle.position.x -. paddle.size.x /. 2.)
    (paddle.position.y -. paddle.size.y /. 2.)
    paddle.size.x
    paddle.size.y;
  Canvas.fill ctx
};

let update dt canvasSize (paddle: t) => {
  let x =
    switch (paddle.position.x +. paddle.speed *. paddle.direction.x *. dt /. 1000.) {
    | x when x +. paddle.size.x /. 2. > canvasSize => canvasSize -. paddle.size.x /. 2.
    | x when x -. paddle.size.x /. 2. < 0. => paddle.size.x /. 2.
    | x => x
    };
  {...paddle, position: {...paddle.position, x}}
};
